#include "msp430G2553.h"
void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  BCSCTL1 = CALBC1_1MHZ;                   // Set range
  DCOCTL = CALDCO_1MHZ;
  P1DIR |= 0x01;                            // P1.0 output
  TA1CCTL0 = CCIE;                             // CCR0 interrupt enabled
  TA1CCR0 = 50000;
  TA1CTL = TASSEL_1 + MC_1+TACLR + ID_0;                  // SMCLK, contmode
  _BIS_SR(LPM0_bits + GIE);                 // Enter LPM0 w/ interrupt
}

// Timer A0 interrupt service routine
#pragma vector=TIMER1_A0_VECTOR
__interrupt void Timer_A (void)
{
  P1OUT ^= 0x01;                            // Toggle P1.0
}
/*
#include <msp430g2553.h>

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  P1DIR |= 0x01;                            // P1.0 output
  TACTL = TASSEL_2 + MC_2 + TAIE;           // SMCLK, contmode, interrupt

  _BIS_SR(LPM0_bits + GIE);                 // Enter LPM0 w/ interrupt
}

// Timer_A3 Interrupt Vector (TA0IV) handler
#pragma vector=TIMER0_A1_VECTOR
__interrupt void Timer_A(void)
{
 switch( TA0IV )
 {
   case  2: break;                          // CCR1 not used
   case  4: break;                          // CCR2 not used
   case 10: P1OUT ^= 0x01;                  // overflow
            break;
 }
}*/

/*#include  <msp430g2553.h>

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  P1DIR |= 0x01;                            // P1.0 output
  TACTL = TASSEL_1 + MC_2 + TAIE;           // ACLK£¨32KHz£©, contmode, interrupt

  _BIS_SR(LPM3_bits + GIE);                 // Enter LPM3 w/ interrupt
}

// Timer_A3 Interrupt Vector (TA0IV) handler
#pragma vector=TIMER0_A1_VECTOR
__interrupt void Timer_A(void)
{
  switch( TA0IV )
  {
    case  2:  break;                        // CCR1 not used
    case  4:  break;                        // CCR2 not used
    case 10:  P1OUT ^= 0x01;                // overflow
              break;
  }
}*/

/*#include  <msp430g2553.h>

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  P1DIR |= 0x01;                            // P1.0 output
  CCTL1 = CCIE;                             // CCR1 interrupt enabled
  CCR1 = 50000;
  TACTL = TASSEL_2 + MC_2;                  // SMCLK, Contmode

  _BIS_SR(LPM0_bits + GIE);                 // Enter LPM0 w/ interrupt
}

// Timer_A3 Interrupt Vector (TA0IV) handler
#pragma vector=TIMER0_A1_VECTOR
__interrupt void Timer_A(void)
{
  switch( TA0IV )
  {
  case  2:                                  // CCR1
    {
    P1OUT ^= 0x01;                          // Toggle P1.0
    CCR1 += 50000;                          // Add Offset to CCR1
    }
           break;
  case  4: break;                           // CCR2 not used
  case 10: break;                           // overflow not used
 }
}*/


/*
#include  <msp430g2553.h>

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  P1SEL |= 0x06;                            // P1.1 - P1.2 option select
  P1DIR |= 0x07;                            // P1.0 - P1.2 outputs
  CCTL0 = OUTMOD_4 + CCIE;                  // CCR0 toggle, interrupt enabled
  CCTL1 = OUTMOD_4 + CCIE;                  // CCR1 toggle, interrupt enabled
  TACTL = TASSEL_2 +  MC_2 + TAIE;          // SMCLK, Contmode, int enabled

  _BIS_SR(LPM0_bits + GIE);                 // Enter LPM0 w/ interrupt
}

// Timer A0 interrupt service routine
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A0 (void)
{
  CCR0 += 200;                              // Add Offset to CCR0
}

// Timer_A2 Interrupt Vector (TA0IV) handler
#pragma vector=TIMER0_A1_VECTOR
__interrupt void Timer_A1(void)
{
  switch( TA0IV )
  {
  case  2: CCR1 += 1000;                    // Add Offset to CCR1
           break;
  case 10: P1OUT ^= 0x01;                   // Timer_A3 overflow
           break;
 }
}*/
