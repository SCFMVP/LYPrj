#ifndef __DHT11_H_
#define __DHT11_H_

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

sbit Data=P3^3;   //定义数据线
extern uchar rec_dat[9];   //用于显示的接收数据数组

void DHT11_delay_us(uchar n);
void DHT11_delay_ms(uint z);
void DHT11_start();
uchar DHT11_rec_byte();
void DHT11_receive();

#endif