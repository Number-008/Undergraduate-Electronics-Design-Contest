/*
 * main.c
 */
#include "lcd.h"
#include "spi.h"
#include "ad9854.h"

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
	BCSCTL1 = CALBC1_1MHZ;                   // Set range
	DCOCTL = CALDCO_1MHZ;                    // Set DCO step + modulation*/
	SpiInit();
	LCDInit();
    Init_AD9854();
    Write_AD9854_Freq(10000000);
	while(1);

}
