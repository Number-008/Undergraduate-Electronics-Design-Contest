#include "ili9320.h"
#include "stdlib.h"
#include "font.h"
#include "unistd.h"
#include "app.h"
//管理LCD重要参数
//默认为竖屏
_lcd_dev lcddev;

void delay_ms(alt_u16 n)
{
	usleep(n*1000);
}
/*******************************************************************************
* Function Name  : LCD_WriteReg
* Description    : 写寄存器.
* Input          : - LCD_Reg: 寄存器地址
*                  - LCD_RegValue: 要写入的数据.
* Output         : None
* Return         : None
*******************************************************************************/
void LCD_WriteReg(alt_u8 LCD_Reg,alt_u16 LCD_RegValue)
{
	/* Write 16-bit Index, then Write Reg */
	WriteREG(LCD_Reg);
	/* Write 16-bit Reg */
	WriteRAM(LCD_RegValue);
}

/*******************************************************************************
* Function Name  : LCD_ReadReg
* Description    : 读寄存器
* Input          : None
* Output         : None
* Return         : LCD Register Value.
*******************************************************************************/
alt_u16 LCD_ReadReg(alt_u8 LCD_Reg)
{
  alt_u16 temp;
  /* Write 16-bit Index (then Read Reg) */
  WriteREG(LCD_Reg);
  temp = ReadRAM;

   temp = ReadRAM;
  /* Read 16-bit Reg */
  return temp;
}

/*******************************************************************************
* Function Name  : LCD_WriteRAM_Prepare
* Description    : Prepare to write to the LCD RAM.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void LCD_WriteRAM_Prepare(void)
{
	WriteREG(R34);
}

/*******************************************************************************
* Function Name  : LCD_ReadRAM
* Description    : Reads the LCD RAM.
* Input          : None
* Output         : None
* Return         : LCD RAM Value.
*******************************************************************************/
alt_u16 LCD_ReadRAM(void)
{
	alt_u16 dummy;
	/* Write 16-bit Index (then Read Reg) */
	WriteREG(R34); /* Select GRAM Reg */
	/* Read 16-bit Reg */
	dummy = ReadRAM;
	return dummy;
}

