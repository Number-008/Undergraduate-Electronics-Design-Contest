/*
 * ad9854.c
 *
 *  Created on: 2013-9-3
 *      Author: 覃海程
 */
#include "msp430G2553.h"
#include "spi.h"
#include "ad9854.h"

u8 FreqWord[6];

u8 AD9854SpiSendReceive(u8 Addr,u8 dat)
{
	u8 temp;
	//SpiSetCK(0);
	AD9854_CS_DOWN;
	SpiWriteData(Addr);
	temp=SpiWriteData(dat);
	AD9854_CS_UP;
	return (temp);
}

//函数功能:更新设置
//输入参数:无
//******************************************************************
void Update_AD9854(void)
{
	AD9854_UPDATE_UP ;
	__delay_cycles(100);
	AD9854_UPDATE_DOWN ;
	__delay_cycles(100);
	AD9854_UPDATE_UP ;
}
//******************************************************************

//函数功能:复位
//输入参数:无
//******************************************************************
void Io_Reset_AD9854(void)
{
	AD9854_IO_RESET_UP ;
	__delay_cycles(100);
	AD9854_IO_RESET_DOWN ;
}
//******************************************************************

//函数功能:AD9854初始化 写控制寄存器
//输入参数:无
//硬件说明：
//******************************************************************
void Init_AD9854(void)
{
	P1DIR |=BIT2 + BIT1 + BIT0;
	AD9854_OSC_ON;			//打开时钟
	AD9854_CS_DOWN ;        //片选
	AD9854_RESET_UP;
	__delay_cycles(10000);
	AD9854_RESET_DOWN;		//主复位
	Io_Reset_AD9854();
	AD9854_OSC_OFF;			//关闭时钟，更新配置
	AD9854SpiSendReceive(0x1d,0x10);//关闭比较器
	AD9854SpiSendReceive(0x1e,0x47); //设置系统时钟倍频 40*7=280M
	AD9854SpiSendReceive(0x1f,0x00); //设置系统为模式0，由外部更新
	AD9854SpiSendReceive(0x20,0x40);//关闭sinc函数滤波器以较少损耗
	AD9854_OSC_ON;			//打开时钟，更新配置
	__delay_cycles(10000);
	AD9854_UPDATE_DOWN;		//配置更新时钟为输出
}

void Write_AD9854_Freq(double Freq)
{
	u32 Low32;
	u16  High16;
	Freq*=1005267.773966629;
	High16 = (u16)(Freq/4294967295.0f);                  //2^32 = 4294967295
	Freq -= (double)High16*4294967295;
	Low32 = (u32)Freq;

    FreqWord[0]=Low32;
    FreqWord[1]=Low32>>8;
    FreqWord[2]=Low32>>16;
    FreqWord[3]=Low32>>24;
    FreqWord[4]=High16;
    FreqWord[5]=High16>>8;

	AD9854SpiSendReceive(0x04,FreqWord[5]);
	AD9854SpiSendReceive(0x05,FreqWord[4]);
	AD9854SpiSendReceive(0x06,FreqWord[3]);
	AD9854SpiSendReceive(0x07,FreqWord[2]);
	AD9854SpiSendReceive(0x08,FreqWord[1]);
	AD9854SpiSendReceive(0x09,FreqWord[0]);
	Update_AD9854();
}
