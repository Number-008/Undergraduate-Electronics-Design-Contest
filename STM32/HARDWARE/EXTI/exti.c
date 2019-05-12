#include "exti.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "beep.h"

//外部中断0服务程序
void EXTIX_Init(void)
{
 
 	EXTI_InitTypeDef EXTI_InitStructure;
 	NVIC_InitTypeDef NVIC_InitStructure;

    KEY_Init();	 //	按键端口初始化

  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//使能复用功能时钟

  	//GPIOA.0 中断线以及中断初始化配置   下降沿触发  //KEY0 PA0  WK_UP
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0 | GPIO_PinSource8);

  	EXTI_InitStructure.EXTI_Line=EXTI_Line0 | EXTI_Line8;	
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 	//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器

    //GPIOC.13	  中断线以及中断初始化配置 下降沿触发 //KEY1  
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource13);
	EXTI_InitStructure.EXTI_Line = EXTI_Line13;
	EXTI_Init(&EXTI_InitStructure);
    //GPIOA.8	  中断线以及中断初始化配置 下降沿触发 //KEY2  
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource8);
//	EXTI_InitStructure.EXTI_Line = EXTI_Line8;
//	EXTI_Init(&EXTI_InitStructure);
  	//GPIOD.3	  中断线以及中断初始化配置 下降沿触发 //KEY3
 	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource3); 
 	EXTI_InitStructure.EXTI_Line=EXTI_Line3;
  	EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器

  	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;				//使能按键WK_UP所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//抢占优先级2， 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;			//子优先级0
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//使能外部中断通道
  	NVIC_Init(&NVIC_InitStructure); 

	/* Enable the EXTI15_10 Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
 
	/* Enable the EXTI9_5 Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;				//使能按键KEY3所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//抢占优先级2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;			//子优先级3 
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//使能外部中断通道
  	NVIC_Init(&NVIC_InitStructure);  	  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
}

//外部中断0服务程序 
void EXTI0_IRQHandler(void)
{
	delay_ms(10);//消抖
	if(KEY0==0)	 	 //WK_UP按键
	{				 
		BEEP=!BEEP;
		LED0=!LED0;	
	}
	EXTI_ClearITPendingBit(EXTI_Line0); //清除LINE0上的中断标志位  
}
 
//外部中断15~10服务程序
void EXTI15_10_IRQHandler(void)
{
	delay_ms(10);//消抖
	if(KEY1==0)	 //按键KEY1
	{
		LED1=!LED1; 
	}
	EXTI_ClearITPendingBit(EXTI_Line13);  //清除LINE8上的中断标志位  
}

//外部中断9~5服务程序
void EXTI9_5_IRQHandler(void)
{
	delay_ms(10);//消抖
	if(KEY2==0)	 //按键KEY2
	{
		LED2=!LED2; 
	}
	EXTI_ClearITPendingBit(EXTI_Line8);  //清除LINE8上的中断标志位  
}

//外部中断3服务程序
void EXTI3_IRQHandler(void)
{
	delay_ms(10);//消抖
	if(KEY3==0)	 //按键KEY3
	{
		LED3=!LED3; 
	}		 
	EXTI_ClearITPendingBit(EXTI_Line3);  //清除LINE3上的中断标志位  
}
