#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"



#define KEY0  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)	//读取按键0(WK_UP)
#define KEY1  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13)	//读取按键1
#define KEY2  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)	//读取按键2 
#define KEY3  GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_3)	//读取按键3 


#define WK_UP 	1
#define TAMPER	2
#define USER1	3
#define USER2	4

void KEY_Init(void);//IO初始化
u8 KEY_Scan(u8);  	//按键扫描函数					    
#endif
