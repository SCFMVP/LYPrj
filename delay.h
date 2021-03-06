#ifndef __DELAY_H__	  //定义ADC0809_HH文件，用于存放定时中断相关函数声明
#define __DELAY_H__		
/**
 	************************************************************
 	************************************************************
 	************************************************************
 	*	文件名： 	delay.c
 	*
 	*	作者： 		Later
 	*
 	*	日期： 		2020-05-2
 	*
 	*	版本： 		V1.0
 	*
 	*	说明： 		延时函数
 	*
 	*	修改记录：	
 	************************************************************
 	************************************************************
 	************************************************************
 **/

//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

void delayms(uint ms);


#endif

