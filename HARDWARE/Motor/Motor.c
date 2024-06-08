#include "Motor.h"

// ��ǰ(FORWARD)

void Motor_FORWARD(void)
{
    PWM_PIN = (LEFT_WHEEL_FORWARD_Pin & RIGHT_WHEEL_FORWARD_Pin);
}

// ���(BACKWARD)
void Motor_BACKWARD(void)
{
    PWM_PIN = (LEFT_WHEEL_BACKWARD_Pin & RIGHT_WHEEL_BACKWARD_Pin);
}

// ��ת(RIGHT)
void Motor_RIGHT(void)
{
    PWM_PIN = RIGHT_WHEEL_FORWARD_Pin;
}

// ��ԭ��ת(RIGHT)
void Motor_RIGHT_Pirouette(void)
{
    PWM_PIN = (RIGHT_WHEEL_FORWARD_Pin & LEFT_WHEEL_BACKWARD_Pin);
}

// ��ת(LEFT)
void Motor_LEFT(void)
{
    PWM_PIN = LEFT_WHEEL_FORWARD_Pin;
}

// ��ԭ��ת(LEFT)
void Motor_LEFT_Pirouette(void)
{
    PWM_PIN = (LEFT_WHEEL_FORWARD_Pin & RIGHT_WHEEL_BACKWARD_Pin);
}

void Motor_Stop(void)
{
    PWM_PIN = 0xff;
}
