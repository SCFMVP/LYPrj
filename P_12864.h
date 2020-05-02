/**************dis_12864.h***************/

#include <reg52.h>

#ifndef __P_12864_H__
#define __P_12864_H__

#define uchar unsigned char
#define uint  unsigned int

/*12864�˿ڶ���*/
#define LCD_data  P0             //���ݿ�
sbit LCD_RS  =  P1^0;            //�Ĵ���ѡ������ 
sbit LCD_RW  =  P1^1;            //Һ����/д����
sbit LCD_EN  =  P2^5;            //Һ��ʹ�ܿ���

sbit LCD_PSB =  P1^2;            //��/����ʽ����


/*��������*/
void delay(int ms);
void lcd_init(); 
void beep();
void  dataconv();
void lcd_pos(uchar X,uchar Y);  //ȷ����ʾλ��
void zifu_dis (uchar X,uchar Y,uchar *dis);

#endif