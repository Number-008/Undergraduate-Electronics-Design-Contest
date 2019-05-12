/*
 * DAC7811.c
 *
 *  Created on: 2013-7-11
 *      Author: fan_hang
 */

#include "msp430g2553.h"
#include  "DAC7811.h"
#include "lcd.h"
#include"math.h"
//SYNC P1.0  SCLK P1.1  DATA P1.2
void Init_7811()
{
	P1DIR |= BIT2 +BIT1 + BIT0;
	SCLK_L;
	SYNC_H;
	SCLK_L;
}

void DAC7811(u8 n)
{
	char BUF[5];
	u8 i=0;
	u16 temp;
	temp=n;
	temp = 0x1000|temp;
	SYNC_L;
	for(i=0; i<16; i++)
	{
		SCLK_H;
		if(temp & 0x8000) //0000_1000_0000_0000
		{
			SDI_H;//P1OUT |= BIT2;
		}
		else
		{
			SDI_L;//P1OUT &= ~BIT2;
		}
		temp <<= 1;
		SCLK_L;
	}
	SCLK_H;
	SYNC_H;


	BUF[0]=n/1000+0x30;
	BUF[1]=n/100%10+0x30;
	BUF[2]=n/10%10+0x30;
	BUF[3]=n%10+0x30;
	BUF[4]='\0';
	LCD_ShowString(1,2,BUF);
}


