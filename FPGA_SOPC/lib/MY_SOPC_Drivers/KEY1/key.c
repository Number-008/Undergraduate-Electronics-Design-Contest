/*
 * key.c
 *
 *  Created on: 2013-1-24
 *      Author: qin
 */
#include "key.h"
#include "led.h"
#include "sys/alt_irq.h"
#include "unistd.h"//延时函数usleep

/********************************************************************
* 名 称：KeyDown_interrupts()
* 功 能：键按下事件中断服务子程序
* 告知外界
* 入口参数：context，一般用于传递中断状态寄存器的值，这里未使用
* id，中断号，这里未使用
* 出口参数：无
********************************************************************/
static void KeyDown_interrupts(void* context, alt_u32 id)
{
	//WR_KEY_IRQ_MASK(0x00);
	usleep(5000); //延时5ms
	/* 清中断捕获寄存器 */
	WR_KEY_EDGE_CAP(0x00);
	if(RD_KEY != 0x0f) //如果是由短暂脉冲引起的中断则忽略
	{
		switch(RD_KEY)
		{
			case 0x0e:
			{
				//while(RD_KEY == 0x0e);//等待按键释放
				NOT_LEDn(0);
			}break;
			case 0x0d:
			{

				NOT_LEDn(1);

			}break;
			case 0x0b:
			{
				NOT_LEDn(2);
			}break;
			case 0x07:
			{
				while(RD_KEY == 0x07);//等待按键释放
				NOT_LEDn(3);
			}break;
		}

	}
	//WR_KEY_IRQ_MASK(0x0f);

}
/********************************************************************
* 名 称：Init_Key()
* 功 能：初始化LED_PIO为输出，KEY为输入，开中断，清边沿捕获寄存器
* 入口参数：无
* 出口参数：无
********************************************************************/
void Init_Key(void)
{


	/* 屏蔽KEY的中断 ；1--允许，0--屏蔽*/
	WR_KEY_IRQ_MASK(0x0f);
	/* 清边沿捕获寄存器 */
	WR_KEY_EDGE_CAP(0x00);

	/* 注册中断服务子程序 */
	alt_irq_register(KEY_IRQ,0, KeyDown_interrupts);
}



