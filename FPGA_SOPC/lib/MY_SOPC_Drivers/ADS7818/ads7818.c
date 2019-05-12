/*
 * dac7818.c
 *
 *  Created on: 2013-7-16
 *      Author: Qin Hai Cheng
 */
#include"ads7818.h"
#include <sys/unistd.h>
#include "ili9320.h"
//ADS7818 SPI驱动程序
alt_u16 Read_ADS7818(void)
{
	alt_u8 i;
	alt_u16 ADS7818=0;
	SCS1=0;
	usleep(5);
	SCLK=0;
	usleep(1);
	SCLK=1;
	usleep(1);
	SCLK=0;
	usleep(1);
	SCLK=1;
	usleep(1);
	for(i=0;i<12;i++)
	{	
		SCLK=0;//上升沿有效
		usleep(1);
		SCLK=1;
		usleep(1);
		ADS7818<<=1; 
		ADS7818|=MISO;
		usleep(1);
	}
	usleep(1);
	SCLK=0;
	usleep(1);
	SCLK=1;
	usleep(1);
	SCLK=0;
	usleep(1);
	SCLK=1;
	usleep(1);
	SCLK=0;//不可少！
	usleep(5);
	SCS1=1;
	ADS7818=ADS7818 & 0x0fff;
	return (ADS7818); 
}
////去掉最高位和最低位，然后取平均值,最后加权平均滤波
#define	READ_TIMES 50
#define	LOST_VAL 5

double  AN0;
//double  AN1;
alt_u16 Filter(void)
{
	alt_u8 i, j;
	alt_u16 temp;
	alt_u16  buf[READ_TIMES];
	for(i=0;i<READ_TIMES;i++)
	{
		buf[i]=Read_ADS7818();
		//usleep(5);
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
	//AN1=0.7*AN1+0.3*AN0;
	//return (AN1);
	return ((alt_u16)AN0);
}

//显示AD数字
void printf_AD(void)
{
	char BUF2[7];
	alt_u32 temp;
	temp=2.828427*(50000*Filter())/4096.0;
	if((temp%10)>=5)temp+=10;//四舍五入
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

	 ili9320_ShowString(10,10,100,20,16,BUF2,WHITE,BLUE);
}
