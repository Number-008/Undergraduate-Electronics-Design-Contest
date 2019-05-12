#include "lcd12864.h"  


//��æ��
void LCD_CheckBusy(void)
{ 
	CLR_RS;
	SET_RW;
	SET_E;
	while((RD_REG & 0x80)==0x80);//��busy
	CLR_E;
	usleep(100);
   
}
//дָ��
void LCD_WriteCom(alt_u8 com)
{
    
	LCD_CheckBusy();
	CLR_RS;
	CLR_RW;
	SET_E;
	WR_DATA(com);
	CLR_E;
	usleep(100);
 }
//д����
void LCD_WriteData(alt_u8 data)
{
	LCD_CheckBusy();
	SET_RS;
	CLR_RW;
	SET_E;
	WR_DATA(data);
	CLR_E;
	usleep(100);
}
//��ʼ��
void LCD_Init(void)
{
	LCD_WriteCom(0x38);
	usleep(100);
	LCD_WriteCom(0x38);
	usleep(100);
	LCD_WriteCom(0x0c);
	usleep(100);
	LCD_WriteCom(0x06);
	usleep(100);
	LCD_WriteCom(0x01);
	usleep(1000);
}
//��ʾ�ַ���
void LCD_ShowString(alt_u8 x,alt_u8 y,char *str)
{
	alt_u8 addr;
	if(y==1)
	addr = 0x80 | x;
	else
	addr = 0xc0 | x;

    addr = (addr - 0x01);
    LCD_WriteCom(addr);
    while(*str!='\0')
    {
        LCD_WriteData(*str);
        str++;
    }
}
