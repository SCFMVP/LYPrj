/**
* Author: Later
* Time: 2020/5/1 18:54
* Info: ADC0809Driver
* Change:
**/

#ifndef __ADC0809_H__	  //定义ADC0809_HH文件，用于存放定时中断相关函数声明
#define __ADC0809_H__		

//宏定义
#define Data_ADC0809 P1
//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif


//ADC0809 控制引脚定义
sbit ST=P3^4;  //sbit ST=P3^1;
sbit EOC=P3^2;
sbit OE=P3^3;

uchar pdata tt[51];		    //定义空数组用于AD0809取平均值(RAM)
extern uchar ADC0809();	   //函数声明

/**********************************************************************
* 名称 : ADC0809();
* 功能 : ADC0809把模拟量转化为八位数字量
* 输入 : 无
* 输出 : 无
***********************************************************************/
uchar ADC0809()
{
	uchar temp_=0x00;
	
	OE=0;		 //初始化高阻态	   转化初始化   低电平，禁止输出允许

	ST=0;
	ST=1;		 //上升沿 清零    

	ST=0;		 //下降沿 开始转换
	
	while(EOC==0);	    //外部中断 等待AD转换结束	EOC为1时AD转换结束跳出
	
	OE=1;			  	//高电平，输出允许
	temp_=Data_ADC0809;	//读取转换的AD值

	OE=0;				//低电平，禁止输出允许
	return temp_;		//返回ADC读取值
}

#endif