/****************************************************************************
* 名    称：ili9320_Initializtion()
* 功    能：初始化 LCD 控制器
* 入口参数：无
* 出口参数：无
* 说    明：
* 调用方法：ili9320_Initializtion();
****************************************************************************/
void ili9320_Initializtion(void)
{

	LCD_LED(0);
	LCD_WriteReg(0x0000,0x0001);
	delay_ms(50); // delay 50 ms 
	lcddev.id = LCD_ReadReg(0x0000);
	if(lcddev.id==0x8999)	   //对应的驱动IC为SSD1289
	{
		//************* Start Initial Sequence **********//
		LCD_WriteReg(0x00, 0x0001); // Start internal OSC.
		LCD_WriteReg(0x01, 0x3B3F); // Driver output control, RL=0;REV=1;GD=1;BGR=0;SM=0;TB=1
		LCD_WriteReg(0x02, 0x0600); // set 1 line inversion
		//************* Power control setup ************/
		LCD_WriteReg(0x0C, 0x0007); // Adjust VCIX2 output voltage
		LCD_WriteReg(0x0D, 0x0006); // Set amplitude magnification of VLCD63
		LCD_WriteReg(0x0E, 0x3200); // Set alternating amplitude of VCOM
		LCD_WriteReg(0x1E, 0x00BB); // Set VcomH voltage
		LCD_WriteReg(0x03, 0x6A64); // Step-up factor/cycle setting
		//************ RAM position control **********/
		LCD_WriteReg(0x0F, 0x0000); // Gate scan position start at G0.
		LCD_WriteReg(0x44, 0xEF00); // Horizontal RAM address position
		LCD_WriteReg(0x45, 0x0000); // Vertical RAM address start position
		LCD_WriteReg(0x46, 0x013F); // Vertical RAM address end position
		// ----------- Adjust the Gamma Curve ----------//
		LCD_WriteReg(0x30, 0x0000);
		LCD_WriteReg(0x31, 0x0706);
		LCD_WriteReg(0x32, 0x0206);
		LCD_WriteReg(0x33, 0x0300);
		LCD_WriteReg(0x34, 0x0002);
		LCD_WriteReg(0x35, 0x0000);
		LCD_WriteReg(0x36, 0x0707);
		LCD_WriteReg(0x37, 0x0200);
		LCD_WriteReg(0x3A, 0x0908);
		LCD_WriteReg(0x3B, 0x0F0D);
		//************* Special command **************/
		LCD_WriteReg(0x28, 0x0006); // Enable test command
		LCD_WriteReg(0x2F, 0x12EB); // RAM speed tuning
		LCD_WriteReg(0x25, 0xe000);
		LCD_WriteReg(0x26, 0x7000); // Internal Bandgap strength
		LCD_WriteReg(0x20, 0xB0E3); // Internal Vcom strength
		LCD_WriteReg(0x27, 0x0044); // Internal Vcomh/VcomL timing
		LCD_WriteReg(0x2E, 0x7E45); // VCOM charge sharing time  
		//************* Turn On display ******************/
		LCD_WriteReg(0x10, 0x0000); // Sleep mode off.
		delay_ms(30);
		LCD_WriteReg(0x11, 0x6230); // Entry mode setup. 262K type B, take care on the data bus with 16it only
		LCD_WriteReg(0x07, 0x0033); // Display ON	*/
	}	
	delay_ms(50);
	ili9320_Display_Oir(1);		 	//默认为横屏
	LCD_LED(1);					//点亮背光
	ili9320_Clear(WHITE);

} 
/****************************************************************************
* 名    称：ili9320_Clear(alt_u16 color)
* 功    能：将屏幕填充成指定的颜色，如清屏，则填充 0xffff
* 入口参数：color      填充值
* 出口参数：无
* 说    明：
* 调用方法：ili9320_Clear(0xffff);
****************************************************************************/
void ili9320_Clear(alt_u16 color)
{
  alt_u32 index=0;
  ili9320_SetCursor(0,0); 
  LCD_WriteRAM_Prepare(); /* Prepare to write GRAM */
  for(index=0;index<76800;index++)
  {
	  WriteRAM(color);
  }
}
/*******************************************************************************
* Function Name  : ili9320_Display_Oir(alt_u8 oir)
* Description    : 设置LCD显示方向
* Input          : oir:0,竖屏；1,横屏
* Output         : None
* Return         : None
*******************************************************************************/
void ili9320_Display_Oir(alt_u8 oir)
{
	if(oir)
	{
		/*横屏*/
		lcddev.oir=1;
		lcddev.width=319;
		lcddev.height=239;	
	}else
	{
	   	/*竖屏*/
		lcddev.oir=0;
		lcddev.width=239;
		lcddev.height=319;
	}

}
/*******************************************************************************
* Function Name  : ili9320_SetCursor
* Description    : Sets the cursor position.
* Input          : - Xpos: specifies the X position.
*                  - Ypos: specifies the Y position. 
* Output         : None
* Return         : None
*******************************************************************************/
void ili9320_SetCursor(alt_u16 Xpos, alt_u16 Ypos)
{
 	if(lcddev.id==0x8999)
	{	
		if(lcddev.oir)
		{	
			/*横屏*/                                                                                                                                                                                          
			LCD_WriteReg(0x004E, 239-Ypos);
			LCD_WriteReg(0X004F, Xpos);

		}else
		{
		  	/*竖屏*/                                                                     
			LCD_WriteReg(0x004E, Xpos);
			LCD_WriteReg(0X004F, Ypos);
		}
	}else 
	{
		if(lcddev.oir)
		{	
			/*竖屏*/
			LCD_WriteReg(R32, Xpos);
			LCD_WriteReg(R33, Ypos);
		}else
		{
			/*横屏*/
			LCD_WriteReg(R32, Ypos);
			LCD_WriteReg(R33, 319-Xpos);
		}
	}
}

