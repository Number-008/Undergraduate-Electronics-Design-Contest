#include "msp430G2553.h"
#include "lcd.h"
#include "spi.h"

char DisBuf1[17]="                ";
char DisBuf2[17]="                ";
char DisBuf3[17]="                ";
char DisBuf4[17]="                ";

/**********************************************************************************************************
函数名称：LCDWrite()
函数功能：LCD接口向串行总线发送数据。
入口参数：type		发送的数据类型
          dat		待发送的数据
出口参数：无
**********************************************************************************************************/
void  LCDWrite(u8 type,u8 dat)
{
	SpiSetCK(1);
   	P2OUT |= BIT0;//P1.0高电平即CS拉高
   	SpiWriteDat(type);
   	//__delay_cycles(5);
   	SpiWriteDat(dat & 0xf0);
   	//__delay_cycles(5);
   	SpiWriteDat((dat & 0x0f)<<4);
   	//__delay_cycles(5);
	P2OUT &= ~BIT0;//CS拉低
}

/**********************************************************************************************************
* 函数名称：LCDInit
* 函数功能：初始化LCD
**********************************************************************************************************/
void LCDInit(void)
{
	P2DIR |=BIT0;//输出 P2.0--RS;
	LCDWrite(W_CMD,0x30);
	LCDWrite(W_CMD,0x30);
	LCDWrite(W_CMD,0x0c);
	LCDWrite(W_CMD,0x10);
	LCDWrite(W_CMD,0x01);
	LCDWrite(W_CMD,0x06);
	__delay_cycles(50000);
	DisBuf1[16]='\0';
	DisBuf2[16]='\0';
	DisBuf3[16]='\0';
	DisBuf4[16]='\0';
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

void RefDis(void)
{
	LCD_ShowString(1,1,DisBuf1);
	LCD_ShowString(1,2,DisBuf2);
	LCD_ShowString(1,3,DisBuf3);
	LCD_ShowString(1,4,DisBuf4);
}
