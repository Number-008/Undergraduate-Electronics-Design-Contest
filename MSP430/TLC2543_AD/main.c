/*
 * main.c
 */
#include "lcd.h"
#include "spi.h"
#include "tlc2543.h"
#include "string.h"
void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
	BCSCTL1 = CALBC1_1MHZ;                   // Set range
	DCOCTL = CALDCO_1MHZ;                    // Set DCO step + modulation*/
	SpiInit();
	LCDInit();
	TLC2543Init();
	strcpy(DisBuf1,"TLC2543         ");
	strcpy(DisBuf2,"CH0:");
	strcpy(DisBuf3,"CH1:");
	strcpy(DisBuf4,"CH2:");
	RefDis();
	while(1)
	{
		Printf_AD(0,DisBuf2,4);
		Printf_AD(1,DisBuf3,4);
		Printf_AD(2,DisBuf4,4);
		RefDis();
	}
}

