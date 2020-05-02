/**
* Author: Later
* Time: 2020/5/1 18:54
* Info: 
* Change:
**/
#include "reg52.h"
#include "Usart1.h"
#include "DHT11.h"
#include "lcd.h"
#include "ADC0809.h"

#include <intrins.h>
//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif
int Read_Light()
{
	uchar b,c;
	uint lum_mean,lum_all;		//ad0809读出值

	for( b=0;b<49;b++) 			//将空数组tt[51]内数值整体左移一位
	{
		tt[b]=tt[b+1];			//将后一数值放到前一位置
	}
	tt[49]=ADC0809();			//将读出的ad0809数值放入tt[49]
	for( c=0;c<50;c++)			//将tt[]内数值相加
	{
		lum_all=lum_all+tt[c];
	}
	return lum_mean=lum_all/50;		//将总数/50取出平均值
}
void main()
{  
	/*初始化设备*/
	InitUART1();
	LcdInit();	
	while(1)
	{  
		/*读取DHT11温湿度数据*/
		DHT11_delay_ms(1500);    //DHT11上电后要等待1S以越过不稳定状态在此期间不能发送任何指令
		DHT11_receive();  	

	/*读取ADC0809读取光强数值*/
	//		Read_Light();	 
		
	//Todo: 合并传感器数据到一个数组,用于串口发送和LCD显示
		
	/*串口蓝牙发送数据*/
	//	   send_string("Later");  	   
	//	   send_string(rec_dat);    //RH:湿度, CU:温度
	//	   send_string("\r\n"); 		
	/*LCD1602显示传感器数组*/
		
		
	}
}
