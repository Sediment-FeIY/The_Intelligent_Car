#pragma once
#include "esp_system.h"
#include "esp_timer.h"
#include "esp_log.h"
static const char *PID_TAG = "PID";
// 声明参数（单位：m）
#define MAX_SPEED 1.4f //最大速度
#define W  0.147 //左右轮距
#define L  0.112 //前后轮距
#define Pi  3.1415926535f

static float gyro_zero_offset_z = 0.0f;
static void calibrate_gyro_zero_offset(void) {
    float sum = 0.0f;
    int samples = 100;
    
    for (int i = 0; i < samples; i++) {
        float gyro_dps[3] = {0};
        Icm42670p_Get_Gyro_dps(gyro_dps);
        sum += gyro_dps[2] * 180.0f / Pi;
        vTaskDelay(pdMS_TO_TICKS(10));
    }
    gyro_zero_offset_z = sum / samples;
    ESP_LOGI(PID_TAG, "Gyro Z zero offset: %.3f°/s", gyro_zero_offset_z);
}

static float get_current_angular_speed(void) {
    float gyro_dps[3] = {0};
    Icm42670p_Get_Gyro_dps(gyro_dps);
    // 减去零点偏移
    return gyro_dps[2] * 180.0f / Pi - gyro_zero_offset_z;
}


// PID控制器结构体（优化版本）
typedef struct {
    float target;       // 目标值
    float error;        // 误差
    float prev_error;   // 上一次误差
    float integral;     // 积分项
    float derivative;   // 微分项
    float kp, ki, kd;   // PID系数
    float integral_limit; // 积分限幅
    float output_limit;  // 输出限幅
    float deadband;     // 死区阈值
    float deriv_filter; // 微分滤波系数
    float prev_deriv;   // 微分滤波历史值
} PID_Controller;

// 全局PID控制器实例
static PID_Controller pid_speed = {0};
static PID_Controller pid_angular = {0};

// PID初始化
static void pid_init(PID_Controller *pid, float kp, float ki, float kd, 
                    float integral_limit, float output_limit, float deadband, float deriv_filter) {
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
    pid->integral_limit = integral_limit;
    pid->output_limit = output_limit;
    pid->deadband = deadband;
    pid->deriv_filter = deriv_filter;
    
    pid->target = 0.0f;
    pid->error = 0.0f;
    pid->prev_error = 0.0f;
    pid->integral = 0.0f;
    pid->derivative = 0.0f;
    pid->prev_deriv = 0.0f;
}

// PID计算（优化稳定性）
static float mypid_compute(PID_Controller *pid, float current_value, float dt) {
    pid->error = pid->target - current_value;
    
    // 死区处理
    if (fabsf(pid->error) < pid->deadband) {
        pid->error = 0.0f;
        pid->integral *= 0.95f; // 积分衰减
    }
    
    // 比例项
    float p_term = pid->kp * pid->error;
    
    // 积分项（改进的积分分离）
    float i_term = 0.0f;
    
    // 允许在小误差时进行积分，不只是在大误差时
    if (fabsf(pid->error) < pid->integral_limit * 2.0f) { // 放宽积分条件
        pid->integral += pid->error * dt;
        
        // 积分限幅（更柔和的限幅）
        float max_integral = pid->integral_limit / pid->ki;
        if (max_integral > 0) {
            if (pid->integral > max_integral) pid->integral = max_integral;
            if (pid->integral < -max_integral) pid->integral = -max_integral;
        }
        
        i_term = pid->ki * pid->integral;
    } else {
        // 误差过大时重置积分，防止积分饱和
        pid->integral *= 0.5f;
    }
    
    // 微分项（增加低通滤波）
    float deriv = (pid->error - pid->prev_error) / dt;
    pid->derivative = pid->deriv_filter * pid->prev_deriv + (1 - pid->deriv_filter) * deriv;
    
    // 微分项限幅，防止微分冲击
    float max_derivative = pid->output_limit / pid->kd * 0.1f;
    if (pid->derivative > max_derivative) pid->derivative = max_derivative;
    if (pid->derivative < -max_derivative) pid->derivative = -max_derivative;
    
    float d_term = pid->kd * pid->derivative;
    pid->prev_deriv = pid->derivative;
    
    // 计算输出
    float output = p_term + i_term + d_term;
    
    // 输出限幅
    if (output > pid->output_limit) output = pid->output_limit;
    if (output < -pid->output_limit) output = -pid->output_limit;
    
    pid->prev_error = pid->error;
    return output;
}

/**
 * 基于差速模型计算四轮目标速度
 * @param TurnDirection 转向方向，0左转，1右转
 * @param linear_speed  目标线速度（m/s）
 * @param angular_speed_deg 目标角速度（°/s）
 * @param v_L    输出左轮线速度（m/s）
 * @param v_R    输出右轮线速度（m/s）
 */
