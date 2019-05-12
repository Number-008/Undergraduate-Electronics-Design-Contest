/*
 * key.c
 *
 *  Created on: 2013-7-4
 *      Author: qin
 */
#include "key.h"
#include "msp430G2553.h"
#include "lcd.h"
#include  "DAC7811.h"
void KeyInit(void)
{
	P1DIR &=~BIT3;
    P1REN |=BIT3;// P1.3 pullup��
    P1IES |= BIT3;
    P1IFG &= ~BIT3;
    P1IE |= BIT3;
}
u8 n=0;
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
		P1OUT^=BIT6;
		n+=10;
		if(n>60) n=0;
		DAC7811(n);
		//P1IFG &= ~BIT3;           //����жϱ�־λ
	}
	P1IFG = 0x00;                   //����жϱ�־λ
	return;                         //�˳��жϳ���
}
