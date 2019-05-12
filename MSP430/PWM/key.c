/*
 * key.c
 *
 *  Created on: 2013-7-4
 *      Author: Qin Hai Cheng
 */
#include "key.h"
#include "msp430G2553.h"

void KeyInit(void)
{
	P1DIR &=~BIT3;
    P1REN |=BIT3;// P1.3 pullup��
    P1IES |= BIT3;
    P1IFG &= ~BIT3;
    P1IE |= BIT3;
}
u16 n=0;
#pragma vector=PORT1_VECTOR			//�ж���������
__interrupt void  Port_1(void)
{
	unsigned char PushKey;
	PushKey=P1IFG & BIT3;
	 __delay_cycles(5000);
	//delay_ms(10);
	if((P1IN & PushKey)==PushKey)
	{
		P1IFG = 0x00;return;
	}
	if(PushKey & BIT3)              //��P1.3������
	{
		while(!(P1IN & BIT3))
		{
			n+=1;
			if(n>512)n=0;
			TA1CCR2=n;
			__delay_cycles(50000);
		}
		//P1IFG &= ~BIT3;           //����жϱ�־λ
	}
	P1IFG = 0x00;                   //����жϱ�־λ
	return;                         //�˳��жϳ���
}
