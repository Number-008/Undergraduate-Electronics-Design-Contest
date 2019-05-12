/*
 * ads8513.c
 *
 *  Created on: 2013-7-20
 *      Author: Qin Hai Cheng
 */
#include "lcd.h"
#include "ads8513.h"
void ADS8513Init(void)
{
	P1DIR &=~(BIT7);		//P1.6---BUSY;P1.7---DATA
	P2DIR |=BIT4 + BIT5;	//P2.4--CONV;P2.5---DATACLK
	P2DIR &=~BIT3;
}

u16 ADS8513(void)
{
	u8 i;
	u16 AD=0;
	CONV_L;//启动转换
	while((P2IN & BIT3)==0);	//等待转换结束
	for(i=0;i<16;i++)			//输出转换结果
	{
		AD<<=1;
		DATACLK_H;
		 __delay_cycles(50);
		DATACLK_L;
		if(P1IN & BIT7) AD|=0x0001;
	}
	CONV_H;
	return (AD);
}
////去掉最高位和最低位，然后取平均值,最后加权平均滤波
#define	READ_TIMES 50
#define	LOST_VAL 5

double  AN0;
double  AN1;
u16 Filter(void)
{
	u8 i, j;
	u16 temp;
	u16  buf[READ_TIMES];
	for(i=0;i<READ_TIMES;i++)
	{
		buf[i]=ADS8513();
	}
	for(i=0;i<READ_TIMES-1; i++)//排序
	{
		for(j=i+1;j<READ_TIMES;j++)
		{
			if(buf[i]>buf[j])//升序排列
			{
				temp=buf[i];
				buf[i]=buf[j];
				buf[j]=temp;
			}
		}
	}
	AN0=0;
	for(i=LOST_VAL;i<READ_TIMES-LOST_VAL;i++)AN0+=buf[i];
	AN0=AN0/(READ_TIMES-2*LOST_VAL);
	AN1=0.7*AN1+0.3*AN0;
	//return (AN1);
	return ((u16)AN1);
}
void Printf_AD(void)
{
	u16 temp;
	double Vad;
	char BUF[9];
	temp=Filter();
	if(temp & 0x8000)
	{
		BUF[0]='-';
		temp=~temp+1;
		Vad=50000*temp/32767.0f-300;
	}else
		{
			BUF[0]=' ';
			Vad=50000*temp/32767.0f+300;
		}
	if(Vad<10000)
	{
		BUF[1]=(u32)Vad/1000+0x30;
		BUF[2]=(u32)Vad/100%10+0x30;
		BUF[3]=(u32)Vad/10%10+0x30;
		BUF[4]='.';
		BUF[5]=(u32)Vad%10+0x30;
		if(BUF[1]==0x30 && BUF[2]==0x30)
			BUF[1]=BUF[2]=' ';
		else if	(BUF[1]==0x30)
			BUF[1]=' ';
		BUF[6]='m';
	}
	else
	{
		if(((u32)Vad%10)>=5) Vad+=10;
		BUF[1]=(u32)Vad/100000+0x30;
		BUF[2]=(u32)Vad/10000%10+0x30;
		BUF[3]='.';
		BUF[4]=(u32)Vad/1000%10+0x30;
		BUF[5]=(u32)Vad/100%10+0x30;
		BUF[6]=(u32)Vad/10%10+0x30;
		if(BUF[1]==0x30)
			BUF[1]=' ';
	}
	BUF[7]='V';
	BUF[8]='\0';
	LCD_ShowString(1,2,BUF);
}
