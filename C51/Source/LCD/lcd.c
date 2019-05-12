#include"lcd.h"	
void LCD_Init(void)//LCD初始化
{
	#if (LCD_CONTROLLER == 1602)
    LCD_CW=0x0c;			//00001100,开显示，不显示光标，光标不闪烁/
	WHILE_BUSY;				//忙等待/
	LCD_CW=0x38;	 		//设置16×2显示，5×7点阵，8位数据接口
	WHILE_BUSY;
	LCD_CW=0x01;
	#endif 
 
	#if (LCD_CONTROLLER == 12864)
	WHILE_BUSY;
    LCD_CW=0x30;
	WHILE_BUSY;
    LCD_CW=0x30;
	WHILE_BUSY;
    LCD_CW=0x0c;
	WHILE_BUSY;
    LCD_CW=0x10;
	WHILE_BUSY;
    LCD_CW=0x01;
	WHILE_BUSY;
    LCD_CW=0x06;
	#endif
}
//#if (LCD_CONTROLLER == 1602)
//void LCD_ShowChar(u8 addr,u8 dat)     //LCD字符输出
//{
//    WHILE_BUSY;				//忙等待，不能少！！！/
//	LCD_CW = 0x80 | addr;	//向LCD写入地址，数据指针初始地址为0x80/
//    WHILE_BUSY;				//忙等待/
//	LCD_DW = dat;			//向LCD写入数据/		
//}
//
//void LCD_WriteData(u8 dat)
//{
//    WHILE_BUSY;				//忙等待/
//	LCD_DW = dat;			//向LCD写入数据/		
//}
//#endif 
void LCD_ShowString(u8 x,u8 y, u8 *str)//LCD字符串输出	,x--列，y--行
{
    WHILE_BUSY;

	#if (LCD_CONTROLLER == 1602)	
	if(y==1)							//忙等待，不能少！！！/
	LCD_CW = 0x80 | x;
	else	
	LCD_CW = 0xc0 | x;					//向LCD写入地址，数据指针初始地址为0x80/
	#endif

	#if (LCD_CONTROLLER == 12864)
    switch(y)
    {
        case 1:LCD_CW=0x80 | x; break;
        case 2:LCD_CW=0x90 | x; break;
        case 3:LCD_CW=0x88 | x; break;
        case 4:LCD_CW=0x98 | x; break;
    }
	#endif

	while(*str!='\0')					//写到字符串结束/
	{
         WHILE_BUSY;					//忙等待/
	     LCD_DW=*str;					//向LCD写入数据/
		 str++;							//写下一个字符/
	}

}

