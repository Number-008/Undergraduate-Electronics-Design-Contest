/*
 * DJD.c
 *
 *  Created on: 2013-5-18
 *      Author: qin
 */
#include "djd.h"
#include "alt_types.h"
#include "lcd12864.h"
#include "string.h"
/********************************************************************
* �� �ƣ�aut(double n)
* �� �ܣ��Զ��л���ʾ��λ
* ��ڲ�����n
* ���ڲ�������
********************************************************************/
void DJDaut(double n)
{
	char d[14];

	if(n>=0.000 && n<0.001)
	{
		n=n*1000000;
		sprintf(d,"%10.6fuHz",(double)n);
	}
	else if(n>=0.001 && n<1)
	{
		n=n*1000;
		sprintf(d,"%10.6fmHz",(double)n);
	}
	else if(n>=1 && n<1000)
	{
		sprintf(d,"%10.6fHz ",(double)n);

	}
	else if(n>=1000 && n<1000000)
	{
		n=n/1000;
		sprintf(d,"%10.6fKHz",(double)n);
	}
	else if(n>=1000000)
	{
		n=n/1000000;
		sprintf(d,"%10.6fMHz",(double)n);

	}
	d[13]='\0';
	LCD_ShowString(3,2,d);
}

double ReadDJD(void)//����Ƶ��ֵ
{
	double temp;
	alt_u32 d1,d2;
	d1=ReadTest;
	d2=ReadRef;
	temp=(d1*200000000.0f)/d2;
	return(temp);
}