#include "PWM.h"

void Timers_Init()
{
    TMOD &= 0xF0; // ���ö�ʱ��ģʽ
    TMOD |= 0x01; // ���ö�ʱ��ģʽ
    TL0 = 0x66;   // ���ö�ʱ��ֵ
    TH0 = 0xFC;   // ���ö�ʱ��ֵ
    TF0 = 0;      // ���TF0��־
    TR0 = 1;      // ��ʱ��0��ʼ��ʱ

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
    TL0 = 0xAE; // ���ö�ʱ��ֵ
    TH0 = 0xFB; // ���ö�ʱ��ֵ

    time++;
    time %= time_max;
    if (time <= duty_cycle) // ռ�ձ�
        P1 = PWM_PIN;       // ���ת��
    else
        P1 = 0xff;

    if (Flag>0)
    {
        timeCnt++;   // 0-4000
        PWMTimCnt++; // 0-200

        PWM_LED %= 100;
        // ��������
        if (timeCnt < 2000)
        {
            // �͵�ƽ�ĳ���ʱ��
            if (timeCnt % 20 < (PWM_LED * 20 / 100))
                LED8 = 0;
            else
                LED8 = 1;
        }
        else // ��������
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
        // 4s ����
        if (timeCnt == 4000)
        {
            timeCnt = 0;
            PWMTimCnt = 0;
            PWM_LED = 0;
			Flag--;
        }
    }
}
