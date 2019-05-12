/*
 * ads7818.c
 *
 *  Created on: 2013-7-4
 *      Author: Qin Hai Cheng
 */
#include"ads7818.h"
#include "msp430g2553.h"
#include "lcd.h"
#include "spi.h"
//ADS7818 SPI驱动程序
u16 Read_ADS7818(void)
{
	u16 ADS7818=0;
	SpiSetCK(0);
	P1OUT &= ~BIT5;
	ADS7818=SpiSendData(0);
	P1OUT |= BIT5;
	return ((ADS7818>>2)& 0x0fff);//XXD11-D8D7-D0XX
}


//显示AD数字
void printf_AD(void)
{
	char BUF2[7];
	u32 temp;
	temp=(50000.0*Read_ADS7818())/4096.0;
	//if((temp%10)>=5)temp+=10;//四舍五入
	//if(temp<25000) temp-=10;
	if(temp<10000)
   	{
		BUF2[0]=' ';
		BUF2[1]=temp/1000%10+0x30;
		BUF2[2]=temp/100%10+0x30;
		BUF2[3]=temp/10%10+0x30;
		BUF2[4]='m';
		if(BUF2[1]==0x30 && BUF2[2]==0x30)
			BUF2[1]=BUF2[2]=' ';
		else if	(BUF2[1]==0x30)
			BUF2[1]=' ';	
	}
	else
	{
		BUF2[0]=temp/10000+0x30;
		BUF2[1]='.';
		BUF2[2]=temp/1000%10+0x30;
		BUF2[3]=temp/100%10+0x30;
		BUF2[4]=temp/10%10+0x30;
	}
	BUF2[5]='V';
	BUF2[6]='\0';
	LCD_ShowString(1,1,BUF2);
}
