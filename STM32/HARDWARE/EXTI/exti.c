#include "exti.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "beep.h"

//�ⲿ�ж�0�������
void EXTIX_Init(void)
{
 
 	EXTI_InitTypeDef EXTI_InitStructure;
 	NVIC_InitTypeDef NVIC_InitStructure;

    KEY_Init();	 //	�����˿ڳ�ʼ��

  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//ʹ�ܸ��ù���ʱ��

  	//GPIOA.0 �ж����Լ��жϳ�ʼ������   �½��ش���  //KEY0 PA0  WK_UP
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0 | GPIO_PinSource8);

  	EXTI_InitStructure.EXTI_Line=EXTI_Line0 | EXTI_Line8;	
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���

    //GPIOC.13	  �ж����Լ��жϳ�ʼ������ �½��ش��� //KEY1  
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource13);
	EXTI_InitStructure.EXTI_Line = EXTI_Line13;
	EXTI_Init(&EXTI_InitStructure);
    //GPIOA.8	  �ж����Լ��жϳ�ʼ������ �½��ش��� //KEY2  
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource8);
//	EXTI_InitStructure.EXTI_Line = EXTI_Line8;
//	EXTI_Init(&EXTI_InitStructure);
  	//GPIOD.3	  �ж����Լ��жϳ�ʼ������ �½��ش��� //KEY3
 	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource3); 
 	EXTI_InitStructure.EXTI_Line=EXTI_Line3;
  	EXTI_Init(&EXTI_InitStructure);		//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���

  	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;				//ʹ�ܰ���WK_UP���ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2�� 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;			//�����ȼ�0
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//ʹ���ⲿ�ж�ͨ��
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

	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;				//ʹ�ܰ���KEY3���ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;			//�����ȼ�3 
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure);  	  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���
}

//�ⲿ�ж�0������� 
void EXTI0_IRQHandler(void)
{
	delay_ms(10);//����
	if(KEY0==0)	 	 //WK_UP����
	{				 
		BEEP=!BEEP;
		LED0=!LED0;	
	}
	EXTI_ClearITPendingBit(EXTI_Line0); //���LINE0�ϵ��жϱ�־λ  
}
 
//�ⲿ�ж�15~10�������
void EXTI15_10_IRQHandler(void)
{
	delay_ms(10);//����
	if(KEY1==0)	 //����KEY1
	{
		LED1=!LED1; 
	}
	EXTI_ClearITPendingBit(EXTI_Line13);  //���LINE8�ϵ��жϱ�־λ  
}

//�ⲿ�ж�9~5�������
void EXTI9_5_IRQHandler(void)
{
	delay_ms(10);//����
	if(KEY2==0)	 //����KEY2
	{
		LED2=!LED2; 
	}
	EXTI_ClearITPendingBit(EXTI_Line8);  //���LINE8�ϵ��жϱ�־λ  
}

//�ⲿ�ж�3�������
void EXTI3_IRQHandler(void)
{
	delay_ms(10);//����
	if(KEY3==0)	 //����KEY3
	{
		LED3=!LED3; 
	}		 
	EXTI_ClearITPendingBit(EXTI_Line3);  //���LINE3�ϵ��жϱ�־λ  
}
