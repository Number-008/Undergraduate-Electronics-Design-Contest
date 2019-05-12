#ifndef __ILI9320_H
#define __ILI9320_H
#include "alt_types.h"
#include "system.h"
#include <stdlib.h>
#include "io.h"

#define	USE_uCGUI (0)	 /*1---ʹ��uCGUI  0---��ʹ��uCGUI*/

//��ַA1A0:10--дָ�11д���ݣ�00���Ʊ����;��ʱ��A0=1�����ݣ�A0=0���Ĵ���
#define LCD_LED(data) 		IOWR(SSD1298_BASE,0, data)
#define WriteREG(data) 		IOWR(SSD1298_BASE,2, data)
#define WriteRAM(data) 		IOWR(SSD1298_BASE,3, data)
#define ReadREG 			IORD(SSD1298_BASE,0)
#define ReadRAM 			IORD(SSD1298_BASE,1)

//LCD��Ҫ������
typedef struct  
{										    
	alt_u16 width;			//LCD ���
	alt_u16 height;			//LCD �߶�
	alt_u16 id;				//LCD ID
	alt_u8  oir;			//���������������ƣ�0��������1��������
}_lcd_dev; 	  
//LCD����
extern _lcd_dev lcddev;	//����LCD��Ҫ����


//////////////////////////////////////////////////////////////////////////////////
//������ɫ
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
#define BROWN 			 0XBC40 //��ɫ
#define BRRED 			 0XFC07 //�غ�ɫ
#define GRAY  			 0X8430 //��ɫ
//GUI��ɫ

#define DARKBLUE      	 0X01CF	//����ɫ
#define LIGHTBLUE      	 0X7D7C	//ǳ��ɫ  
#define GRAYBLUE       	 0X5458 //����ɫ
//������ɫΪPANEL����ɫ 
 
#define LIGHTGREEN     	 0X841F //ǳ��ɫ
//#define LIGHTGRAY        0XEF5B //ǳ��ɫ(PANNEL)
#define LGRAY 			 0XC618 //ǳ��ɫ(PANNEL),���屳��ɫ

#define LGRAYBLUE        0XA651 //ǳ����ɫ(�м����ɫ)
#define LBBLUE           0X2B12 //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)
	    															  
void ili9320_Initializtion(void);											//��ʼ��
void ili9320_Clear(alt_u16 Color);	 											//����
void ili9320_SetCursor(alt_u16 Xpos, alt_u16 Ypos);									//���ù��
void ili9320_SetPoint(alt_u16 x,alt_u16 y,alt_u16 color);										//����
alt_u16  ili9320_GetPoint(alt_u16 x,alt_u16 y); 										//����
void ili9320_Display_Oir(alt_u8 dir);											//������Ļ��ʾ����
void ili9320_Fill(alt_u16 StartX,alt_u16 StartY,alt_u16 EndX,alt_u16 EndY,alt_u16 color);		//��䵥ɫ
void ili9320_SetWindows(alt_u16 StartX,alt_u16 StartY,alt_u16 EndX,alt_u16 EndY);		 	//���ô�������
alt_u16 ili9320_BGR2RGB(alt_u16 c);
void delay_ms(alt_u16 n);


/*���ʹ����uCGUI �Ͳ��ñ������´�����*/
#if (USE_uCGUI==0)
void ili9320_DrawCircle(alt_u16 x0,alt_u16 y0,alt_u8 r,alt_u16 color);							//��Բ
void ili9320_DrawLine(alt_u16 x1, alt_u16 y1, alt_u16 x2, alt_u16 y2,alt_u16 color);						//����
void ili9320_DrawLine2(alt_u16 x1, alt_16 y1, alt_u16 x2, alt_16 y2,alt_u16 color);
void ili9320_DrawRectangle(alt_u16 x1, alt_u16 y1, alt_u16 x2, alt_u16 y2,alt_u16 color);	   			//������
void ili9320_DrawPicture(alt_u16 StartX,alt_u16 StartY,alt_u16 EndX,alt_u16 EndY,alt_u8 *pic);	//��ָ�����귶Χ��ʾһ��ͼƬ
void ili9320_ShowChar(alt_u16 x,alt_u16 y,alt_u8 num,alt_u8 size,alt_u8 mode,alt_u16  POINT_COLOR,alt_u16  BACK_COLOR);					//��ʾһ���ַ�
void ili9320_ShowNum(alt_u16 x,alt_u16 y,alt_u32 num,alt_u8 len,alt_u8 size,alt_u16  POINT_COLOR,alt_u16  BACK_COLOR);  					//��ʾһ������
void ili9320_ShowxNum(alt_u16 x,alt_u16 y,alt_u32 num,alt_u8 len,alt_u8 size,alt_u8 mode,alt_u16  POINT_COLOR,alt_u16  BACK_COLOR);			//��ʾ ����
void ili9320_ShowString(alt_u16 x,alt_u16 y,alt_u16 width,alt_u16 height,alt_u8 size,alt_u8 *p,alt_u16  POINT_COLOR,alt_u16  BACK_COLOR);	//��ʾһ���ַ���,12/16����
#endif
 					   																			 
//9320/9325 LCD�Ĵ���  

#define R32            0x20
#define R33            0x21
#define R34            0x22

#define R80            0x50
#define R81            0x51
#define R82            0x52
#define R83            0x53

#endif  
	 
	 



