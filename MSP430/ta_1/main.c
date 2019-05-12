#include "msp430G2553.h"
void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  BCSCTL1 = CALBC1_1MHZ;                   // Set range
  DCOCTL = CALDCO_1MHZ;

  P1SEL|=BIT1;
  P1REN|=BIT1;
  P1DIR |= BIT0+BIT6;
  CCTL0 = CCIE+CCIS_0+CM_2+CAP+SCS;
  TACTL  = TAIE+TASSEL_2 +TACLR  + MC_2+ID_0;
  P1OUT &= ~(BIT0+BIT6);

  _BIS_SR(LPM0_bits + GIE);                 // Enter LPM0 w/ interrupt
}

// Timer A0 interrupt service routine
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
{
  P1OUT ^= 0x01;                            // Toggle P1.0
}

#pragma vector=TIMER0_A1_VECTOR
__interrupt void Timer_A0(void)
{
 switch( TA0IV )
 {
   case  2: break;                          // CCR1 not used
   case  4: break;                          // CCR2 not used
   case 10: P1OUT ^= BIT6;                  // overflow
            break;
 }
}
