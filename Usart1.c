/**
* Author: Later
* Time: 2020/5/1 18:54
* Info: LCD1602Driver
* Change:
**/
#include "Usart1.h"

void InitUART1()
{
	TMOD = 0x20;
    SCON = 0x50;
    TH1 = 0xFA;   //9600
    TL1 = TH1;
    PCON = 0x80;
    TR1 = 1;
}
/*����һ���ֽ�*/
void SendOneByte(uchar c)
{
    SBUF = c;
    while(!TI);
    TI = 0;
}
/*����һ���ַ���*/
void send_string(uchar *p)
{
	while(*p!= '\0')
	{
		SendOneByte(*p);
		p++;
	}
}