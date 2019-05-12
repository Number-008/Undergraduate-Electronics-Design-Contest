#include "led.h"
		    
//LED IO初始化
void LED_Init(void)
{
 
	 GPIO_InitTypeDef  GPIO_InitStructure;
	 	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);	 //使能PF端口时钟
		
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10;				
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	 GPIO_Init(GPIOF, &GPIO_InitStructure);					 //根据设定参数初始化GPIOF
	 GPIO_SetBits(GPIOF,GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10);					

}
 
