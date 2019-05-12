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


#endif /* LED_H_ */