/****************************************************************************
* 名    称：alt_u16 ili9320_BGR2RGB(alt_u16 c)
* 功    能：RRRRRGGGGGGBBBBB 改为 BBBBBGGGGGGRRRRR 格式
* 入口参数：c      BRG 颜色值
* 出口参数：RGB 颜色值
* 说    明：内部函数调用
* 调用方法：
****************************************************************************/
alt_u16 ili9320_BGR2RGB(alt_u16 c)
{
	alt_u16  r,g,b,rgb;
	b=(c>>0)&0x1f;
	g=(c>>5)&0x3f;
	r=(c>>11)&0x1f;	 
	rgb=(b<<11)+(g<<5)+(r<<0);		 
	return(rgb);
} 
/****************************************************************************
* 名    称：void ili9320_SetWindows(alt_u16 StartX,alt_u16 StartY,alt_u16 EndX,alt_u16 EndY)
* 功    能：设置窗口区域
* 入口参数：StartX     行起始座标
*           StartY     列起始座标
*           EndX       行结束座标
*           EndY       列结束座标
* 出口参数：无
* 说    明：
* 调用方法：ili9320_SetWindows(0,0,100,100)；
****************************************************************************/
__inline void ili9320_SetWindows(alt_u16 StartX,alt_u16 StartY,alt_u16 EndX,alt_u16 EndY)
{
	if(lcddev.id==0x8999)
  	{
		//设置图片显示窗口大小
		LCD_WriteReg(0x44,StartX|EndX<<8);  //设置水平方向GRAM起始地址(低字节为起始地址，高字节为结束地址)
		LCD_WriteReg(0x45,StartY);		    //设置窗口的Y方向的开始位置
		LCD_WriteReg(0x46,EndY);			//设置窗口的Y方向的结束位置
  	}else 
	{										
		LCD_WriteReg(R80, StartX); 			//水平方向GRAM起始地址
		LCD_WriteReg(R81, EndX); 			//水平方向GRAM结束地址
		LCD_WriteReg(R82, StartY);			//垂直方向GRAM起始地址
		LCD_WriteReg(R83, EndY);			//垂直方向GRAM结束地址	
	}
	ili9320_SetCursor(StartX,StartY);

}
/****************************************************************************
* 名    称：void ili9320_Fill(alt_u16 StartX,alt_u16 StartY,alt_u16 EndX,alt_u16 EndY,alt_u16 color)
* 功    能：在指定区域内填充单个颜色
* 入口参数：(sx,sy),(ex,ey):填充矩形对角坐标,区域大小为:(ex-sx+1)*(ey-sy+1)   
*			color:要填充的颜色
* 出口参数：无
* 说    明：
* 调用方法：
****************************************************************************/
void ili9320_Fill(alt_u16 StartX,alt_u16 StartY,alt_u16 EndX,alt_u16 EndY,alt_u16 color)
{                   
    alt_u32 n;
    alt_u8 temp=0;
	//设置窗口
	if(lcddev.oir)
	{	
		lcddev.oir=0;
	   	//ili9320_SetWindows(StartY,319-EndX,EndY,319-StartX);
		ili9320_SetWindows(239-EndY,StartX,239-StartY,EndX);
	   	temp=1;

	}else
	{
		ili9320_SetWindows(StartX,StartY,EndX,EndY);
	}
	//ili9320_SetCursor(StartX,StartY);
	LCD_WriteRAM_Prepare();  //开始写入GRAM		   	   
	n=(alt_u32)(EndY-StartY+1)*(EndX-StartX+1);
	while(n--) WriteRAM(color);//显示所填充的颜色
	//恢复设置
	ili9320_SetWindows(0,0,239,319);
	lcddev.oir=temp;
}    
/****************************************************************************
* 名    称：alt_u16 LCD_ReadPoint(alt_u16 x,alt_u16 y)
* 功    能：获取指定座标的颜色值
* 入口参数：x      行座标
*           y      列座标
* 出口参数：当前座标颜色值
* 说    明：
* 调用方法：i=LCD_ReadPoint(10,10);
****************************************************************************/
alt_u16 ili9320_GetPoint(alt_u16 x,alt_u16 y)
{
 	//if(x>=lcddev.width||y>=lcddev.height)return 0;	//超过了范围,直接返回		   
	ili9320_SetCursor(x,y);	
	return (ili9320_BGR2RGB(LCD_ReadRAM()));
}

