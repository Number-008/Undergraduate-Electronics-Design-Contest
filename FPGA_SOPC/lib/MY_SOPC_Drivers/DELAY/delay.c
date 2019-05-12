/*
 * delay.c
 *
 *  Created on: 2013-7-12
 *  Author: Qin Hai Cheng
 */
#include "system.h"                             //包含基本的硬件描述信息
#include "altera_avalon_timer_regs.h"    		//定义内核寄存器的映射，提供对底层硬件的符号化访问
#include "alt_types.h"                          //Altera定义的数据类型
#include "sys/alt_irq.h"						//中断相关
//#include "sys/alt_alarm.h"                    //系统时钟服务头文件
#include "led.h"								//自定义LED IP核

static alt_u8 delay_flag;

//定时器中断服务函数
static void Timer_interrupts(void* context, alt_u32 id)
{
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_BASE, 0x00);
    IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_BASE, 0);    //清状态寄存器
    delay_flag=0;
}

//定时器中断初始化
void Delay_Timer_Init(void)
{
	delay_flag=0;
	//清状态标志
    IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_BASE, 0);
    //设置Timer周期，定时1s
    IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER_BASE, 100000000>>16);//32位定时器的高16位
    IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER_BASE, 0);			//32位定时器的低16位，xxxx & 0xffff
    //启动定时器允许中断，连续计数0x07
    IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_BASE, 0x00);
    //注册中断函数
    alt_irq_register(TIMER_IRQ,0,Timer_interrupts);

}

void delay_ms(alt_u16 n)
{
	delay_flag=1;
    //设置Timer周期，定时n*1ms
    IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER_BASE, n*100000>>16);//32位定时器的高16位
    IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER_BASE, 0);
    IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_BASE, 0x07);//重新启动定时器
	while(delay_flag);
}

void delay_us(alt_u16 n)
{
	delay_flag=1;
    //设置Timer周期，定时n*1us
    IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER_BASE, n*100>>16);//32位定时器的高16位
    IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER_BASE, 0);
    IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_BASE, 0x07);//重新启动定时器
	while(delay_flag);
}



