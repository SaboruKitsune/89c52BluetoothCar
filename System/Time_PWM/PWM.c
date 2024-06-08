#include "PWM.h"

void Timers_Init()
{
    TMOD &= 0xF0; // 设置定时器模式
    TMOD |= 0x01; // 设置定时器模式
    TL0 = 0x66;   // 设置定时初值
    TH0 = 0xFC;   // 设置定时初值
    TF0 = 0;      // 清除TF0标志
    TR0 = 1;      // 定时器0开始计时

    ET0 = 1;
    EA = 1;
}

void PWM_Seepd_control(int numerical)
{
    if (numerical && duty_cycle < time_max)
    {
        duty_cycle += 5;
    }
    else if (duty_cycle > time_min)
    {
        duty_cycle -= 5;
    }
	UartData=0;
}

void tim0() interrupt 1
{
    TL0 = 0xAE; // 设置定时初值
    TH0 = 0xFB; // 设置定时初值

    time++;
    time %= time_max;
    if (time <= duty_cycle) // 占空比
        P1 = PWM_PIN;       // 电机转动
    else
        P1 = 0xff;

    if (Flag>0)
    {
        timeCnt++;   // 0-4000
        PWMTimCnt++; // 0-200

        PWM_LED %= 100;
        // 吸气过程
        if (timeCnt < 2000)
        {
            // 低电平的持续时间
            if (timeCnt % 20 < (PWM_LED * 20 / 100))
                LED8 = 0;
            else
                LED8 = 1;
        }
        else // 呼气过程
        {
            if (timeCnt % 20 < (PWM_LED * 20 / 100))
                LED8 = 1;
            else
                LED8 = 0;
        }
        if (PWMTimCnt == 200)
        {
            PWM_LED = PWM_LED + 10;
            PWMTimCnt = 0;
        }
        // 4s 到了
        if (timeCnt == 4000)
        {
            timeCnt = 0;
            PWMTimCnt = 0;
            PWM_LED = 0;
			Flag--;
        }
    }
}