/*****************************************************************************
** 函数名称: ili9320_SetPoint
** 功能描述: 写一个点
** 入口参数：x      行座标
**           y      列座标
** 出口参数：
** 说    明：
*****************************************************************************/
__inline void ili9320_SetPoint(alt_u16 x,alt_u16 y,alt_u16 color)
{
	if ( (x>320)||(y>240) ) return;
	ili9320_SetCursor(x,y);		//设置光标位置 
	LCD_WriteRAM_Prepare();//开始写入GRAM
	WriteRAM(color);
}
__inline void ili9320_SetPoint2(alt_u16 x,alt_u16 y,alt_u16 color)
{
	if ((x<10)||(x>310)||(y<20 )||(y>220) ) return;
	ili9320_SetCursor(x,y);		//设置光标位置
	LCD_WriteRAM_Prepare();//开始写入GRAM
	WriteRAM(color);

}
//------------------------------------------------------------------------------------------------------------------
#if (USE_uCGUI==0)
/*****************************************************************************
** 函数名称: ili9320_DrawLine
** 功能描述: 在指定的两侧位置画一条线
**				x1,y1:起点坐标度  x2,y2:终点坐标 
** 出口参数：
** 说    明：
*****************************************************************************/ 
void ili9320_DrawLine(alt_u16 x1, alt_u16 y1, alt_u16 x2, alt_u16 y2,alt_u16 color)
{
	alt_u16 t;
	int xerr=0,yerr=0,delta_x,delta_y,distance; 
	int incx,incy,uRow,uCol; 
	delta_x=x2-x1; //计算坐标增量 
	delta_y=y2-y1; 
	uRow=x1; 
	uCol=y1; 
	if(delta_x>0)incx=1; //设置单步方向 
	else if(delta_x==0)incx=0;//垂直线 
	else {incx=-1;delta_x=-delta_x;} 
	if(delta_y>0)incy=1; 
	else if(delta_y==0)incy=0;//水平线 
	else{incy=-1;delta_y=-delta_y;} 
	if( delta_x>delta_y)distance=delta_x; //选取基本增量坐标轴 
	else distance=delta_y; 
	for(t=0;t<=distance+1;t++ )//画线输出 
	{  
		//sx(uRow);
		ili9320_SetPoint(uRow,uCol,color);//画点
		xerr+=delta_x ; 
		yerr+=delta_y ; 
		if(xerr>distance) 
		{ 
			xerr-=distance; 
			uRow+=incx; 
		} 
		if(yerr>distance) 
		{ 
			yerr-=distance; 
			uCol+=incy; 
		} 
	}  
}
__inline void ili9320_DrawLine2(alt_u16 x1, alt_u16 y1, alt_u16 x2, alt_u16 y2,alt_u16 color)
{
	//if ((x1<10)||(x1>310)||(y1<20)||(y1>220) ) return;
	//if ((x2<10)||(x2>310)||(y2<20)||(y2>220) ) return;
	alt_u16 t;
	int xerr=0,yerr=0,delta_x,delta_y,distance;
	int incx,incy,uRow,uCol;
	delta_x=x2-x1; //计算坐标增量
	delta_y=y2-y1;
	uRow=x1;
	uCol=y1;
	if(delta_x>0)incx=1; //设置单步方向
	else if(delta_x==0)incx=0;//垂直线
	else {incx=-1;delta_x=-delta_x;}
	if(delta_y>0)incy=1;
	else if(delta_y==0)incy=0;//水平线
	else{incy=-1;delta_y=-delta_y;}
	if( delta_x>delta_y)distance=delta_x; //选取基本增量坐标轴
	else distance=delta_y;
	for(t=0;t<=distance+1;t++ )//画线输出
	{
		ili9320_SetPoint2(uRow,uCol,color);//画点
		xerr+=delta_x ;
		yerr+=delta_y ;
		if(xerr>distance)
		{
			xerr-=distance;
			uRow+=incx;
		}
		if(yerr>distance)
		{
			yerr-=distance;
			uCol+=incy;
		}
	}
}
//画矩形	  
//(x1,y1),(x2,y2):矩形的对角坐标
void ili9320_DrawRectangle(alt_u16 x1, alt_u16 y1, alt_u16 x2, alt_u16 y2,alt_u16 color)
{
	ili9320_DrawLine(x1,y1,x2,y1,color);
	ili9320_DrawLine(x1,y1,x1,y2,color);
	ili9320_DrawLine(x1,y2,x2,y2,color);
	ili9320_DrawLine(x2,y1,x2,y2,color);
}
//在指定位置画一个指定大小的圆
//(x,y):中心点
//r    :半径
void ili9320_DrawCircle(alt_u16 x0,alt_u16 y0,alt_u8 r,alt_u16 color)
{
	int a,b;
	int di;
	a=0;b=r;	  
	di=3-(r<<1);             //判断下个点位置的标志
	while(a<=b)
	{
		ili9320_SetPoint(x0+a,y0-b,color);             //5
 		ili9320_SetPoint(x0+b,y0-a,color);             //0
		ili9320_SetPoint(x0+b,y0+a,color);             //4
		ili9320_SetPoint(x0+a,y0+b,color);             //6
		ili9320_SetPoint(x0-a,y0+b,color);             //1
 		ili9320_SetPoint(x0-b,y0+a,color);
		ili9320_SetPoint(x0-a,y0-b,color);             //2
  		ili9320_SetPoint(x0-b,y0-a,color);             //7
		a++;
		//使用Bresenham算法画圆     
		if(di<0)di +=4*a+6;	  
		else
		{
			di+=10+4*(a-b);   
			b--;
		} 						    
	}
} 
/****************************************************************************
* 名    称：void LCD_DrawPicture(alt_u16 StartX,alt_u16 StartY,alt_u16 EndX,alt_u16 EndY,alt_u8 *pic)
* 功    能：在指定座标范围显示一副图片
* 入口参数：StartX     行起始座标
*           StartY     列起始座标
*           EndX       行结束座标
*           EndY       列结束座标
            pic        图片头指针
* 出口参数：无
* 说    明：图片取模格式为水平扫描，16位颜色模式
* 调用方法：ili9320_DrawPicture(0,0,100,100,(alt_u16*)demo);
****************************************************************************/
void ili9320_DrawPicture(alt_u16 StartX,alt_u16 StartY,alt_u16 EndX,alt_u16 EndY,alt_u8 *pic)
{
 	 alt_u32 n;
  
  	alt_u16 *bitmap = (alt_u16 *)pic;
  	alt_u8 temp=0;
  		//设置窗口
  		if(lcddev.oir)
  		{
  			lcddev.oir=0;
  		   	ili9320_SetWindows(StartY,319-EndX,EndY,319-StartX);
  		   	temp=1;

  		}else
  		{
  			ili9320_SetWindows(StartX,StartY,EndX,EndY);
  		}
	//ili9320_SetCursor(StartX,StartY);
 	LCD_WriteRAM_Prepare();
  	n=(alt_u32)(EndY-StartY+1)*(EndX-StartX+1);
	while(n--) WriteRAM(*bitmap++);
	
	//恢复设置
	ili9320_SetWindows(0,0,239,319);
}
									  
