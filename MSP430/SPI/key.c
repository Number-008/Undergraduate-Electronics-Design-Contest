/*
 * key.c
 *
 *  Created on: 2013-7-4
 *      Author: Qin Hai Cheng
 */
#include "key.h"
#include "msp430G2553.h"
#include "lcd.h"
#include "tlv5638.h"
void KeyInit(void)
{
	P1DIR &=~BIT3;
    P1REN |=BIT3;// P1.3 pullup；
    P1IES |= BIT3;
    P1IFG &= ~BIT3;
    P1IE |= BIT3;
    _EINT();//总中断允许
}
#pragma vector=PORT1_VECTOR			//中断向量声明
__interrupt void  Port_1(void)
{
	unsigned char PushKey;
	PushKey=P1IFG & BIT3;
	 //__delay_cycles(5000);
	//delay_ms(10);
	if((P1IN & PushKey)==PushKey)
	{
		P1IFG = 0x00;return;
	}
	if(PushKey & BIT3)              //若P1.3被按下
	{
		TLV5638+=100;
		if(TLV5638>4096)TLV5638=0;
		LCDWrite(W_CMD,0x01);
		TLV5638_Out(TLV5638);
		//P1IFG &= ~BIT3;           //清除中断标志位
	}
	P1IFG = 0x00;                   //清除中断标志位
	return;                         //退出中断程序
}
