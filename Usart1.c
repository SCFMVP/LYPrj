/**
* Author: Later
* Time: 2020/5/1 18:54
* Info: LCD1602Driver
* Change:
**/
#include "Usart1.h"
/*
************************************************************
*	函数名称：	InitUART1
*
*	函数功能：	初始化串口1
*
*	入口参数：	无
*
*	返回参数：	无
*
*	说明：		 
************************************************************
*/  
void InitUART1()
{
	TMOD = 0x20;
    SCON = 0x50;
    TH1 = 0xFA;   //9600
    TL1 = TH1;
    PCON = 0x80;
    TR1 = 1;
}
/*发送一个字节*/
void SendOneByte(uchar c)
{
    SBUF = c;
    while(!TI);
    TI = 0;
}
/*发送一个字符串*/
void send_string(uchar *p)
{
	while(*p!= '\0')
	{
		SendOneByte(*p);
		p++;
	}
}