//在指定位置显示一个字符
//x,y:起始坐标
//num:要显示的字符:" "--->"~"
//size:字体大小 12/16
//mode:叠加方式(1)还是非叠加方式(0)
void ili9320_ShowChar(alt_u16 x,alt_u16 y,alt_u8 num,alt_u8 size,alt_u8 mode,alt_u16  POINT_COLOR,alt_u16  BACK_COLOR)
{  							  
    alt_u8 temp,t1,t;
	alt_u16 y0=y;
	alt_u16 colortemp=POINT_COLOR;
	//设置窗口		   
	num=num-' ';//得到偏移后的值
	if(!mode) //非叠加方式
	{
	    for(t=0;t<size;t++)
	    {   
			if(size==12)temp=asc2_1206[num][t];  //调用1206字体
			else temp=asc2_1608[num][t];		 //调用1608字体 	                          
	        for(t1=0;t1<8;t1++)
			{			    
		        if(temp&0x80)POINT_COLOR=colortemp;
				else POINT_COLOR=BACK_COLOR;
				ili9320_SetPoint(x,y,POINT_COLOR);	
				temp<<=1;
				y++;
				if(x>=lcddev.width){POINT_COLOR=colortemp;return;}//超区域了
				if((y-y0)==size)
				{
					y=y0;
					x++;
					if(x>=lcddev.width){POINT_COLOR=colortemp;return;}//超区域了
					break;
				}
			}  	 
	    }    
	}else//叠加方式
	{
	    for(t=0;t<size;t++)
	    {   
			if(size==12)temp=asc2_1206[num][t];  //调用1206字体
			else temp=asc2_1608[num][t];		 //调用1608字体 	                          
	        for(t1=0;t1<8;t1++)
			{			    
		        if(temp&0x80)ili9320_SetPoint(x,y,POINT_COLOR); 
				temp<<=1;
				y++;
				if(x>=lcddev.height){POINT_COLOR=colortemp;return;}//超区域了
				if((y-y0)==size)
				{
					y=y0;
					x++;
					if(x>=lcddev.width){POINT_COLOR=colortemp;return;}//超区域了
					break;
				}
			}  	 
	    }     
	}
	POINT_COLOR=colortemp;	    	   	 	  
}   
//m^n函数
//返回值:m^n次方.
alt_u32 ili9320_Pow(alt_u8 m,alt_u8 n)
{
	alt_u32 result=1;
	while(n--)result*=m;    
	return result;
}			 
//显示数字,高位为0,则不显示
//x,y :起点坐标	 
//len :数字的位数
//size:字体大小
//color:颜色 
//num:数值(0~4294967295);	 
void ili9320_ShowNum(alt_u16 x,alt_u16 y,alt_u32 num,alt_u8 len,alt_u8 size,alt_u16  POINT_COLOR,alt_u16  BACK_COLOR)
{         	
	alt_u8 t,temp;
	alt_u8 enshow=0;
	for(t=0;t<len;t++)
	{
		temp=(num/ili9320_Pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				ili9320_ShowChar(x+(size/2)*t,y,' ',size,0,POINT_COLOR,BACK_COLOR);
				continue;
			}else enshow=1; 
		 	 
		}
	 	ili9320_ShowChar(x+(size/2)*t,y,temp+'0',size,0,POINT_COLOR,BACK_COLOR);
	}
} 
//显示数字,高位为0,还是显示
//x,y:起点坐标
//num:数值(0~999999999);	 
//len:长度(即要显示的位数)
//size:字体大小
//mode:
//[7]:0,不填充;1,填充0.
//[6:1]:保留
//[0]:0,非叠加显示;1,叠加显示.
void ili9320_ShowxNum(alt_u16 x,alt_u16 y,alt_u32 num,alt_u8 len,alt_u8 size,alt_u8 mode,alt_u16  POINT_COLOR,alt_u16  BACK_COLOR)
{  
	alt_u8 t,temp;
	alt_u8 enshow=0;
	for(t=0;t<len;t++)
	{
		temp=(num/ili9320_Pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				if(mode&0X80)ili9320_ShowChar(x+(size/2)*t,y,'0',size,mode&0X01,POINT_COLOR,BACK_COLOR);
				else ili9320_ShowChar(x+(size/2)*t,y,' ',size,mode&0X01,POINT_COLOR,BACK_COLOR);
 				continue;
			}else enshow=1; 
		 	 
		}
	 	ili9320_ShowChar(x+(size/2)*t,y,temp+'0',size,mode&0X01,POINT_COLOR,BACK_COLOR);
	}
} 
//显示字符串
//x,y:起点坐标
//width,height:区域大小  
//size:字体大小
//*p:字符串起始地址		  
void ili9320_ShowString(alt_u16 x,alt_u16 y,alt_u16 width,alt_u16 height,alt_u8 size,alt_u8 *p,alt_u16  POINT_COLOR,alt_u16  BACK_COLOR)
{         
	alt_u8 x0=x;
	width+=x;
	height+=y;
    while((*p<='~')&&(*p>=' '))//判断是不是非法字符!
    {       
        if(x>=width){x=x0;y+=size;}
        if(y>=height)break;//退出
        ili9320_ShowChar(x,y,*p,size,0,POINT_COLOR,BACK_COLOR);
        x+=size/2;
        p++;
    }  
}

#endif
