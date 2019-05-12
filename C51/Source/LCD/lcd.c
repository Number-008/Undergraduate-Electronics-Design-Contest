#include"lcd.h"	
void LCD_Init(void)//LCD��ʼ��
{
	#if (LCD_CONTROLLER == 1602)
    LCD_CW=0x0c;			//00001100,����ʾ������ʾ��꣬��겻��˸/
	WHILE_BUSY;				//æ�ȴ�/
	LCD_CW=0x38;	 		//����16��2��ʾ��5��7����8λ���ݽӿ�
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
//void LCD_ShowChar(u8 addr,u8 dat)     //LCD�ַ����
//{
//    WHILE_BUSY;				//æ�ȴ��������٣�����/
//	LCD_CW = 0x80 | addr;	//��LCDд���ַ������ָ���ʼ��ַΪ0x80/
//    WHILE_BUSY;				//æ�ȴ�/
//	LCD_DW = dat;			//��LCDд������/		
//}
//
//void LCD_WriteData(u8 dat)
//{
//    WHILE_BUSY;				//æ�ȴ�/
//	LCD_DW = dat;			//��LCDд������/		
//}
//#endif 
void LCD_ShowString(u8 x,u8 y, u8 *str)//LCD�ַ������	,x--�У�y--��
{
    WHILE_BUSY;

	#if (LCD_CONTROLLER == 1602)	
	if(y==1)							//æ�ȴ��������٣�����/
	LCD_CW = 0x80 | x;
	else	
	LCD_CW = 0xc0 | x;					//��LCDд���ַ������ָ���ʼ��ַΪ0x80/
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

	while(*str!='\0')					//д���ַ�������/
	{
         WHILE_BUSY;					//æ�ȴ�/
	     LCD_DW=*str;					//��LCDд������/
		 str++;							//д��һ���ַ�/
	}

}

