/**
* Author: Later
* Time: 2020/5/1 18:54
* Info: ADC0809Driver
* Change:
**/

#ifndef __ADC0809_H__	  //定义ADC0809_HH文件，用于存放定时中断相关函数声明
#define __ADC0809_H__		

#include "reg52.h"

//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

//宏定义
#define adc0809_data P1

//ADC0809 控制引脚定义
sbit ST=P3^4;  
sbit EOC=P3^5;
sbit OE=P3^6;

sbit CLK =P3^7;

extern uchar AD_DATA[1]; 
extern uchar light[3];

extern void ADC0809();	   //函数声明
extern void Read_Light();
void startT0();



#endif

