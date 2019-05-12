/*
 * spi.c
 *
 *  Created on: 2013-7-21
 *      Author: qin
 */
#include "msp430G2553.h"
#include "spi.h"

//����һ���ֽ�����
void SpiWriteDat(u8 c)
{
	UCA0TXBUF=c;
	while ((IFG2 & UCA0TXIFG)==0); // �ȴ���һ�ֽڷ���
	IFG2 &=~ UCA0TXIFG;
}
//����һ���ֽ�����
u8 SpiReadDat(void)
{
	while ((IFG2 & UCA0RXIFG)==0); // �յ�һ�ֽ�?
	IFG2 &=~ UCA0RXIFG;
    return(UCA0RXBUF);
}

//���ͺͽ���һ���ֽ�����
u8 SpiWriteData(u8 c)
{
	SpiWriteDat(c);
	return SpiReadDat();
}
//SPIʱ��ģʽ����
//0:�����ط��ͣ��½��ؽ��գ�����UCLK,			ʱ���źŵĵ͵�ƽΪ��Ч��ƽ��
//1:�½��ط��ͣ������ؽ��գ�����UCLK,			ʱ���źŵĸߵ�ƽΪ��Ч��ƽ��
//2:�½��ط��ͣ������ؽ��գ���ʱ�������UCLK,	ʱ���źŵĵ͵�ƽΪ��Ч��ƽ��
//3:�����ط��ͣ��½��ؽ��գ���ʱ�������UCLK,	ʱ���źŵĸߵ�ƽΪ��Ч��ƽ��
void SpiSetCK(u8 P)
{
	switch(P)
	{
		case 0:{UCA0CTL0 &= ~UCCKPH;	UCA0CTL0 &= ~UCCKPL;}break;
		case 1:{UCA0CTL0 &= ~UCCKPH;	UCA0CTL0 |= UCCKPL;	}break;
		case 2:{UCA0CTL0 |= UCCKPH;		UCA0CTL0 &= ~UCCKPL;}break;
		case 3:{UCA0CTL0 |= UCCKPH;		UCA0CTL0 |= UCCKPL;	}break;
		default:break;
	}
}

//SPI��ʼ������
void SpiInit(void)
{
	UCA0CTL1 |= UCSWRST;
	P1SEL = BIT1 + BIT2 + BIT4;
	P1SEL2 = BIT1 + BIT2 + BIT4;
	UCA0CTL0 |=  UCMSB + UCMST + UCSYNC;  	// 3-pin, 8-bit SPI master
	UCA0CTL1 |= UCSSEL_2;                   // SMCLK
	UCA0BR0 = 0x02;							//1M/2=500KHz
	UCA0BR1 = 0x00;
	UCA0MCTL = 0x00; 						// no modulation
	SpiSetCK(2);
	UCA0CTL1 &= ~UCSWRST;                   // **Initialize USCI state machine**
	//IE2 |= UCA0RXIE;                      // Enable USCI0 RX interrupt
}