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
//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

uchar bluetooth[14];
uchar code CDIS1[14]={"BlueTooth Data"};

void main()
{  
	/*��ʼ���豸*/
	InitUART1();
	LcdInit();	
	startT0();
	while(1)
	{  
		uchar i=0;
		/*��ȡDHT11��ʪ������*/
		DHT11_delay_ms(1500);    //DHT11�ϵ��Ҫ�ȴ�1S��Խ�����ȶ�״̬�ڴ��ڼ䲻�ܷ����κ�ָ��
		DHT11_receive();  


		/*��ȡADC0809��ȡ��ǿ��ֵ*/
		delayms(10);		//80MS
		Read_Light();	

		
		/*LCD1602��ʾ����������*/
		LcdWriteCom(0x01);  //����
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
		for(i=0;i<2;i++)
		{
			LcdWriteData(' ');		
		}
		for(i=0;i<3;i++)
		{
			LcdWriteData(light[i]);	
		}
		LcdWriteData('L');	
		LcdWriteData('u');	
		//LcdWriteData('x');	
		
		
		bluetooth[0]='#';
		bluetooth[1]=' ';
		bluetooth[2]=rec_dat[0];
		bluetooth[3]=rec_dat[1];
		bluetooth[4]=' ';
		bluetooth[5]=rec_dat[6];
		bluetooth[6]=rec_dat[7];
		bluetooth[7]=' ';
		bluetooth[8]=light[0];
		bluetooth[9]=light[1];
		bluetooth[10]=light[2];
		bluetooth[11]=' ';
		bluetooth[12]='*';
		bluetooth[13]='\0';   //��β��,����Ҫ��
		
		/*����������������*/
		send_string(bluetooth);
		send_string("\r\n");
		delayms(20);		//80MS

	
	}
}

/*
************************************************************
*	�������ƣ�	t0
*
*	�������ܣ�	t0�жϻص�
*
*	��ڲ�����	
*
*	���ز�����	
*
*	˵����		ADCʱ�� 
************************************************************
*/  
void t0(void) interrupt 1 using 0 
{  
   CLK=~CLK; 
} 