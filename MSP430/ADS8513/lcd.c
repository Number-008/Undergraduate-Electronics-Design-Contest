#include "msp430G2553.h"
#include "lcd.h"


/**********************************************************************************************************
�������ƣ�LCDWrite()
�������ܣ�LCD�ӿ��������߷������ݡ�
��ڲ�����type		���͵���������
          dat		�����͵�����
���ڲ�������
**********************************************************************************************************/
void  LCDWrite(u8 type,u8 dat)
{
   	unsigned char i,j;
	unsigned long d,s_dat;//һ�η��͵�24λ����

	d = type;//������������ ��дָ��f8������fa����ָ��fc��������fe
	d <<= 8;
	d |= dat & 0xf0;
	d <<= 8;
	d |= (dat & 0x0f) << 4;	//���24λ

   	P1OUT |= BIT0;//P1.0�ߵ�ƽ��CS����

    for(i = 0;i < 24;i ++)
	{
		s_dat = (d & 0x800000);
        	if(s_dat == 0x800000)
                  P1OUT |= BIT1;//P1.1Ϊ�������
                else
                  P1OUT &= ~BIT1;
		P1OUT &= ~BIT2;//ʱ��λ�͵�ƽ
		for(j = 0;j < 5;j ++);//��ʱ
		P1OUT |= BIT2;//ʱ��λ�ߵ�ƽ
		d <<= 1; //������������һ����λ
	}
	P1OUT &= ~BIT0;//CS����
	P1OUT &= ~BIT2;//CLK����
	P1OUT &= ~BIT1;//����λSID����
}

/**********************************************************************************************************
* �������ƣ�LCDInit
* �������ܣ���ʼ��LCD
**********************************************************************************************************/
void LCDInit(void)
{
	P1DIR |=BIT2 + BIT1 + BIT0;//��� P1.0--RS;P1.1--RW;P1.2--E
	__delay_cycles(50);
	LCDWrite(W_CMD,0x30);
	__delay_cycles(50);
	LCDWrite(W_CMD,0x30);
	__delay_cycles(50);
	LCDWrite(W_CMD,0x0c);
	__delay_cycles(50);
	LCDWrite(W_CMD,0x10);
	__delay_cycles(50);
	LCDWrite(W_CMD,0x01);
	__delay_cycles(50);
	LCDWrite(W_CMD,0x06);
	__delay_cycles(50);
}

/**********************************************************************************************************
* �������ƣ�LCD_ShowString
* �������ܣ�ָ����λ����ʾ�ַ���
**********************************************************************************************************/
void LCD_ShowString(u8 col,u8 row,char *str)
{
	u8 add;
	switch(row)							//����AC
	{
		case 1:add = 0x80;break;
		case 2:add = 0x90;break;
		case 3:add = 0x88;break;
		case 4:add = 0x98;break;
		default:return;
	}
	add |= (col - 0x01);
	LCDWrite(W_CMD,add);  //����AC
	while(*str!='\0')	  //д������
	{
		LCDWrite(W_DAT,*str);
		str++;
	}
}

/**********************************************************************************************************
* �������ƣ�LCD_ShowChar
* �������ܣ�ָ����λ����ʾ�ַ�
**********************************************************************************************************/
void LCD_ShowChar(u8 col,u8 row,u8 c)
{
	u8 add;
	switch(row)							//����AC
	{
		case 1:add = 0x80;break;
		case 2:add = 0x90;break;
		case 3:add = 0x88;break;
		case 4:add = 0x98;break;
		default:return;
	}
	add |= (col - 0x01);
	LCDWrite(W_CMD,add);  //����AC
	LCDWrite(W_DAT,c);
}