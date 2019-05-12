#include "msp430G2553.h"
#include "lcd.h"
#include "my_types.h"
u8 x;

void main (void)
{
	u16 i;
	x=0;
	WDTCTL = WDTPW+WDTHOLD; //关看门狗
	BCSCTL1 = CALBC1_16MHZ;                   // Set range
	DCOCTL = CALDCO_16MHZ;                    // Set DCO step + modulation*/
	P1DIR &=~BIT3;
	P1REN |=BIT3;// P1.3 pullup；
	P1IES |= BIT3;
	P1IFG &= ~BIT3;
	P1IE |= BIT3;
    LCDInit();
    for(i=0;i<5000;i++);
    LCD_ShowString(1,1,"MSP430G2553");
    LCD_ShowString(2,1,"MSP430-LaunchPad");
    LCD_ShowString(3,1,"全国大学生电子设");
    LCD_ShowString(4,1,"计竞赛  ——2013");
    _BIS_SR(LPM4_bits + GIE);    // Enter LPM4 w/interrupt
}

// Port 1 interrupt service routine
#pragma vector=PORT1_VECTOR			//中断向量声明
__interrupt void  Port_1(void)
{
	unsigned char PushKey;
	PushKey=P1IFG & BIT3;
	 __delay_cycles(10000);
	if((P1IN & PushKey)==PushKey)
	{
		P1IFG = 0x00;return;
	}
	if(PushKey & BIT3)                //若P1.3被按下
	{
		x++;
		if(x>9) x=0;
		LCD_ShowChar(1,8,0x30+x);
	}
	P1IFG = 0x00;                   //清除中断标志位
	return;                           //退出中断程序
}
