/**
* Author: Later
* Time: 2020/5/1 18:54
* Info: ADC0809Driver
* Change:
**/

#ifndef __ADC0809_H__	  //����ADC0809_HH�ļ������ڴ�Ŷ�ʱ�ж���غ�������
#define __ADC0809_H__		

//�궨��
#define Data_ADC0809 P1
//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif


//ADC0809 �������Ŷ���
sbit ST=P3^4;  //sbit ST=P3^1;
sbit EOC=P3^2;
sbit OE=P3^3;

uchar pdata tt[51];		    //�������������AD0809ȡƽ��ֵ(RAM)
extern uchar ADC0809();	   //��������

/**********************************************************************
* ���� : ADC0809();
* ���� : ADC0809��ģ����ת��Ϊ��λ������
* ���� : ��
* ��� : ��
***********************************************************************/
uchar ADC0809()
{
	uchar temp_=0x00;
	
	OE=0;		 //��ʼ������̬	   ת����ʼ��   �͵�ƽ����ֹ�������

	ST=0;
	ST=1;		 //������ ����    

	ST=0;		 //�½��� ��ʼת��
	
	while(EOC==0);	    //�ⲿ�ж� �ȴ�ADת������	EOCΪ1ʱADת����������
	
	OE=1;			  	//�ߵ�ƽ���������
	temp_=Data_ADC0809;	//��ȡת����ADֵ

	OE=0;				//�͵�ƽ����ֹ�������
	return temp_;		//����ADC��ȡֵ
}

#endif

