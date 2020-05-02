/**************dis_12864.h***************/

#include <reg52.h>

#ifndef __P_12864_H__
#define __P_12864_H__

#define uchar unsigned char
#define uint  unsigned int

/*12864端口定义*/
#define LCD_data  P0             //数据口
sbit LCD_RS  =  P1^0;            //寄存器选择输入 
sbit LCD_RW  =  P1^1;            //液晶读/写控制
sbit LCD_EN  =  P2^5;            //液晶使能控制

sbit LCD_PSB =  P1^2;            //串/并方式控制


/*函数声明*/
void delay(int ms);
void lcd_init(); 
void beep();
void  dataconv();
void lcd_pos(uchar X,uchar Y);  //确定显示位置
void zifu_dis (uchar X,uchar Y,uchar *dis);

#endif