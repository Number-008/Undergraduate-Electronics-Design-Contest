#ifndef __LCD_H
#define __LCD_H	
#include<absacc.h>
#include "my_types.h"

#define LCD_CONTROLLER (1602)//ѡ��LCD�豸, 1602��12864
//RW--A7;RS--A6
//RW:H--����L--д
//RS:H--���ݣ�L--ָ��
#if (LCD_CONTROLLER == 1602)
#define LCD_CW XBYTE[0xF800]
#define LCD_DW XBYTE[0xF840]
#define LCD_CR XBYTE[0xF880]
#endif

#if (LCD_CONTROLLER == 12864)
#define LCD_CW XBYTE[0xF900]//	дָ��
#define LCD_DW XBYTE[0xF940]//	д����
#define LCD_CR XBYTE[0xF980]//	��REG
#define LCD_DR XBYTE[0xF9C0]// �����ݣ�����ʱ�õ�
#endif


#define WHILE_BUSY while(LCD_CR & 0x80)//��æ��

void LCD_Init(void);						//LCD��ʼ��
void LCD_ShowString(u8 x,u8 y, u8 *str);	//LCD�ַ������	,x--�У�y--��
#if (LCD_CONTROLLER == 1602)
//void LCD_ShowChar(u8 addr,u8 dat);     		//LCD�ַ����
//void LCD_WriteData(u8 dat);
#endif
#endif /*__LCD_H*/
 