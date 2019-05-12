#include "msp430G2553.h"

void main(void)
{
	WDTCTL = WDTPW+WDTHOLD; //�ؿ��Ź�
	BCSCTL1 = CALBC1_12MHZ;                   // Set range
	DCOCTL = CALDCO_12MHZ;                    // Set DCO step + modulation*/

	//PxDIR(IO�������������ѡ��)��1--�����0--���룻
	P1DIR &=~BIT3;
    P1DIR |=BIT6;
    //PxREN��IO������������Bit = 0: Pullup/pulldown resistor disabled
    //					  Bit = 1: Pullup/pulldown resistor enabled
    P1REN |=BIT3;// P1.3 pullup��
    //PxIES(��ƽ��������) :1--�½��ش�����0--�����ش���
    P1IES |= BIT3;
    //PxIFG���жϱ�־λ��: 0--�����־λ
    P1IFG &= ~BIT3;
    //PxIE(�ж�ʹ��):	  1--�����жϣ�	0--�������жϣ�
    P1IE |= BIT3;

    P1OUT |= BIT6;
   _BIS_SR(LPM4_bits + GIE);    // Enter LPM4 w/interrupt
    //_EINT();//��ȫ���ж�
   // while(1);

}

// Port 1 interrupt service routine
#pragma vector=PORT1_VECTOR			//�ж���������
__interrupt void  Port_1(void)
{
	unsigned char PushKey;
	PushKey=P1IFG & BIT3;
	 __delay_cycles(10000);
	if((P1IN & PushKey)==PushKey)
	{
		P1IFG = 0x00;return;
	}
	if(PushKey & BIT3)                //��P1.3������
	{
		P1OUT^=BIT6;
		//P1IFG &= ~BIT3;               //����жϱ�־λ
	}
	P1IFG = 0x00;                   //����жϱ�־λ
	return;                           //�˳��жϳ���
}
