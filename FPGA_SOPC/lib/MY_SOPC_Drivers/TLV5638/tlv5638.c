/*
 * tlv5638.c
 *
 *  Created on: 2013-5-19
 *      Author: Qin Hai Cheng
 */

#include "tlv5638.h"
#include "unistd.h"
#include "ili9320.h"
alt_u16 TLV5638=1000;

//SPIд����
void TLV5638_Write(alt_u16 dat)
{
	alt_u8 i=0;
	SCLK=0;
	usleep(1);
	CS=0;
	usleep(1);
	for(i=0;i<16;i++)
	{
		if(dat&0x8000)DIN=1;
		else DIN=0;
		usleep(1);
		dat<<=1;
		usleep(1);
		SCLK=1;//�½�����Ч
		usleep(1);
		SCLK=0;
		usleep(1);
	}
	SCLK=1;//����һ�������ظ�������
	usleep(1);
	CS = 1;
	usleep(1);
}

void TLV5638_Out(alt_u16 dat)// V0=CODE*0.001(V)
{
	char BUF[8];
    TLV5638_Write(0xd002);//2.048V  fast mode\normal operation
    TLV5638_Write(0xc000 | dat);//Write new DAC B value to BUFFER and update DAC B output
	//TLV5638_Write(0xd002);
	//TLV5638_Write(0xc000 | dat);

/*   if(dat<1000)
   {
	BUF[1]=' ';
   	BUF[2]=dat/100%10+0x30;
	BUF[3]=dat/10%10+0x30;
	BUF[4]=dat%10+0x30;
	if	(BUF[2]==0x30 && BUF[3]==0x30)
		BUF[2]=BUF[3]=' ';
	else if	(BUF[2]==0x30 )
		BUF[2]=' ';
	BUF[5]='m';
	BUF[6]='V';
   }
   else  if(dat>=1000)
   {
		BUF[1]=dat/1000+0x30;
		BUF[2]='.';
	   	BUF[3]=dat/100%10+0x30;
		BUF[4]=dat/10%10+0x30;
		BUF[5]=dat%10+0x30;
		BUF[6]='V';
   	 }
   BUF[7]='\0';
   ili9320_ShowString(277,5,120,12,12,BUF,YELLOW,BLACK);*/

}








//D14:1--fast mode��0--slow mode
//D13:1--power down,0--normal operation
//D15      D12
//0			0	д���ݵ�DAC B�ͻ���
//0			1	д���ݵ�������
//1			0	д���ݵ�DAC A�͸���DAC B �뻺����������
//1			1	д���ݵ����ƼĴ���
//���ƼĴ���	XXXXX	D1		D0
//						0		0  EXT
//						0		1  1.024
//						1		0  2.048
//						1		1  EXT
//TLV5638_Write(0x2000);//����Ϊ�͹���ģʽ
//0XD001 1.024V 0XD002 2.048V  fast mode\normal operation

//0x5000 | XXXX	 Write new DAC B value to BUFFER and update DAC B output
//0x1000 | XXXX	 Write data for DAC B to BUFFER
//oxc000 | XXXX	 Write new DAC A value and update DAC A and B simultaneously
