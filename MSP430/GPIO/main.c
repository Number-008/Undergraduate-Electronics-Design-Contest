#include "msp430G2553.h"

void main(void)
{
	WDTCTL = WDTPW+WDTHOLD; //关看门狗
	BCSCTL1 = CALBC1_12MHZ;                   // Set range
	DCOCTL = CALDCO_12MHZ;                    // Set DCO step + modulation*/

	//PxDIR(IO口输入输出方向选择)：1--输出，0--输入；
	P1DIR &=~BIT3;
    P1DIR |=BIT6;
    //PxREN（IO口上下拉）：Bit = 0: Pullup/pulldown resistor disabled
    //					  Bit = 1: Pullup/pulldown resistor enabled
    P1REN |=BIT3;// P1.3 pullup；
    //PxIES(电平触发边沿) :1--下降沿触发，0--上升沿触发
    P1IES |= BIT3;
    //PxIFG（中断标志位）: 0--清除标志位
    P1IFG &= ~BIT3;
    //PxIE(中断使能):	  1--允许中断，	0--不允许中断；
    P1IE |= BIT3;

    P1OUT |= BIT6;
   _BIS_SR(LPM4_bits + GIE);    // Enter LPM4 w/interrupt
    //_EINT();//打开全局中断
   // while(1);

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
		P1OUT^=BIT6;
		//P1IFG &= ~BIT3;               //清除中断标志位
	}
	P1IFG = 0x00;                   //清除中断标志位
	return;                           //退出中断程序
}
