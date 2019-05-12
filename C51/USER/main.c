#include "my_types.h"
#include"key.h"
#include"delay.h"
#include"lcd.h"	
#include"ad9851.h"
#include<absacc.h>
#include"ads7818.h"
#define LED XBYTE[0xfa00] //Y2



void main()
{	
	PGA_A0=0;
	PGA_A1=1;
	//Phase=0x00;
	//Fraq=0x000003e8;//1000
	P3=0xFF; 	//P3 ������IO �ڵ�ƽ����
	IT0=0; 		//�ⲿ�ж�1 �͵�ƽ�����ж�
	EX0=1; 		//�����ⲿ�ж�0 �ж�
	EA=1; 		//���������ж�	
	LCD_Init();
	LED=0xFF;

	LCD_ShowString(0,1,"100 ");
	//LCD_ShowString(0,1,"Fraq:");
	LCD_ShowString(14,1,"Hz");
	//LCD_ShowString(5,2,"V");
	//LCD_ShowString(0,2,"Phase:");
	WHILE_BUSY;
	LCD_CW = 0xc0 | 15;
	WHILE_BUSY;
	LCD_DW=0xDF;

	delay(500);
	PGA_A0=0;
	PGA_A1=1;
	AD9851WriteData();
	printf_Fraq();
	printf_Phase();
	AD9851WriteData();

	while(1)
	{
		//Key_Scan();
		delay(100);
		printf_AD();

	}

}

