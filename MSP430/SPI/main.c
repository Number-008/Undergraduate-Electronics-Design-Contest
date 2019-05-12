#include "msp430g2553.h"
#include "lcd.h"
#include "spi.h"
#include"ads7818.h"
#include "tlv5638.h"
#include "key.h"
void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
	BCSCTL1 = CALBC1_1MHZ;                   // Set range
	DCOCTL = CALDCO_1MHZ;                    // Set DCO step + modulation*/
	P1DIR |=BIT5;
	P1REN |=BIT5;
	P2DIR |=BIT1;
	P2REN |=BIT1;
	SpiInit();
	LCDInit();
	KeyInit();
	TLV5638_Out(1234);
	while(1)
	{
		printf_AD();
		__delay_cycles(50000);

	}


}

