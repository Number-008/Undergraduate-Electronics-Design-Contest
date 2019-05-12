/*
 * ad9854.c
 *
 *  Created on: 2013-9-3
 *      Author: ������
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

//��������:��������
//�������:��
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

//��������:��λ
//�������:��
//******************************************************************
void Io_Reset_AD9854(void)
{
	AD9854_IO_RESET_UP ;
	__delay_cycles(100);
	AD9854_IO_RESET_DOWN ;
}
//******************************************************************

//��������:AD9854��ʼ�� д���ƼĴ���
//�������:��
//Ӳ��˵����
//******************************************************************
void Init_AD9854(void)
{
	P1DIR |=BIT2 + BIT1 + BIT0;
	AD9854_OSC_ON;			//��ʱ��
	AD9854_CS_DOWN ;        //Ƭѡ
	AD9854_RESET_UP;
	__delay_cycles(10000);
	AD9854_RESET_DOWN;		//����λ
	Io_Reset_AD9854();
	AD9854_OSC_OFF;			//�ر�ʱ�ӣ���������
	AD9854SpiSendReceive(0x1d,0x10);//�رձȽ���
	AD9854SpiSendReceive(0x1e,0x47); //����ϵͳʱ�ӱ�Ƶ 40*7=280M
	AD9854SpiSendReceive(0x1f,0x00); //����ϵͳΪģʽ0�����ⲿ����
	AD9854SpiSendReceive(0x20,0x40);//�ر�sinc�����˲����Խ������
	AD9854_OSC_ON;			//��ʱ�ӣ���������
	__delay_cycles(10000);
	AD9854_UPDATE_DOWN;		//���ø���ʱ��Ϊ���
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
