#ifndef __BLE_H
#define __BLE_H

#include <reg51.h>

extern unsigned char UartData;
extern unsigned int Flag;

void UartInit(void);
void sendByte(char byte);
void sendString(char *string);

#endif
