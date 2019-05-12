#include "sys.h"
#include "led.h"
#include "delay.h"
#include "beep.h"
#include "key.h"
#include "exti.h"
#include "timer.h"
#include "lcd.h"



//整个系统的初始化
void SysInit(void)
{   
  SystemInit();	 		 //时钟初始化
  delay_init();	    	 //延时函数初始化
  LED_Init();			 //led初始化
  BEEP_Init();
  NVIC_Configuration(); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
  EXTIX_Init();
  //TIM3_Int_Init(4999,7199);//10Khz的计数频率，计数到5000为500ms 
  LCD_Init();

}
 	
 int main(void)
 {
	SysInit();
	LCD_Clear(BLACK);
	LCD_Fill(50,50,250,70,GRAY);
	BACK_COLOR=GRAY;
	POINT_COLOR=BLACK;
	LCD_ShowString(80,50,200,20,12,"Window display");

	LCD_Fill(50,71,250,200,BLUE);

	POINT_COLOR=LGRAYBLUE;
	LCD_DrawLine(50,71,250,71);

	POINT_COLOR=LIGHTBLUE;
	LCD_DrawRectangle(49,49,251,201);
	LCD_DrawRectangle(48,48,252,202);
	LCD_DrawRectangle(47,47,253,203);
	LCD_SetWindows(50,71,250,200);
	BACK_COLOR=BLUE;
	POINT_COLOR=WHITE;
	LCD_ShowString(80,100,150,130,16," STM32 TFT test OK! qwertyuiop[]asdfghjkl;'zxcvbnm,./1234567890-=~!@#$%^&*()_+");
		
	 	
  	while(1) 
	{		 	      					 
		LED0=!LED0;					 
		delay_ms(1000);	
	} 
 	
}
