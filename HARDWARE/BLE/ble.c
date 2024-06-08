#include "ble.h"

void UartInit(void) // 9600bps@11.0592MHz
{
	PCON &= 0x7F; // 波特率不倍速
	SCON = 0x50;  // 8位数据,可变波特率
	TMOD &= 0x0F; // 清除定时器1模式位
	TMOD |= 0x20; // 设定定时器1为8位自动重装方式
	TL1 = 0xFD;	  // 设定定时初值
	TH1 = 0xFD;	  // 设定定时器重装值
	ET1 = 0;	  // 禁止定时器1中断
	TR1 = 1;	  // 启动定时器1

	ES = 1; // 开启串口中断
	EA = 1; // 开启总中断
}

void sendByte(char byte)
{
	SBUF = byte;
	while (TI == 0)
		;
	TI = 0;
}

// void sendString(char *string)
//{
//	char *temp = string;
//
//	while ( *temp )
//	{
//		sendByte( *temp );
//		temp++;
//	}
// }

void uartISR() interrupt 4
{
	// 收到了一帧数据
	if (RI == 1)
	{
		// 数据保存在sbuf中
		UartData = SBUF;

		// 写回给蓝牙
		sendByte(UartData);

		RI = 0;
		Flag = 2;
	}
}
