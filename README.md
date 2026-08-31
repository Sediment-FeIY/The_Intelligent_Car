# The Intelligent Car —— ROS2 麦克纳姆轮小车（ESP32-S3 + micro-ROS）

> 对应课程：进阶式挑战性综合项目 III ｜ 具身智能系统集成与审计（Physical AI）
> 第 1 课《具身智能导论、系统架构与上位机接入》配套本体工程

---

## 一、项目是什么

这是一个运行在 **ESP32-S3** 上的 **ROS2（micro-ROS）麦克纳姆轮智能小车固件工程**，基于 **ESP-IDF** 构建。

- **硬件主控**：ESP32-S3（4MB Flash）
- **底盘**：四轮麦克纳姆轮小车，四个直流电机 + 四路霍尔编码器闭环
- **传感**：ICM-42670-P 六轴 IMU（加速度计 + 陀螺仪）、电池电压检测、蜂鸣器
- **通信**：WiFi → micro-ROS over UDP 连接上位机 ROS2 Agent
- **上层控制**：浏览器网页远程控制（roslib.js）

一句话：**这是一台能通过 ROS2 话题被远程遥控、并上报里程计/IMU/电量/轮速状态的麦克纳姆轮小车固件。**

---

## 二、目录结构

```
demo/
├── main/                  # 主程序
│   ├── main.c             # app_main：初始化 → 连WiFi → micro-ROS任务 → 预定路线
│   ├── CMakeLists.txt
│   ├── Kconfig.projbuild  # micro-ROS 相关 menuconfig 项
│   └── mymsg/             # 自定义 ROS2 消息生成代码（micro-ROS）
├── components/            # 自研组件
│   ├── car_motion/        # 麦克纳姆轮底盘运动学（Vx/Vy/Wz → 四轮速度）
│   ├── motor/             # 电机速度闭环（PID 封装，10ms 周期）
│   ├── pwm_motor/         # 电机 PWM 驱动（25kHz）
│   ├── encoder/           # 四路霍尔编码器（PCNT 计数）
│   ├── battery/           # 电池电压检测
│   ├── beep/              # 蜂鸣器
│   ├── i2c_master/        # I2C 主机驱动
│   ├── icm42670p/         # ICM-42670-P IMU 驱动
│   ├── inv_imu/           # InvenSense IMU 驱动库
│   ├── PID_IMU/           # PID 控制器（含 IMU 角速度反馈，轨迹控制）
│   └── ROS2/              # micro-ROS 通信层（发布/订阅/定时器）
├── managed_components/    # ESP-IDF 托管组件（乐鑫 bdc_motor / pid_ctrl）
├── 远程控制.html          # 浏览器远程控制界面
├── roslib.js              # ROS WebSocket（rosbridge）客户端库
├── CMakeLists.txt         # 工程根构建文件
├── sdkconfig              # 当前编译配置（WiFi / Agent IP 等）
└── build/                 # 编译产物（已成功构建 main.bin）
```

---

## 三、ROS2 通信架构（话题清单）

| 方向 | 话题 | 消息类型 | 说明 |
|---|---|---|---|
| MCU 订阅 | `cmd_vel` | geometry_msgs/Twist | 上位机下发的速度指令（linear.x / angular.z） |
| MCU 发布 | `odom_raw` | nav_msgs/Odometry | 运动学里程计（编码器推算），frame: odom_frame → base_footprint |
| MCU 发布 | `car_status` | std_msgs/Float32MultiArray | 8 个浮点：电池电压、四轮速度 ×4、三轴加速度 ×3 |

**通信方式**：ESP32 通过 WiFi 以 **UDP** 方式连接 micro-ROS Agent（`ROS_AGENT_IP:ROS_AGENT_PORT`，见 sdkconfig），domain ID 见 Kconfig。

**micro-ROS 任务流程**（`components/ROS2/ros2.h`）：
1. 循环尝试连接 Agent（失败每 500ms 重试）
2. 建节点 `odom_publisher`，注册 `/cmd_vel` 订阅、`/odom_raw` 与 `/car_status` 发布
3. 定时器 100ms（10Hz）发布里程计与状态数据
4. 收到 `cmd_vel` → `Motion_Ctrl(linear.x, 0, angular.z)` 驱动底盘

---

## 四、main.c 启动逻辑

`main.c` 的 `app_main` 依次执行：

1. **硬件初始化**：电机、电池、IMU、蜂鸣器（约 1s）
2. **连接 WiFi**：`uros_network_interface_initialize()`（阻塞，直到连上）
3. **创建 micro-ROS 后台任务**：独立 FreeRTOS 任务，负责连 Agent、收发话题
4. **立即进入预定路线**：一连串 `PidContrl(...)` 串行执行（直线 + 圆弧转弯的 PID 轨迹运动，约 20 秒，含首次陀螺仪零点校准 1s）

> ⚠️ **重要现状**：当前固件**没有预留"先遥控、后路线"的等待窗口**。创建 micro-ROS 任务后立即开始走预定路线；且在路线执行期间，`cmd_vel` 遥控与 `PidContrl` 会**并发争抢电机控制**，二者无先后协调。若需要"启动后可遥控待命，确认后再走路线"，需修改 `main.c`（如增加启动标志位）。

