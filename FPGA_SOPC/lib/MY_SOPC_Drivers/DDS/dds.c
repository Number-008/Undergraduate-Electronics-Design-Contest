/*
 * dds.c
 *
 *  Created on: 2013-7-12
 *  Author: Qin Hai Cheng
 */
#include "dds.h"
#include "string.h"
#include "ili9320.h"
double Freq=1000;
float Phasew=0;

void WriteFreq(double n)//2^48=281474976710656;
{
	alt_u64 K;
	K=n*1759218.6044416;
	FREQW_L((alt_u32) K);
	FREQW_H((alt_u32)(K>> 32 ));
}

void WritePhasew(float n)
{
	double P;
	P=n*1.40625f;
	PHASEW((alt_u32) P);

}


//ÏÔÊ¾ÆµÂÊÖµ
void DDS_OUT(double n)
{
   char d[14];
   double Fn;

   Fn=n;
   WriteFreq(Fn);
   if(Fn>=0.000 && Fn<0.001)
   	{
	   Fn=Fn*1000000;
   		sprintf(d,"%10.6fuHz",(double)Fn);
   	}
   else if(Fn>=0.001 && Fn<1)
   	{
	   Fn=Fn*1000;
   		sprintf(d,"%10.6fmHz",(double)Fn);
   	}
   	else if(Fn>=1 && Fn<1000)
   		{
   			sprintf(d,"%10.6fHz ",(double)Fn);

   		}
   	else if(Fn>=1000 && Fn<1000000)
   		{
   			Fn=Fn/1000;
   			sprintf(d,"%10.6fKHz",(double)Fn);
   		}
   	else if(Fn>=1000000)
   		{
   			Fn=Fn/1000000;
   			sprintf(d,"%10.6fMHz",(double)Fn);

   		}

   ili9320_ShowString(216,225,120,12,12,d,YELLOW,BLACK);

}

void DDS_Phasew(float n)
{
   char d[6];
   WritePhasew(n/10.0f);
   d[0]=(alt_u32)n/1000+0x30;
   d[1]=(alt_u32)n/100%10+0x30;
   d[2]=(alt_u32)n/10%10+0x30;
   d[3]='.';
   d[4]=(alt_u32)n%10+0x30;
   d[5]='\0';
   ili9320_ShowString(152,140,180,145,16,d,WHITE,BLUE);

}
