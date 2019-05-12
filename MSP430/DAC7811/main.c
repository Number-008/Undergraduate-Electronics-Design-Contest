#include "msp430G2553.h"
#include "lcd.h"
#include "key.h"
#include  "DAC7811.h"
void main (void)
{
	u16 i;
	WDTCTL = WDTPW+WDTHOLD; //¹Ø¿´ÃÅ¹·
	BCSCTL1 = CALBC1_16MHZ;                   // Set range
	DCOCTL = CALDCO_16MHZ;                    // Set DCO step + modulation*/
    LCDInit();
    for(i=0;i<5000;i++);
    KeyInit();
    Init_7811();
    LCD_ShowString(1,1,"MSP430G2553");
    _BIS_SR(LPM4_bits + GIE);    // Enter LPM4 w/interrupt

}

