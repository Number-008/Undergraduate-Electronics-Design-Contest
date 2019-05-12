/*
 * lcd.h
 *
 *  Created on: 2013-6-29
 *      Author: qin
 */

#ifndef LCD_H_
#define LCD_H_
#include "my_types.h"
#define		W_CMD		0xf8
#define		W_DAT		0xfa

void LCDInit(void);
void LCD_ShowString(u8 row,u8 col,char *str);
void LCD_ShowChar(u8 row,u8 col,u8 c);

#endif /* LCD_H_ */
