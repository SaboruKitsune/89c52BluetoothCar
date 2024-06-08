#include <reg51.h>
#include "Motor.h"
#include "ble.h"
#include "PWM.h"

sbit LED7 = P1 ^ 6;

#define uint unsigned int
#define uchar unsigned char

#define Speed_UP 1
#define Speed_DN 0

uchar UartData;
uchar PWM_PIN = 0xFF;
uchar time = 0; // 定义占空比的变量
uint Flag = 0;
uint duty_cycle = 35; // 占空比,越大越快
uint timeCnt = 0;
uint PWMTimCnt = 0;
uint PWM_LED = 0;

void delay_ms(uint z)
{
	uint i, j;
	for (i = z; i > 0; i--)
		for (j = 110; j > 0; j--)
			;
}

int main()
{
	UartInit();
	Timers_Init();
	while (1)
	{
		if (UartData == FORWARD)
		{
			Motor_FORWARD();
		}
		if (UartData == BACKWARD)
		{
			Motor_BACKWARD();
		}
		if (UartData == RIGHT)
		{
			Motor_RIGHT();
		}
		if (UartData == LEFT)
		{
			Motor_LEFT();
		}
		if (UartData == Stop)
		{
			Motor_Stop();
		}
		if (UartData == Seepd_UP)
		{
			PWM_Seepd_control(Speed_UP);
		}
		if (UartData == Seepd_DN)
		{
			PWM_Seepd_control(Speed_DN);
		}
	}
}
