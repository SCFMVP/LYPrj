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
#include "delay.h"

#include <intrins.h>
//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

uchar bluetooth[11];
uchar code CDIS1[14]={"BlueTooth Data"};

void main()
{  
	/*初始化设备*/
	InitUART1();
	LcdInit();	
	startT0();
	while(1)
	{  
		uchar i=0;
		/*读取DHT11温湿度数据*/
		DHT11_delay_ms(1500);    //DHT11上电后要等待1S以越过不稳定状态在此期间不能发送任何指令
		DHT11_receive();  
//		send_string(rec_dat);    //RH:湿度, CU:温度
//		send_string("\r\n");

		/*读取ADC0809读取光强数值*/
		delayms(10);		//80MS
		Read_Light();	
//		send_string(light);    	
//		send_string("\r\n");
		
		/*LCD1602显示传感器数组*/
		LcdWriteCom(0x01);  //清屏
		LcdWriteCom(0x80);
		for(i=0;i<14;i++)
		{
			LcdWriteData(CDIS1[i]);	
		}
		LcdWriteCom(0x80+0x40);
		for(i=0;i<9;i++)
		{
			LcdWriteData(rec_dat[i]);		
		}
		for(i=0;i<3;i++)
		{
			LcdWriteData(light[i]);	
		}
		
		bluetooth[0]='#';
		bluetooth[1]=rec_dat[0];
		bluetooth[2]=rec_dat[1];
		bluetooth[3]=' ';
		bluetooth[4]=rec_dat[6];
		bluetooth[5]=rec_dat[7];
		bluetooth[6]=' ';
		bluetooth[7]=light[0];
		bluetooth[8]=light[1];
		bluetooth[9]=light[2];
		bluetooth[10]='#';
		
		/*串口蓝牙发送数据*/
		send_string(bluetooth);
		send_string("\r\n");
	
	}
}

/*
************************************************************
*	函数名称：	t0
*
*	函数功能：	t0中断回调
*
*	入口参数：	
*
*	返回参数：	
*
*	说明：		ADC时钟 
************************************************************
*/  
void t0(void) interrupt 1 using 0 
{  
   CLK=~CLK; 
} 