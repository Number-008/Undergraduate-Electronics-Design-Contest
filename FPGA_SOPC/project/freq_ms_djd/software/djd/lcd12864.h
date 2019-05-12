#ifndef LCD12864_H_
#define LCD12864_H_
#include "system.h" 
#include "alt_types.h"
#include <io.h>
#include <sys/unistd.h>

#define SET_E          IOWR(LCD1602_BASE,0,1)
#define CLR_E          IOWR(LCD1602_BASE,0,0)
#define SET_RW         IOWR(LCD1602_BASE,1,1)
#define CLR_RW         IOWR(LCD1602_BASE,1,0)
#define SET_RS         IOWR(LCD1602_BASE,2,1)
#define CLR_RS         IOWR(LCD1602_BASE,2,0)
#define WR_DATA(data)  IOWR(LCD1602_BASE,3,data)
#define RD_REG         IORD(LCD1602_BASE,3)

void LCD_WriteCom(alt_u8 com);
void LCD_WriteData(alt_u8 data);
void LCD_Init(void);						//LCD初始化
void LCD_ShowString(alt_u8 x,alt_u8 y,char *str);	//LCD字符串输出	,x--行，y--列

#endif /*LCD12864_H_*/
