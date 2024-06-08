#include "Motor.h"

// 向前(FORWARD)

void Motor_FORWARD(void)
{
    PWM_PIN = (LEFT_WHEEL_FORWARD_Pin & RIGHT_WHEEL_FORWARD_Pin);
}

// 向后(BACKWARD)
void Motor_BACKWARD(void)
{
    PWM_PIN = (LEFT_WHEEL_BACKWARD_Pin & RIGHT_WHEEL_BACKWARD_Pin);
}

// 右转(RIGHT)
void Motor_RIGHT(void)
{
    PWM_PIN = RIGHT_WHEEL_FORWARD_Pin;
}

// 右原地转(RIGHT)
void Motor_RIGHT_Pirouette(void)
{
    PWM_PIN = (RIGHT_WHEEL_FORWARD_Pin & LEFT_WHEEL_BACKWARD_Pin);
}

// 左转(LEFT)
void Motor_LEFT(void)
{
    PWM_PIN = LEFT_WHEEL_FORWARD_Pin;
}

// 左原地转(LEFT)
void Motor_LEFT_Pirouette(void)
{
    PWM_PIN = (LEFT_WHEEL_FORWARD_Pin & RIGHT_WHEEL_BACKWARD_Pin);
}

void Motor_Stop(void)
{
    PWM_PIN = 0xff;
}
