#ifndef __MOTOR_H
#define __MOTOR_H

#include <reg51.h>

// ��ǰ(FORWARD)�����(BACKWARD)������(RIGHT)������(LEFT)

#define LEFT_WHEEL_FORWARD_Pin 0xFE  // ����ǰ����������
#define LEFT_WHEEL_BACKWARD_Pin 0xFD // ���ֺ��˿�������

#define RIGHT_WHEEL_FORWARD_Pin 0xFB  // ����ǰ����������
#define RIGHT_WHEEL_BACKWARD_Pin 0xF7 // ���ֺ��˿�������

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
