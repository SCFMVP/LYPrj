#ifndef __DHT11_H_
#define __DHT11_H_

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

sbit Data=P2^0;   //����������
extern uchar rec_dat[9];   //������ʾ�Ľ�����������

void DHT11_delay_us(uchar n);
void DHT11_delay_ms(uint z);
void DHT11_start();
uchar DHT11_rec_byte();
void DHT11_receive();

#endif