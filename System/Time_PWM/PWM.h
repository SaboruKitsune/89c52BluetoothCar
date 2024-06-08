#ifndef __PWM_H
#define __PWM_H

#include <reg51.h>
#include "Motor.h"

sbit LED8 = P1 ^ 7;

#define time_max 50
#define time_min 20

extern unsigned char UartData;
extern unsigned char PWM_PIN;
extern unsigned char time; // 定义占空比的变量
extern unsigned int duty_cycle;
extern unsigned int Flag;
extern unsigned int timeCnt;
extern unsigned int PWMTimCnt;
// PWM 变化的范围 0-100 每200ms 加10 
extern unsigned int PWM_LED;

void Timers_Init();
void PWM_Seepd_control(int numerical);

#endif