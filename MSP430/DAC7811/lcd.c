#include "msp430G2553.h"
#include "lcd.h"


/**********************************************************************************************************
函数名称：LCDWrite()
函数功能：LCD接口向串行总线发送数据。
入口参数：type		发送的数据类型
          dat		待发送的数据
出口参数：无
**********************************************************************************************************/
void  LCDWrite(u8 type,u8 dat)
{
   	unsigned char i,j;
	unsigned long d,s_dat;//一次发送的24位数据

	d = type;//发送数据类型 是写指令f8、数据fa、读指令fc、读数据fe
	d <<= 8;
	d |= dat & 0xf0;
	d <<= 8;
	d |= (dat & 0x0f) << 4;	//组合24位

   	P2OUT |= BIT0;//P1.0高电平即CS拉高

        for(i = 0;i < 24;i ++)
	{
		s_dat = (d & 0x800000);
                if(s_dat == 0x800000)
                  P2OUT |= BIT1;//P1.1为数据输出
                else
                  P2OUT &= ~BIT1;
		P2OUT &= ~BIT2;//时钟位低电平
		for(j = 0;j < 5;j ++);//延时
		P2OUT |= BIT2;//时钟位高电平
		d <<= 1; //发送数据左移一个单位
	}
	P2OUT &= ~BIT0;//CS拉低
	P2OUT &= ~BIT2;//CLK拉低
	P2OUT &= ~BIT1;//数据位SID拉低
}

/**********************************************************************************************************
* 函数名称：LCDInit
* 函数功能：初始化LCD
**********************************************************************************************************/
void LCDInit(void)
{
	P2DIR |=BIT2 + BIT1 + BIT0;//输出 P1.0--RS;P1.1--RW;P1.2--E
	LCDWrite(W_CMD,0x30);
	LCDWrite(W_CMD,0x30);
	LCDWrite(W_CMD,0x0c);
	LCDWrite(W_CMD,0x10);
	LCDWrite(W_CMD,0x01);
	LCDWrite(W_CMD,0x06);
}

/**********************************************************************************************************
* 函数名称：LCD_ShowString
* 函数功能：指定的位置显示字符串
**********************************************************************************************************/
void LCD_ShowString(u8 col,u8 row,char *str)
{
	u8 add;
	switch(row)							//计算AC
	{
		case 1:add = 0x80;break;
		case 2:add = 0x90;break;
		case 3:add = 0x88;break;
		case 4:add = 0x98;break;
		default:return;
	}
	add |= (col - 0x01);
	LCDWrite(W_CMD,add);  //设置AC
	while(*str!='\0')	  //写入数据
	{
		LCDWrite(W_DAT,*str);
		str++;
	}
}

/**********************************************************************************************************
* 函数名称：LCD_ShowChar
* 函数功能：指定的位置显示字符
**********************************************************************************************************/
void LCD_ShowChar(u8 col,u8 row,u8 c)
{
	u8 add;
	switch(row)							//计算AC
	{
		case 1:add = 0x80;break;
		case 2:add = 0x90;break;
		case 3:add = 0x88;break;
		case 4:add = 0x98;break;
		default:return;
	}
	add |= (col - 0x01);
	LCDWrite(W_CMD,add);  //设置AC
	LCDWrite(W_DAT,c);
}
