#include "beep.h"
	   
//��ʼ��PB2Ϊ�����.��ʹ������ڵ�ʱ��		    
//��������ʼ��
void BEEP_Init(void)
{
 
 	GPIO_InitTypeDef  GPIO_InitStructure;
 	
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//ʹ��GPIOB�˿�ʱ��
 
 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;				//BEEP-->PB.2�˿�����
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		//�������
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 	//�ٶ�Ϊ50MHz
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	 				//���ݲ�����ʼ��GPIOB.2
 
 	GPIO_ResetBits(GPIOB,GPIO_Pin_2);						//���0���رշ��������

}
