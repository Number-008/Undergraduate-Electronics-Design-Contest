/*
 * delay.c
 *
 *  Created on: 2013-7-4
 *      Author: Qin Hai Cheng
 */
#include "msp430G2553.h"
#include "delay.h"


//__delay_cycles(10000);

void delay(u16 n)
{
	u8 j;
	while(n--)
	{
		for(j=120;j>0;j--);
	}
}

void delay_ms(u16 n)//n<=2000
{
	TA1CCTL0 = CCIE;
	TA1CCR0 = (u16)(32.768f*n);
	TA1CTL = TASSEL_1 + MC_1+TACLR ;
	 _BIS_SR(LPM3_bits + GIE);                 // Enter LPM3 w/interrupt

}

#pragma vector=TIMER1_A0_VECTOR
__interrupt void Timer_A (void)
{
	TA1CCTL0 &=~CCIE;
	TA1CTL &=0xFFFD;
	_BIC_SR_IRQ(LPM3_bits);                 // Clear LPM3 bits from 0(SR)
}


