/**
* Author: Later
* Time: 2020/5/1 18:54
* Info: ADC0809Driver
* Change:
**/

#ifndef __USART1_H__	  //����ADC0809_HH�ļ������ڴ�Ŷ�ʱ�ж���غ�������
#define __USART1_H__		


//---����ͷ�ļ�---//
#include <reg52.h>
#include <intrins.h>

//---�ض���ؼ���---//
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

