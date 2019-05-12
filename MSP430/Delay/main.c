#include "msp430G2553.h"
#include "delay.h"
void main(void)
{
	  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
	  BCSCTL1 = CALBC1_12MHZ;                   // Set range
	  DCOCTL = CALDCO_12MHZ;
	  P1DIR |= BIT0;                            // P1.0 output
	  while(1)
	  {
		  delay_ms(500);
		  P1OUT^=BIT0;
	  }
}
