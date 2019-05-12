/*
 * clk_div.c
 *
 *  Created on: 2013-5-18
 *      Author: qin
 */
#include "app.h"
#include "div.h"
#include "djd.h"
#include "ili9320.h"
#include "altera_avalon_pio_regs.h"
#include "unistd.h"//ÑÓÊ±º¯Êýusleep
#include "tlv5638.h"
alt_u8 LCKDIV=0;
alt_u8 VDIV=8;
void WrClkDiv(alt_u8 n)
{
	switch(n)
	{
		case 0:{
			WriteClkDiv(79999);//50Hz*25=1.25K
			//usleep(5);
			ili9320_ShowString(80,5,120,12,12,"Time 20.00ms/div",WHITE,BLACK);
		}break;
		case 1:{
			WriteClkDiv(39999);//100*25=2.5K
			//usleep(5);
			ili9320_ShowString(80,5,120,12,12,"Time 10.00ms/div",WHITE,BLACK);
		}break;
		case 2:{
			WriteClkDiv(19999);//200*25=5.0K
			//usleep(5);
			ili9320_ShowString(80,5,120,12,12,"Time 5.000ms/div",WHITE,BLACK);
		}break;
		case 3:{
			WriteClkDiv(7999);//500*25=12.5K
			//usleep(5);
			ili9320_ShowString(80,5,120,12,12,"Time 2.000ms/div",WHITE,BLACK);
		}break;
		case 4:{
			WriteClkDiv(3999);//1k*25=25K
			//usleep(5);
			ili9320_ShowString(80,5,120,12,12,"Time 1.000ms/div",WHITE,BLACK);
		}break;
		case 5:{
			WriteClkDiv(1999);//2k*25=50k
			//usleep(5);
			ili9320_ShowString(80,5,120,12,12,"Time 500.0us/div",WHITE,BLACK);
		}break;
		case 6:{
			WriteClkDiv(799);//5k*25=125k
			//usleep(5);
			ili9320_ShowString(80,5,120,12,12,"Time 200.0us/div",WHITE,BLACK);
		}break;
		case 7:{
			WriteClkDiv(399);//10k*25=250k
			//usleep(5);
			ili9320_ShowString(80,5,120,12,12,"Time 100.0us/div",WHITE,BLACK);
		}break;
		case 8:{
			WriteClkDiv(199);//20k*25=500k
			//usleep(5);
			ili9320_ShowString(80,5,120,12,12,"Time 50.00us/div",WHITE,BLACK);
		}break;
		case 9:{
			WriteClkDiv(79);//50k*25=1.25M
			//usleep(5);
			ili9320_ShowString(80,5,120,12,12,"Time 20.00us/div",WHITE,BLACK);
		}break;
		case 10:{
			WriteClkDiv(39);//100k*25=2.5M
			//usleep(5);
			ili9320_ShowString(80,5,120,12,12,"Time 10.00us/div",WHITE,BLACK);
		}break;
		case 11:{
			WriteClkDiv(19);//200k*25=5M
			//usleep(5);
			ili9320_ShowString(80,5,120,12,12,"Time 5.000us/div",WHITE,BLACK);
		}break;
		case 12:{
			WriteClkDiv(7);//500k*25=12.5M
			//usleep(5);
			ili9320_ShowString(80,5,120,12,12,"Time 2.000us/div",WHITE,BLACK);
		}break;
		case 13:{
			WriteClkDiv(3);//1m*25=25M
			//usleep(5);
			ili9320_ShowString(80,5,120,12,12,"Time 1.000us/div",WHITE,BLACK);
		}break;
		case 14:{
			WriteClkDiv(1);//2m*25=50M
			//usleep(5);
			ili9320_ShowString(80,5,120,12,12,"Time 500.0ns/div",WHITE,BLACK);
		}break;
		default:
			break;

	}
}

#define DIV1  403
#define DIV2  268
#define DIV5  558
alt_u16 DIV[10]={DIV2+1500,DIV5+1000-4,DIV1+1000,DIV2+1000-14,DIV5+500+4,
				 DIV1+500+8,DIV2+500-8,     DIV5,      DIV1+5,DIV2-4
};
void WrVDiv(alt_u8 n)
{

	switch(n)
	{
		case 0:{
			ili9320_ShowString(10,5,120,12,12,"2.00mV/div",WHITE,BLACK);//OK
			TLV5638_Out(DIV[0]);//1790
		}break;
		case 1:{
			ili9320_ShowString(10,5,120,12,12,"5.00mV/div",WHITE,BLACK);//25
			TLV5638_Out(DIV[1]);//1588
		}break;
		case 2:{
			ili9320_ShowString(10,5,120,12,12,"10.0mV/div",WHITE,BLACK);//1.25
			TLV5638_Out(DIV[2]);//1448

		}break;
		case 3:{
			ili9320_ShowString(10,5,120,12,12,"20.0mV/div",WHITE,BLACK);//OK
			TLV5638_Out(DIV[3]);//1298

		}break;
		case 4:{
			ili9320_ShowString(10,5,120,12,12,"50.0mV/div",WHITE,BLACK);//OK
			TLV5638_Out(DIV[4]);//1091

		}break;
		case 5:{
			ili9320_ShowString(10,5,120,12,12,"100mV/div",WHITE,BLACK);//1/4
			TLV5638_Out(DIV[5]);//925

		}break;
		case 6:{
			ili9320_ShowString(10,5,120,12,12,"200mV/div",WHITE,BLACK);//1/4
			TLV5638_Out(DIV[6]);//768

		}break;
		case 7:{
			ili9320_ShowString(10,5,120,12,12,"500mV/div",WHITE,BLACK);//OK
			TLV5638_Out(DIV[7]);//558

		}break;
		case 8:{
			ili9320_ShowString(10,5,120,12,12,"1.00V/div ",WHITE,BLACK);//1/4
			TLV5638_Out(DIV[8]);//403

		}break;
		case 9:{
			ili9320_ShowString(10,5,120,12,12,"2.00V/div ",WHITE,BLACK);//1/4
			TLV5638_Out(DIV[9]);//268

		}break;
		default:
			break;

	}
}

