#ifndef __ILI9320_H
#define __ILI9320_H
#include "alt_types.h"
#include "system.h"
#include <stdlib.h>
#include "io.h"

#define	USE_uCGUI (0)	 /*1---使用uCGUI  0---不使用uCGUI*/

//地址A1A0:10--写指令，11写数据，00控制背光灯;读时：A0=1读数据，A0=0读寄存器
#define LCD_LED(data) 		IOWR(SSD1298_BASE,0, data)
#define WriteREG(data) 		IOWR(SSD1298_BASE,2, data)
#define WriteRAM(data) 		IOWR(SSD1298_BASE,3, data)
#define ReadREG 			IORD(SSD1298_BASE,0)
#define ReadRAM 			IORD(SSD1298_BASE,1)

//LCD重要参数集
typedef struct  
{										    
	alt_u16 width;			//LCD 宽度
	alt_u16 height;			//LCD 高度
	alt_u16 id;				//LCD ID
	alt_u8  oir;			//横屏还是竖屏控制：0，竖屏；1，横屏。
}_lcd_dev; 	  
//LCD参数
extern _lcd_dev lcddev;	//管理LCD重要参数


//////////////////////////////////////////////////////////////////////////////////
//画笔颜色
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE         	 0x001F  
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 //棕色
#define BRRED 			 0XFC07 //棕红色
#define GRAY  			 0X8430 //灰色
//GUI颜色

#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色
//以上三色为PANEL的颜色 
 
#define LIGHTGREEN     	 0X841F //浅绿色
//#define LIGHTGRAY        0XEF5B //浅灰色(PANNEL)
#define LGRAY 			 0XC618 //浅灰色(PANNEL),窗体背景色

#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)
	    															  
void ili9320_Initializtion(void);											//初始化
void ili9320_Clear(alt_u16 Color);	 											//清屏
void ili9320_SetCursor(alt_u16 Xpos, alt_u16 Ypos);									//设置光标
void ili9320_SetPoint(alt_u16 x,alt_u16 y,alt_u16 color);										//画点
alt_u16  ili9320_GetPoint(alt_u16 x,alt_u16 y); 										//读点
void ili9320_Display_Oir(alt_u8 dir);											//设置屏幕显示方向
void ili9320_Fill(alt_u16 StartX,alt_u16 StartY,alt_u16 EndX,alt_u16 EndY,alt_u16 color);		//填充单色
void ili9320_SetWindows(alt_u16 StartX,alt_u16 StartY,alt_u16 EndX,alt_u16 EndY);		 	//设置窗口区域
alt_u16 ili9320_BGR2RGB(alt_u16 c);
void delay_ms(alt_u16 n);


/*如果使用了uCGUI 就不用编译以下代码了*/
#if (USE_uCGUI==0)
void ili9320_DrawCircle(alt_u16 x0,alt_u16 y0,alt_u8 r,alt_u16 color);							//画圆
void ili9320_DrawLine(alt_u16 x1, alt_u16 y1, alt_u16 x2, alt_u16 y2,alt_u16 color);						//画线
void ili9320_DrawLine2(alt_u16 x1, alt_16 y1, alt_u16 x2, alt_16 y2,alt_u16 color);
void ili9320_DrawRectangle(alt_u16 x1, alt_u16 y1, alt_u16 x2, alt_u16 y2,alt_u16 color);	   			//画矩形
void ili9320_DrawPicture(alt_u16 StartX,alt_u16 StartY,alt_u16 EndX,alt_u16 EndY,alt_u8 *pic);	//在指定座标范围显示一副图片
void ili9320_ShowChar(alt_u16 x,alt_u16 y,alt_u8 num,alt_u8 size,alt_u8 mode,alt_u16  POINT_COLOR,alt_u16  BACK_COLOR);					//显示一个字符
void ili9320_ShowNum(alt_u16 x,alt_u16 y,alt_u32 num,alt_u8 len,alt_u8 size,alt_u16  POINT_COLOR,alt_u16  BACK_COLOR);  					//显示一个数字
void ili9320_ShowxNum(alt_u16 x,alt_u16 y,alt_u32 num,alt_u8 len,alt_u8 size,alt_u8 mode,alt_u16  POINT_COLOR,alt_u16  BACK_COLOR);			//显示 数字
void ili9320_ShowString(alt_u16 x,alt_u16 y,alt_u16 width,alt_u16 height,alt_u8 size,alt_u8 *p,alt_u16  POINT_COLOR,alt_u16  BACK_COLOR);	//显示一个字符串,12/16字体
#endif
 					   																			 
//9320/9325 LCD寄存器  

#define R32            0x20
#define R33            0x21
#define R34            0x22

#define R80            0x50
#define R81            0x51
#define R82            0x52
#define R83            0x53

#endif  
	 
	 



