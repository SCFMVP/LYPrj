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
//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif
int Read_Light()
{
	uchar b,c;
	uint lum_mean,lum_all;		//ad0809����ֵ

	for( b=0;b<49;b++) 			//��������tt[51]����ֵ��������һλ
	{
		tt[b]=tt[b+1];			//����һ��ֵ�ŵ�ǰһλ��
	}
	tt[49]=ADC0809();			//��������ad0809��ֵ����tt[49]
	for( c=0;c<50;c++)			//��tt[]����ֵ���
	{
		lum_all=lum_all+tt[c];
	}
	return lum_mean=lum_all/50;		//������/50ȡ��ƽ��ֵ
}
void main()
{  
	/*��ʼ���豸*/
	InitUART1();
	LcdInit();	
	while(1)
	{  
		/*��ȡDHT11��ʪ������*/
		DHT11_delay_ms(1500);    //DHT11�ϵ��Ҫ�ȴ�1S��Խ�����ȶ�״̬�ڴ��ڼ䲻�ܷ����κ�ָ��
		DHT11_receive();  	

	/*��ȡADC0809��ȡ��ǿ��ֵ*/
	//		Read_Light();	 
		
	//Todo: �ϲ����������ݵ�һ������,���ڴ��ڷ��ͺ�LCD��ʾ
		
	/*����������������*/
	//	   send_string("Later");  	   
	//	   send_string(rec_dat);    //RH:ʪ��, CU:�¶�
	//	   send_string("\r\n"); 		
	/*LCD1602��ʾ����������*/
		
		
	}
}
