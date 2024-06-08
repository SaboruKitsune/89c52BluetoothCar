#include "ble.h"

void UartInit(void) // 9600bps@11.0592MHz
{
	PCON &= 0x7F; // �����ʲ�����
	SCON = 0x50;  // 8λ����,�ɱ䲨����
	TMOD &= 0x0F; // �����ʱ��1ģʽλ
	TMOD |= 0x20; // �趨��ʱ��1Ϊ8λ�Զ���װ��ʽ
	TL1 = 0xFD;	  // �趨��ʱ��ֵ
	TH1 = 0xFD;	  // �趨��ʱ����װֵ
	ET1 = 0;	  // ��ֹ��ʱ��1�ж�
	TR1 = 1;	  // ������ʱ��1

	ES = 1; // ���������ж�
	EA = 1; // �������ж�
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
	// �յ���һ֡����
	if (RI == 1)
	{
		// ���ݱ�����sbuf��
		UartData = SBUF;

		// д�ظ�����
		sendByte(UartData);

		RI = 0;
		Flag = 2;
	}
}
