/**
* Author: Later
* Time: 2020/5/1 18:54
* Info: ADC0809Driver
* Change:
**/

#ifndef __USART1_H__	  //定义ADC0809_HH文件，用于存放定时中断相关函数声明
#define __USART1_H__		


//---包含头文件---//
#include <reg52.h>
#include <intrins.h>

//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

	
void InitUART1();
void SendOneByte(uchar c);
void send_string(uchar *p);

#endif

