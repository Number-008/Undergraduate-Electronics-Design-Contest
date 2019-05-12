#include "msp430G2553.h"
#include "lcd.h"
#include "ads8513.h"
void main (void)
{
	WDTCTL = WDTPW+WDTHOLD; //¹Ø¿´ÃÅ¹·
	BCSCTL1 = CALBC1_1MHZ;                   // Set range
	DCOCTL = CALDCO_1MHZ;                    // Set DCO step + modulation*/

    ADS8513Init();
    LCDInit();
    __delay_cycles(50000);
    LCD_ShowString(1,1,"MSP430G2553");
    //_BIS_SR(LPM4_bits + GIE);    // Enter LPM4 w/interrupt
    while(1)
    {
    	Printf_AD();
    	 __delay_cycles(500);

    }

}

