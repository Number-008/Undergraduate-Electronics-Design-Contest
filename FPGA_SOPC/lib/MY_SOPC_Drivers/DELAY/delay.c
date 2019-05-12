/*
 * delay.c
 *
 *  Created on: 2013-7-12
 *  Author: Qin Hai Cheng
 */
#include "system.h"                             //����������Ӳ��������Ϣ
#include "altera_avalon_timer_regs.h"    		//�����ں˼Ĵ�����ӳ�䣬�ṩ�Եײ�Ӳ���ķ��Ż�����
#include "alt_types.h"                          //Altera�������������
#include "sys/alt_irq.h"						//�ж����
//#include "sys/alt_alarm.h"                    //ϵͳʱ�ӷ���ͷ�ļ�
#include "led.h"								//�Զ���LED IP��

static alt_u8 delay_flag;

//��ʱ���жϷ�����
static void Timer_interrupts(void* context, alt_u32 id)
{
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_BASE, 0x00);
    IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_BASE, 0);    //��״̬�Ĵ���
    delay_flag=0;
}

//��ʱ���жϳ�ʼ��
void Delay_Timer_Init(void)
{
	delay_flag=0;
	//��״̬��־
    IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_BASE, 0);
    //����Timer���ڣ���ʱ1s
    IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER_BASE, 100000000>>16);//32λ��ʱ���ĸ�16λ
    IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER_BASE, 0);			//32λ��ʱ���ĵ�16λ��xxxx & 0xffff
    //������ʱ�������жϣ���������0x07
    IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_BASE, 0x00);
    //ע���жϺ���
    alt_irq_register(TIMER_IRQ,0,Timer_interrupts);

}

void delay_ms(alt_u16 n)
{
	delay_flag=1;
    //����Timer���ڣ���ʱn*1ms
    IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER_BASE, n*100000>>16);//32λ��ʱ���ĸ�16λ
    IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER_BASE, 0);
    IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_BASE, 0x07);//����������ʱ��
	while(delay_flag);
}

void delay_us(alt_u16 n)
{
	delay_flag=1;
    //����Timer���ڣ���ʱn*1us
    IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER_BASE, n*100>>16);//32λ��ʱ���ĸ�16λ
    IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER_BASE, 0);
    IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_BASE, 0x07);//����������ʱ��
	while(delay_flag);
}



