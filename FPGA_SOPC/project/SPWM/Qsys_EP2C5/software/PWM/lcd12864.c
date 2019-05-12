#include "lcd12864.h"  


//��æ��
void LCD_CheckBusy(void)
{ 
	CLR_RS;
	SET_RW;
	SET_E;
	while((RD_REG & 0x80)==0x80);//��busy
	CLR_E;
	usleep(72);
   
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
	usleep(72);
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
	usleep(72);
}
//��ʼ��
void LCD_Init(void)
{
	LCD_WriteCom(0x30);
	usleep(100);
	LCD_WriteCom(0x30);
	usleep(100);
	LCD_WriteCom(0x0c);
	usleep(100);
	LCD_WriteCom(0x10);
	usleep(100);
	LCD_WriteCom(0x01);
	usleep(1000);
	LCD_WriteCom(0x06);
	usleep(100);
  
}
//��ʾ�ַ���
void LCD_ShowString(alt_u8 x,alt_u8 y,char *str)
{
	alt_u8 addr;
    switch(y)
    {
        case 1:addr=0x80; break;
        case 2:addr=0x90; break;
        case 3:addr=0x88; break;
        case 4:addr=0x98; break;
    }
    addr |= (x - 0x01);
    LCD_WriteCom(addr);
    while(*str!='\0')
    {
        LCD_WriteData(*str);
        str++;
    }
}