---

## 五、网页远程控制

- `远程控制.html` + `roslib.js`：浏览器页面，通过 **ROS WebSocket（rosbridge）** 连接 `ws://localhost:8888`
- 功能：发布 `/cmd_vel`（前进/后退/左转/右转 + 速度滑杆），订阅 `/car_status` 显示车速
- 与固件话题匹配：`/cmd_vel` 发布 ↔ 固件订阅；`/car_status` 订阅 ↔ 固件发布

> 注：该网页走 rosbridge WebSocket；课程 PPT 架构中的云控台后端为 Flask+SocketIO，实现路径不同。

---

## 六、与《第三学期第1课》PPT 的差异对照

PPT 第 1 课核心交付：《接口契约表》实测签核 + 具身系统架构框图。对照如下：

### 1. 接口契约四话题（PPT Slide 12）

| 话题 | 类型 | PPT 约定频率 | 当前工程现状 | 差距 |
|---|---|---|---|---|
| `/cmd_vel` | geometry_msgs/Twist | ≤20Hz | ✅ 已订阅并驱动底盘 | 无（频率取决于上位机） |
| `/odom` | nav_msgs/Odometry | 50Hz | ⚠️ 话题名为 `odom_raw`；发布频率 10Hz（100ms 定时器） | **话题名不符 + 频率不足（应 50Hz）** |
| `/imu` | sensor_msgs/Imu | 50Hz | ❌ 未发布标准 `/imu` 话题；IMU 数据被塞入 `/car_status` 自定义消息 | **缺失** |
| `/scan` | sensor_msgs/LaserScan | 10Hz | ❌ 固件无此话题（LD19 雷达走 USB 转串口接树莓派上位机） | 属上位机侧职责 |

### 2. 远程控制链路

| PPT 要求 | 当前工程现状 | 差距 |
|---|---|---|
| micro-ROS Agent 走 **USB 串口**（`serial --dev /dev/ttyACM0 -b 115200`） | 固件走 **WiFi UDP**（192.168.31.79:8888） | 传输方式不一致，需按课程改为串口或说明偏离 |
| teleop 遥控（树莓派 `teleop_twist_keyboard` → /cmd_vel） | 固件已支持订阅 `cmd_vel` 被遥控 | 固件侧就绪，上位机部分不在本工程 |
| 浏览器统一云控界面 | 有 `远程控制.html`（rosbridge WebSocket） | 有，但与 PPT 的 Flask+SocketIO 路径不同 |
| MCU 层：100Hz 轮速 PID + 运动学里程计 + IMU + 安全限幅 | ✅ 均具备（PID 10ms 周期、麦克纳姆轮运动学、速度限幅） | 基本满足 |
| 急停有效 / 断流冻结 | 固件有 `Motor_Stop(STOP_BRAKE)`，但**无断流自动刹车**（上位机断开会保持最后速度） | 需补超时保护 |

### 3. 上位机 / 云端内容（不在本工程）

PPT 架构中的以下部分**不在本 ESP32 固件工程内**，需在树莓派上位机 / 云端另行实现：
- 树莓派 5（Ubuntu 24.04 · ROS 2）+ micro-ROS Agent
- SLAM（slam_toolbox）/ Nav2 导航栈 / AMCL 定位
- YOLO 目标检测 + 语义地图
- 云控台后端（Flask+SocketIO）+ 规划执行器 + Plan Auditor
- 认知层 LLM 任务规划 / VLM 场景理解（OpenAI 兼容接口）
- LD19 激光雷达 `/scan` 发布（USB 转串口接树莓派）

### 4. 总结：本课验收清单完成度

- [x] 本体可启动、可连接 WiFi、micro-ROS 任务可连 Agent
- [x] `/cmd_vel` 可被遥控、底盘可受控
- [ ] `/odom` 话题名与 50Hz 频率达标（当前 `odom_raw` / 10Hz）
- [ ] `/imu` 标准话题发布（当前缺失）
- [ ] `/scan` 可见（需上位机 + 雷达）
- [ ] 契约表实测签核 / 架构框图（待动手完成）

---

## 七、构建与烧录

```bash
# 设置 ESP-IDF 环境后
idf.py set-target esp32s3
idf.py build
idf.py -p COMx flash monitor
```

> 注意：`sdkconfig` 中含 WiFi 账号、密码与 micro-ROS Agent 地址，属敏感配置；公开仓库中已用 `sdkconfig.defaults` 占位模板替代，请勿直接提交真实 `sdkconfig`。

---

## 八、安全说明

- 上传仓库前已将 `sdkconfig` 中的 **WiFi 密码 / Agent IP 脱敏**，并生成 `sdkconfig.defaults` 模板；本地烧录请在 `sdkconfig.defaults` 中填入真实值后重新 `idf.py build`。
- 本工程不含上位机（树莓派）代码，远程控制的完整闭环需要配合上位机 Agent 使用。
