/*
 * PhaseMeasure.c
 *
 *  Created on: 2013-8-24
 *      Author:  Qin Hai Cheng
 *      Ƶ��1Hz--20kHz,��λ�ֱ���Ϊ 1��.
 */
#include "PhaseMeasure.h"
#include "ili9320.h"
#include "string.h"

/********************************************************************
* �� �ƣ�auto(double n)
* �� �ܣ��Զ��л���ʾ��λ
* ��ڲ�����n
* ���ڲ�������
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

double ReadReg(alt_u32 R)//��������ֵ
{
	double temp;
	temp=R/200000000.0f;
	return(temp);
}





