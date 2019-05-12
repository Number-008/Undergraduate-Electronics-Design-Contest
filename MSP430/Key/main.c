#include "msp430G2553.h"
#include "lcd.h"
#include "key.h"

void main (void)
{
	u16 i;
	WDTCTL = WDTPW+WDTHOLD; //关看门狗
	BCSCTL1 = CALBC1_16MHZ;                   // Set range
	DCOCTL = CALDCO_16MHZ;                    // Set DCO step + modulation*/
	P1DIR |=BIT6;
	P1OUT |= BIT6;
    LCDInit();
    for(i=0;i<5000;i++);
    KeyInit();
    LCD_ShowString(1,1,"MSP430G2553");
    LCD_ShowString(2,1,"MSP430-LaunchPad");
    LCD_ShowString(3,1,"全国大学生电子设");
    LCD_ShowString(4,1,"计竞赛  ——2013");
    _BIS_SR(LPM4_bits + GIE);    // Enter LPM4 w/interrupt

}

