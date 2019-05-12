/*
 * PhaseMeasure.c
 *
 *  Created on: 2013-8-24
 *      Author:  Qin Hai Cheng
 *      频率1Hz--20kHz,相位分辨率为 1度.
 */
#include "PhaseMeasure.h"
#include "ili9320.h"
#include "string.h"

/********************************************************************
* 名 称：auto(double n)
* 功 能：自动切换显示单位
* 入口参数：n
* 出口参数：无
********************************************************************/
void TimeAuto(double n,alt_u16 x,alt_u16 y)
{
	char d[12];

	if( n>=1)
	{
		sprintf(d,"%9.3fs ",(double)n);
	}
	else if(n>=0.001 && n<1)
		{
			n=n*1000.0f;
			sprintf(d,"%9.3fms",(double)n);

		}
	else if(n>=0.000001 && n<0.001)
		{
			n=n*1000000.0f;
			sprintf(d,"%9.3fus",(double)n);
		}
	else if(n<0.000001)
		{
			n=n*1000000000.0f;
			sprintf(d,"%9.3fns",(double)n);

		}
	//d[13]='\0';
	//ili9320_ShowString(178,125,110,12,12,"     ",BLUE,BLUE);
	ili9320_ShowString(x,y,110,12,16,d,YELLOW,BLUE);
}

double ReadReg(alt_u32 R)//返回周期值
{
	double temp;
	temp=R/200000000.0f;
	return(temp);
}





