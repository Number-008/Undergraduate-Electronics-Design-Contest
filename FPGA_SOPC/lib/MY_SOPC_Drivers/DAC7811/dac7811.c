/*
 * dac7811.c
 *
 *  Created on: 2013-7-16
 *      Author: Qin Hai Cheng
 */
#include"ads7818.h"
#include"dac7811.h"
#include"math.h"
#include "ili9320.h"
#include <sys/unistd.h>

alt_u16 DAC_DATA[6]={};

void DAC7811(alt_u8 dB)//Vo=-Vref*CODE/4096
{
	char BUF[5];
	alt_u8 i=0;
	alt_u16 temp;
	switch (dB)
	{
		case 0:{temp=DAC_DATA[0];}break;
		case 1:{temp=DAC_DATA[1];}break;
		case 2:{temp=DAC_DATA[2];}break;
		case 3:{temp=DAC_DATA[3];}break;
		case 4:{temp=DAC_DATA[4];}break;
		case 5:{temp=DAC_DATA[5];}break;
		case 6:{temp=DAC_DATA[6];}break;
		default:
			break;
	}
	BUF[3]='\0';

	temp = 0x1000|temp;//加载，并更新
	SCS2=0;
	usleep(1);
	for(i=0; i<16; i++)
	{
		SCLK=1;

		//usleep(1);
		if(temp & 0x8000) //0000_1000_0000_0000
		{
			MOSI=1;
		}
		else
		{
			MOSI=0;
		}
		temp <<= 1;
		SCLK=0;
		//usleep(1);
	}
	SCLK=1;//最后给一个上升沿更新数据
	//SCLK=0;
	usleep(1);
	SCS2=1;

	ili9320_ShowString(270,38,100,20,16,BUF,WHITE,BLACK);
}


