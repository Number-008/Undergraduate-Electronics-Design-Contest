/*
 * led.h
 * IP核使用静态地址对齐方式
 * led灯：1--灭；0---亮
 * 读lED时是一次读全部的LED，要读得某个LED时右移就行了，如 LED1=(~LED1)>>1;
 * 根据自己的习惯选择编译
 *  Created on: 2013-1-23
 *  Author: qin
 */
#ifndef LED_H_
#define LED_H_
#include "system.h"
#include "io.h"

#define LED_addr LED_BASE



//#define Use_IOWR

// 管脚操作, 根据HDL编写
#define LED_addr LED_BASE
#define RD_LED          IORD(LED_addr, 0)
#define WR_LED(data) 	IOWR(LED_addr,0,data)//总线控制，DATA：0~0xf;
#define WR_LED0(data) 	IOWR(LED_addr,1,data)//单独控制第一个灯,DATA:0~0x01
#define WR_LED1(data) 	IOWR(LED_addr,2,data)
#define WR_LED2(data) 	IOWR(LED_addr,3,data)
#define WR_LED3(data) 	IOWR(LED_addr,4,data)

#define LED0_ON		WR_LED0(0)
#define LED0_OFF	WR_LED0(1)
#define LED1_ON		WR_LED1(0)
#define LED1_OFF	WR_LED1(1)
#define LED2_ON 	WR_LED2(0)
#define LED2_OFF 	WR_LED2(1)
#define LED3_ON		WR_LED3(0)
#define LED3_OFF	WR_LED3(1)
#define NOT_LED     IOWR(LED_addr,0,~RD_LED)
#define NOT_LEDn(n)	IOWR(LED_addr,n+1,(~RD_LED)>>n)

#else

#define CPU_Use_Data_Master//开数据高速缓冲？，没开请注释掉本语句

#ifdef  CPU_Use_Data_Master
//开数据高速缓冲时
//#define LED  *(volatile unsigned long *)(LED_addr | (1 << 31))        //总线控制，使用静态地址对齐方式
//#define LED0 *(volatile unsigned long *)((LED_addr+0x04) | (1 << 31))//单独控制第1个灯
//#define LED1 *(volatile unsigned long *)((LED_addr+0x08) | (1 << 31))//单独控制第2个灯
//#define LED2 *(volatile unsigned long *)((LED_addr+0x0c) | (1 << 31))//单独控制第3个灯
//#define LED3 *(volatile unsigned long *)((LED_addr+0x10) | (1 << 31))//单独控制第4个灯
#define LED(n) *(volatile unsigned long *)((LED_addr+4*n) | (1 << 31))//单独控制第n个灯

#else
//没开数据高速缓冲时
//#define LED  *(volatile unsigned char *) LED_addr  //代表LED输出地址地址，使用静态地址对齐方式
//#define LED0 *(volatile unsigned char *) LED_addr+0x04
//#define LED1 *(volatile unsigned char *) LED_addr+0x08
//#define LED2 *(volatile unsigned char *) LED_addr+0x0c
//#define LED3 *(volatile unsigned char *) LED_addr+0x10
#define LED(n) *(volatile unsigned char *) LED_addr+4*n
#endif

//取反某个灯,n>=1
#define NOT_LED(n) LED(n)=~LED(n)>>(n-1)

#endif


#endif /* LED_H_ */
