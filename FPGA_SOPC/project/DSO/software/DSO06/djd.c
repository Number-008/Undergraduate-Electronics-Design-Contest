/*
 * DJD.c
 *
 *  Created on: 2013-5-18
 *      Author: qin
 */
#include "div.h"
#include "djd.h"
#include "alt_types.h"
#include "ili9320.h"
#include "string.h"
#include "altera_avalon_pio_regs.h"
#include "app.h"
#include "key.h"
/********************************************************************
* 名 称：aut(double n)
* 功 能：自动切换显示单位
* 入口参数：n
* 出口参数：无
********************************************************************/
__inline void DJDaut(double n)
{
	char d[14];
	double temp=0.0f;

	if(n>=0 && n<1000)
	{
		temp=n*1000000.0f;
		d[10]='H';
		d[11]='z';
		d[12]=' ';

	}
	else if(n>=1000 && n<1000000)
	{
		temp=n*1000;
		d[10]='K';
		d[11]='H';
		d[12]='z';
	}
	else if(n>=1000000)
	{
		temp=n;
		d[10]='M';
		d[11]='H';
		d[12]='z';
	}
	//if((alt_u32)(10.0*temp)%10>=5) temp+=1;//四舍五入
	d[0]=(alt_u32)temp/100000000+0x30;
	d[1]=(alt_u32)temp/10000000%10+0x30;
	d[2]=(alt_u32)temp/1000000%10+0x30;
	d[3]='.';
	d[4]=(alt_u32)temp/100000%10+0x30;
	d[5]=(alt_u32)temp/10000%10+0x30;
	d[6]=(alt_u32)temp/1000%10+0x30;
	d[7]=(alt_u32)temp/100%10+0x30;
	d[8]=(alt_u32)temp/10%10+0x30;
	d[9]=(alt_u32)temp%10+0x30;
	d[13]='\0';
	if(d[0]==0x30 && d[1]==0x30)
		d[0]=d[1]=' ';
	else if(d[0]==0x30) d[0]=' ';

	ili9320_ShowString(107,225,110,12,12,d,YELLOW,BLACK);
}
double djd_Freq;
void ReadDJD(void)//返回频率值
{
	alt_u32 d1,d2;
	d1=ReadTest;
	d2=ReadRef;
	djd_Freq=(d1*200000000.0f)/d2;
}

double cp(void)
{
	double f;
	alt_u16 i,j;
	alt_u16 temp[10];
	j=0;
	for(i=0;i<500;i++)
		if(data_in[i+6]>=TRIG_DATA && data_in[i+5]<TRIG_DATA)
		{
			if(j<10)
			{
				temp[j]=i;
				j++;
			}
		}
	if(j>2) f=(temp[j-1]-temp[1])/(j-2);
	switch(LCKDIV)
	{
		case 0:f=1250/f;break;
		case 1:f=2500/f;break;
		case 2:f=5000/f;break;
		case 3:f=12500/f;break;
		case 4:f=25000/f;break;
		case 5:f=50000/f;break;
		case 6:f=125000/f;break;
		case 7:f=250000/f;break;
		case 8:f=500000/f;break;
		case 9:f=1250000/f;break;
		case 10:f=2500000/f;break;
		case 11:f=5000000/f;break;
		case 12:f=12500000/f;break;
		case 13:f=25000000/f;break;
		case 14:f=50000000/f;break;
		default:break;
	}
	return(f);
}
