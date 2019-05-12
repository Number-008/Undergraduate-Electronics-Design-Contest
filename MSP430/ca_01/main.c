/*

#include  <msp430g2553.h>

void delay(void);                           // Software delay

void main (void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  CACTL2 = P2CA4;                           // CA1/P1.1 = +comp
  CCTL0 = CCIE;                             // CCR0 interrupt enabled
  TACTL = TASSEL_2 + ID_3 + MC_2;           // SMCLK/8, cont-mode
  _EINT();                                  // enable interrupts

  while (1)                                 // Loop
  {
    CACTL1 = 0x00;                          // No reference voltage
    _BIS_SR(LPM0_bits);                     // Enter LPM0
    CACTL1 = CAREF0 + CAON;                 // 0.25*Vcc, Comp. on
    _BIS_SR(LPM0_bits);                     // Enter LPM0
    CACTL1 = CAREF1 + CAON;                 // 0.5*Vcc, Comp. on
    _BIS_SR(LPM0_bits);                     // Enter LPM0
    CACTL1 = CAREF1 + CAREF0 + CAON;        // 0.55V, Comp. on
    _BIS_SR(LPM0_bits);                     // Enter LPM0
  }
}

// Timer A0 interrupt service routine
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
{
    _BIC_SR_IRQ(LPM0_bits);                 // Clear LPM0 bits from 0(SR)
}
*/

#include <msp430g2553.h>

void main (void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  P1DIR |= 0x01;                            // P1.0 output
  CACTL1 = CARSEL + CAREF0 + CAON;          // 0.25 Vcc = -comp, on
  CACTL2 = P2CA4;                           // P1.1/CA1 = +comp

  while (1)                                 // Test comparator_A output
  {
    if ((CAOUT & CACTL2))
      P1OUT |= 0x01;                        // if CAOUT set, set P1.0
    else P1OUT &= ~0x01;                    // else reset
  }
}



