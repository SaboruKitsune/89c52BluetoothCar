#ifndef __MOTOR_H
#define __MOTOR_H

#include <reg51.h>

// 向前(FORWARD)、向后(BACKWARD)、向右(RIGHT)、向左(LEFT)

#define LEFT_WHEEL_FORWARD_Pin 0xFE  // 左轮前进控制引脚
#define LEFT_WHEEL_BACKWARD_Pin 0xFD // 左轮后退控制引脚

#define RIGHT_WHEEL_FORWARD_Pin 0xFB  // 右轮前进控制引脚
#define RIGHT_WHEEL_BACKWARD_Pin 0xF7 // 右轮后退控制引脚

#define FORWARD 'a'
#define BACKWARD 'b'
#define RIGHT 'c'
#define LEFT 'd'
#define Stop 'e'
#define Seepd_UP 'f'
#define Seepd_DN 'g'

extern unsigned char PWM_PIN;

void Motor_FORWARD(void);
void Motor_BACKWARD(void);
void Motor_RIGHT(void);
void Motor_RIGHT_Pirouette(void);
void Motor_LEFT(void);
void Motor_LEFT_Pirouette(void);
void Motor_Stop(void);

#endif
