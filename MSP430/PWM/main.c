#include "msp430G2553.h"
#include "key.h"
void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  BCSCTL1 = CALBC1_1MHZ;                   // Set range
  DCOCTL = CALDCO_1MHZ;

  TA1CTL = TASSEL0 + TACLR + MC_1; // ACLK, 清除TAR
  TA1CCR0 = 512-1; // PWM周期
  TA1CCTL1 = OUTMOD_7;
  TA1CCR1 = 128; //占空比128/512=0.25
  TA1CCTL2 = OUTMOD_7;
  TA1CCR2 = 384; //占空比384/512=0.75

  P2DIR |= BIT5+BIT2;
  P2SEL |= BIT5+BIT2;//TA1.2、TA1.1
  KeyInit();
  _BIS_SR(LPM3_bits + GIE);                 // Enter LPM0 w/ interrupt

}
