#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <unistd.h>
#include "math.h"
#include <string.h>
// car control
#include "car_motion.h"
#include "motor.h"
#include "battery.h"
#include "icm42670p.h"
#include "beep.h"
#include "ros2.h"
#include "PID_IMU.h"
// 声明变量
float v_L, v_R;
static const char *TAG = "MAIN";
/** 
 * @param beginspeed 初始速度（m/s）
 * @param endspeed  结束速度（m/s）
 * @param a 加速度（m/s^2）
 */
void accelerate(float beginspeed,float endspeed,float a){
    a=a/100;
    float speed=beginspeed;
    if(speed==0){
        speed=0.05;//当初始速度为0时，直接给予初速度迅速启动
    }
    float speed_m1, speed_m2, speed_m3, speed_m4;
    float voltage = Battery_Get_Voltage();
    float accel_g[3] = {0};
    float gyro_dps[3] = {0};
    while(speed<endspeed){
        speed+=a;
        Motor_Set_Speed(speed,speed,speed,speed);
        Icm42670p_Get_Accel_g(accel_g);
        Icm42670p_Get_Gyro_dps(gyro_dps);
        Motor_Get_Speed(&speed_m1, &speed_m2, &speed_m3, &speed_m4);
        voltage = Battery_Get_Voltage();
        ESP_LOGI(TAG,"setspeed %.3f V1:%.3f V2:%.3f V3:%.3f V4:%.3f voltage:%.2f Accel_g:%f, %f, %f",speed,speed_m1,speed_m2,speed_m3,speed_m4,voltage,accel_g[0], accel_g[1], accel_g[2]);
        vTaskDelay(pdMS_TO_TICKS(10));
    }
    Motor_Stop(STOP_COAST);
}

void app_main(void)
{
    // 调试信息？
    printf("hello yahboom\n");
    ESP_LOGI(TAG, "Nice to meet you!");
    

    // 初始化小车
    Motor_Init();
    Battery_Init();
    Icm42670p_Init();
    Beep_Init();
    vTaskDelay(pdMS_TO_TICKS(1000));



// 初始化网络，连接WiFi信号
    ESP_ERROR_CHECK(uros_network_interface_initialize());

    odom_ros_init();

    //开启microROS任务
    xTaskCreate(micro_ros_task,
                "micro_ros_task",
                CONFIG_MICRO_ROS_APP_STACK,
                NULL,
                CONFIG_MICRO_ROS_APP_TASK_PRIO,
                NULL);

    float LineSpeed = 0.6f;
    float L1 = 2.5f;
    float L2 = 0.5f;
    float L3 = 0.5f;
    float L4 = 0.5f;
    float L5 = 0.5f;
    float R1 = 0.5f;
    float R1a=150;
    float R2 = 0.5f;
    float R2a=90;
    float R3 = 0.5f;
    float R3a=60;
    float R4 = 0.85f;
    float R4a=63.97;
    float R5 = 0.5f;
    float R5a=153.97;
    float R6 = 0.5f;
    float R6a=90;

    PidContrl(0,LineSpeed,0,L1/LineSpeed+0.13);

    PidContrl(1,
        LineSpeed,
        R1a/((2*Pi*R1*R1a/360)/LineSpeed)+6,
        (2*Pi*R1*R1a/360)/LineSpeed+0.15
    );

    PidContrl(0,LineSpeed,0,L2/LineSpeed+0.03);

    PidContrl(1,
        LineSpeed,
        R2a/((2*Pi*R2*R2a/360)/LineSpeed)+9,
        (2*Pi*R2*R2a/360)/LineSpeed+0.06
    );

    PidContrl(0,
        LineSpeed,
        R3a/((2*Pi*R3*R3a/360)/LineSpeed)+5,
        (2*Pi*R3*R3a/360)/LineSpeed-0.07
    );

    PidContrl(0,LineSpeed,0,L3/LineSpeed);

    PidContrl(0,
        LineSpeed,
        R4a/((2*Pi*R4*R4a/360)/LineSpeed)+9,
        (2*Pi*R4*R4a/360)/LineSpeed+0.03
    );

    PidContrl(1,
        LineSpeed,
        R5a/((2*Pi*R5*R5a/360)/LineSpeed)+4,
        (2*Pi*R5*R5a/360)/LineSpeed-0.03
    );

    PidContrl(0,LineSpeed,0,L4/LineSpeed);

    PidContrl(0,
        LineSpeed,
        R6a/((2*Pi*R6*R6a/360)/LineSpeed)+2,
        (2*Pi*R6*R6a/360)/LineSpeed
    );

    PidContrl(0,LineSpeed,0,L5/LineSpeed);
   if(0){
    float speed_m1, speed_m2, speed_m3, speed_m4;
    float voltage = Battery_Get_Voltage();
    float accel_g[3] = {0};
    float gyro_dps[3] = {0};
        while (1)
        {   
            voltage = Battery_Get_Voltage();
            Motor_Get_Speed(&speed_m1, &speed_m2, &speed_m3, &speed_m4);
            Icm42670p_Get_Accel_g(accel_g);
            Icm42670p_Get_Gyro_dps(gyro_dps);
            ESP_LOGI(TAG,"\nV1:%.3f V2:%.3f V3:%.3f V4:%.3f \nomegaX:%.3f omegaY:%.3f omegaZ:%.3f \nGx:%.3f Gy:%.3f Gz:%.3f \nvoltage:%.2f\n\n\n"
                ,speed_m1,speed_m2,speed_m3,speed_m4,gyro_dps[0],gyro_dps[1],gyro_dps[2],accel_g[0],accel_g[1],accel_g[2], voltage);
            vTaskDelay(pdMS_TO_TICKS(100));
        }
        // 结束运行
        Motor_Stop(STOP_BRAKE);
    }
}