static void calc_wheel_speeds(int turn_direction, float linear_speed, float angular_speed_deg, 
                             float *v_L, float *v_R) {
    // 将角速度从°/s转换为rad/s
    float angular_rad = angular_speed_deg * Pi / 180.0f;
    
    // 差速计算（阿克曼转向模型）
    float turn_radius_factor = angular_rad * (W + L) / 2.0f;
    
    if (turn_direction == 0) { // 左转
        *v_L = linear_speed - turn_radius_factor;  // 左轮慢
        *v_R = linear_speed + turn_radius_factor;  // 右轮快
    } else { // 右转
        *v_L = linear_speed + turn_radius_factor;  // 左轮快  
        *v_R = linear_speed - turn_radius_factor;  // 右轮慢
    }
    
    // 原地旋转特殊情况处理
    if (fabsf(linear_speed) < 0.01f && fabsf(angular_speed_deg) > 1.0f) {
        float base_speed = angular_rad * (W + L) / 2.0f;
        if (turn_direction == 0) { // 左转
            *v_L = -base_speed;
            *v_R = base_speed;
        } else { // 右转
            *v_L = base_speed;
            *v_R = -base_speed;
        }
    }
    
    // 速度限幅
    *v_L = (*v_L > MAX_SPEED) ? MAX_SPEED : ((*v_L < -MAX_SPEED) ? -MAX_SPEED : *v_L);
    *v_R = (*v_R > MAX_SPEED) ? MAX_SPEED : ((*v_R < -MAX_SPEED) ? -MAX_SPEED : *v_R);
}

/**
 * 获取平均线速度（四轮速度平均）
 */
static float get_avg_speed(float speed_m1, float speed_m2, float speed_m3, float speed_m4) {
    // 电机1(左上), 电机2(左下) - 左轮
    // 电机3(右上), 电机4(右下) - 右轮
    float left_avg = (speed_m1 + speed_m2) / 2.0f;
    float right_avg = (speed_m3 + speed_m4) / 2.0f;
    return (left_avg + right_avg) / 2.0f;
}


/**
 * 小车运动控制主函数
 * @param TurnDirection 转向方向，0左转，1右转
 * @param target_linear 目标线速度（m/s）
 * @param target_angular 目标角速度（°/s）
 * @param run_time 运行时间（秒）
 */
void PidContrl(int TurnDirection, float target_linear, float target_angular, float run_time) {
    // 校准陀螺仪零点
    static bool gyro_calibrated = false;
    if (!gyro_calibrated) {
        calibrate_gyro_zero_offset();
        gyro_calibrated = true;
    }
    ESP_LOGI(PID_TAG, "PID Control Start: linear=%.2fm/s, angular=%.2f°/s, time=%.1fs, dir=%s", 
             target_linear, target_angular, run_time, TurnDirection == 0 ? "LEFT" : "RIGHT");
    
             target_angular = 720-12*sqrt(10)*sqrt(360-target_angular);
    // 初始化PID参数
    // 线速度PID：增大积分限幅，减小微分滤波系数
    pid_init(&pid_speed, 2.2f, 7.0f, 0.02f, 30.0f, MAX_SPEED, 0.005f, 0.8f);
    // 角速度PID：减小死区，调整积分系数
    pid_init(&pid_angular, 2.2f, 7.0f, 0.05f, 50.0f, 180.0f, 0.2f, 0.9f);
    
    pid_speed.target = target_linear;
    pid_angular.target = target_angular;
    
    float speed_m1, speed_m2, speed_m3, speed_m4;
    float avg_speed, angular_current;
    float v_L, v_R;
    float pid_speed_out, pid_angular_out;
    const float dt = 0.01f; // 10ms控制周期
    
    TickType_t start_time = xTaskGetTickCount();
    TickType_t run_ticks = pdMS_TO_TICKS(run_time * 1000);
    
    while ((xTaskGetTickCount() - start_time) < run_ticks) {
        // 获取当前状态
        Motor_Get_Speed(&speed_m1, &speed_m2, &speed_m3, &speed_m4);
        avg_speed = get_avg_speed(speed_m1, speed_m2, speed_m3, speed_m4);
        angular_current = get_current_angular_speed();
        
        // PID调节
        pid_speed_out = mypid_compute(&pid_speed, avg_speed, dt);
        pid_angular_out = mypid_compute(&pid_angular, angular_current, dt);
        
        // 计算四轮目标速度
        calc_wheel_speeds(TurnDirection, pid_speed_out, pid_angular_out, &v_L, &v_R);
        
        // 设置电机速度（左轮：电机1,2；右轮：电机3,4）
        Motor_Set_Speed(v_L, v_L, v_R, v_R);
        
        // 调试日志
        ESP_LOGI(PID_TAG, 
            "Target:%.2fm/s(%.1f°/s) | Current:%.2fm/s(%.1f°/s) | Wheels:%.2f/%.2fm/s",
            target_linear, target_angular, avg_speed, angular_current, v_L, v_R);
        
        vTaskDelay(pdMS_TO_TICKS(10)); // 10ms周期
    }
    
    // 停止电机（滑行停止）
    Motor_Stop(false);
    ESP_LOGI(PID_TAG, "PID control finished, motor stopped.");
}

// PID参数更新函数（用于调试和优化）
void PidContrl_Update_Params(float speed_kp, float speed_ki, float speed_kd,
                            float angular_kp, float angular_ki, float angular_kd) {
    pid_speed.kp = speed_kp;
    pid_speed.ki = speed_ki; 
    pid_speed.kd = speed_kd;
    pid_angular.kp = angular_kp;
    pid_angular.ki = angular_ki;
    pid_angular.kd = angular_kd;
    
    ESP_LOGI(PID_TAG, "PID params updated: Speed[%.3f,%.3f,%.3f] Angular[%.3f,%.3f,%.3f]",
             speed_kp, speed_ki, speed_kd, angular_kp, angular_ki, angular_kd);
}