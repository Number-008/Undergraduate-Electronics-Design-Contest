#ifndef __LCD_H
#define __LCD_H	
#include<absacc.h>
#include "my_types.h"

#define LCD_CONTROLLER (1602)//选择LCD设备, 1602或12864
//RW--A7;RS--A6
//RW:H--读，L--写
//RS:H--数据，L--指令
#if (LCD_CONTROLLER == 1602)
#define LCD_CW XBYTE[0xF800]
#define LCD_DW XBYTE[0xF840]
#define LCD_CR XBYTE[0xF880]
#endif

#if (LCD_CONTROLLER == 12864)
#define LCD_CW XBYTE[0xF900]//	写指令
#define LCD_DW XBYTE[0xF940]//	写数据
#define LCD_CR XBYTE[0xF980]//	读REG
#define LCD_DR XBYTE[0xF9C0]// 读数据，画点时用到
#endif


#define WHILE_BUSY while(LCD_CR & 0x80)//读忙标

void LCD_Init(void);						//LCD初始化
void LCD_ShowString(u8 x,u8 y, u8 *str);	//LCD字符串输出	,x--行，y--列
#if (LCD_CONTROLLER == 1602)
//void LCD_ShowChar(u8 addr,u8 dat);     		//LCD字符输出
//void LCD_WriteData(u8 dat);
#endif
#endif /*__LCD_H*/
 