/*
 * tlc2543.c
 *
 *  Created on: 2013-7-29
 *      Author: Qin Hai Cheng
 */
#include "lcd.h"
#include "spi.h"
#include "tlc2543.h"

void TLC2543Init(void)
{
	P1DIR &=~BIT6;	//EOC
	P2DIR |=BIT5;	//CS
	P2REN |=BIT5;
}
u16 Read_TLC2543(u8 chx_num)
{
	u16 TLC2543=0;
	chx_num <<=4;
	//while((P1IN & BIT6)==0);
	SpiSetCK(2);
	P2OUT &= ~BIT5;
	TLC2543=SpiWriteData(chx_num | 0x0c) & 0xff;
	TLC2543<<=8;
	TLC2543 |= (SpiWriteData(chx_num | 0x0c) & 0xff);
	P2OUT |= BIT5;
	while((P1IN & BIT6)==0);
	return ((TLC2543>>4)& 0x0fff);
}

//显示AD数字
void Printf_AD(u8 chx_num,char *DisBuf,u8 x)
{
	u16 temp;
	Read_TLC2543(chx_num);
	temp=4096.0*Read_TLC2543(chx_num)/4095;//参考电压=4.096V
	if(temp<1000)
   	{
		DisBuf[x+0]=' ';
		DisBuf[x+1]=temp/100%10+0x30;
		DisBuf[x+2]=temp/10%10+0x30;
		DisBuf[x+3]=temp%10+0x30;
		DisBuf[x+4]='m';
		if(DisBuf[x+1]==0x30 && DisBuf[x+2]==0x30)
			DisBuf[x+1]=DisBuf[x+2]=' ';
		else if	(DisBuf[x+1]==0x30)
			DisBuf[x+1]=' ';
	}
	else
	{
		DisBuf[x+0]=temp/1000+0x30;
		DisBuf[x+1]='.';
		DisBuf[x+2]=temp/100%10+0x30;
		DisBuf[x+3]=temp/10%10+0x30;
		DisBuf[x+4]=temp%10+0x30;
	}
	DisBuf[x+5]='V';
	//DisBuf[6]='\0';
	//LCD_ShowString(x,y,DisBuf);
}


