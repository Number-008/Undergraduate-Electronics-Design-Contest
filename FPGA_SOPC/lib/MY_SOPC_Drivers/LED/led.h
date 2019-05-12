/*
 * led.h
 * IP��ʹ�þ�̬��ַ���뷽ʽ
 * led�ƣ�1--��0---��
 * ��lEDʱ��һ�ζ�ȫ����LED��Ҫ����ĳ��LEDʱ���ƾ����ˣ��� LED1=(~LED1)>>1;
 * �����Լ���ϰ��ѡ�����
 *  Created on: 2013-1-23
 *  Author: qin
 */
#ifndef LED_H_
#define LED_H_
#include "system.h"
#include "io.h"

#define LED_addr LED_BASE



//#define Use_IOWR

// �ܽŲ���, ����HDL��д
#define LED_addr LED_BASE
#define RD_LED          IORD(LED_addr, 0)
#define WR_LED(data) 	IOWR(LED_addr,0,data)//���߿��ƣ�DATA��0~0xf;
#define WR_LED0(data) 	IOWR(LED_addr,1,data)//�������Ƶ�һ����,DATA:0~0x01
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

#define CPU_Use_Data_Master//�����ݸ��ٻ��壿��û����ע�͵������

#ifdef  CPU_Use_Data_Master
//�����ݸ��ٻ���ʱ
//#define LED  *(volatile unsigned long *)(LED_addr | (1 << 31))        //���߿��ƣ�ʹ�þ�̬��ַ���뷽ʽ
//#define LED0 *(volatile unsigned long *)((LED_addr+0x04) | (1 << 31))//�������Ƶ�1����
//#define LED1 *(volatile unsigned long *)((LED_addr+0x08) | (1 << 31))//�������Ƶ�2����
//#define LED2 *(volatile unsigned long *)((LED_addr+0x0c) | (1 << 31))//�������Ƶ�3����
//#define LED3 *(volatile unsigned long *)((LED_addr+0x10) | (1 << 31))//�������Ƶ�4����
#define LED(n) *(volatile unsigned long *)((LED_addr+4*n) | (1 << 31))//�������Ƶ�n����

#else
//û�����ݸ��ٻ���ʱ
//#define LED  *(volatile unsigned char *) LED_addr  //����LED�����ַ��ַ��ʹ�þ�̬��ַ���뷽ʽ
//#define LED0 *(volatile unsigned char *) LED_addr+0x04
//#define LED1 *(volatile unsigned char *) LED_addr+0x08
//#define LED2 *(volatile unsigned char *) LED_addr+0x0c
//#define LED3 *(volatile unsigned char *) LED_addr+0x10
#define LED(n) *(volatile unsigned char *) LED_addr+4*n
#endif

//ȡ��ĳ����,n>=1
#define NOT_LED(n) LED(n)=~LED(n)>>(n-1)

#endif


#endif /* LED_H_ */
