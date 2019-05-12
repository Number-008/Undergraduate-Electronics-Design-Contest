#include "lcd.h"
#include "stdlib.h"
#include "delay.h"
#include "font.h" 
u16 POINT_COLOR=0x0000;	//画笔颜色
u16 BACK_COLOR=0xFFFF;  //背景色 
//管理LCD重要参数
//默认为竖屏
_lcd_dev lcddev;
/*******************************************************************************
* Function Name  : LCD_CtrlLinesConfig
* Description    : LCD配置设置
                   Push-Pull mode.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void LCD_Configuration(void)
{
  	GPIO_InitTypeDef GPIO_InitStructure;
	FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;
    FSMC_NORSRAMTimingInitTypeDef  readWriteTiming; 
	FSMC_NORSRAMTimingInitTypeDef  writeTiming;

	/* Enable FSMC, GPIOD, GPIOE, GPIOF, GPIOG and AFIO clocks */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE |
	                     RCC_APB2Periph_GPIOF | RCC_APB2Periph_GPIOG |
	                     RCC_APB2Periph_AFIO, ENABLE);

	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;				
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出	背光
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOF

	/* Set PD.00(D2), PD.01(D3), PD.04(NOE), PD.05(NWE), PD.08(D13), PD.09(D14),
	 PD.10(D15), PD.14(D0), PD.15(D1) as alternate 
	 function push pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 |
	                            GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_14 | 
	                            GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	/* Set PE.07(D4), PE.08(D5), PE.09(D6), PE.10(D7), PE.11(D8), PE.12(D9), PE.13(D10),
	 PE.14(D11), PE.15(D12) as alternate function push pull */
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | 
	                            GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | 
	                            GPIO_Pin_15;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	//GPIO_WriteBit(GPIOE, GPIO_Pin_6, Bit_SET);
	/* Set PF.00(A0 (RS)) as alternate function push pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init(GPIOF, &GPIO_InitStructure);
	
	/* Set PG.12(NE4 (LCD/CS)) as alternate function push pull - CE3(LCD /CS) */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_Init(GPIOG, &GPIO_InitStructure);


 	readWriteTiming.FSMC_AddressSetupTime = 0x01;	 //地址建立时间（ADDSET）为2个HCLK 1/36M=27ns
    readWriteTiming.FSMC_AddressHoldTime = 0x00;	 //地址保持时间（ADDHLD）模式A未用到	
    readWriteTiming.FSMC_DataSetupTime = 0x0f;		 // 数据保存时间为16个HCLK,因为液晶驱动IC的读数据的时候，速度不能太快，尤其对1289这个IC。
    readWriteTiming.FSMC_BusTurnAroundDuration = 0x00;
    readWriteTiming.FSMC_CLKDivision = 0x00;
    readWriteTiming.FSMC_DataLatency = 0x00;
    readWriteTiming.FSMC_AccessMode = FSMC_AccessMode_A;	 //模式A 
    

	writeTiming.FSMC_AddressSetupTime = 0x00;	 //地址建立时间（ADDSET）为1个HCLK  
    writeTiming.FSMC_AddressHoldTime = 0x00;	 //地址保持时间（A		
    writeTiming.FSMC_DataSetupTime = 0x03;		 ////数据保存时间为4个HCLK	
    writeTiming.FSMC_BusTurnAroundDuration = 0x00;
    writeTiming.FSMC_CLKDivision = 0x00;
    writeTiming.FSMC_DataLatency = 0x00;
    writeTiming.FSMC_AccessMode = FSMC_AccessMode_A;	 //模式A 

 
    FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM4;//  这里我们使用NE4 ，也就对应BTCR[6],[7]。
    FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable; // 不复用数据地址
    FSMC_NORSRAMInitStructure.FSMC_MemoryType =FSMC_MemoryType_SRAM;// FSMC_MemoryType_SRAM;  //SRAM   
    FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;//存储器数据宽度为16bit   
    FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode =FSMC_BurstAccessMode_Disable;// FSMC_BurstAccessMode_Disable; 
    FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
	FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait=FSMC_AsynchronousWait_Disable; 
    FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;   
    FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;  
    FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;	//  存储器写使能
    FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;   
    FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Enable; // 读写使用不同的时序
    FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable; 
    FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &readWriteTiming; //读写时序
    FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &writeTiming;  //写时序

    FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure);  //初始化FSMC配置

   	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM4, ENABLE);  // 使能BANK1 
}

/*******************************************************************************
* Function Name  : LCD_WriteReg
* Description    : 写寄存器.
* Input          : - LCD_Reg: 寄存器地址
*                  - LCD_RegValue: 要写入的数据.
* Output         : None
* Return         : None
*******************************************************************************/
void LCD_WriteReg(u8 LCD_Reg,u16 LCD_RegValue)
{
  /* Write 16-bit Index, then Write Reg */
  LCD->LCD_REG = LCD_Reg;
  /* Write 16-bit Reg */
  LCD->LCD_RAM = LCD_RegValue;
}

/*******************************************************************************
* Function Name  : LCD_ReadReg
* Description    : 读寄存器
* Input          : None
* Output         : None
* Return         : LCD Register Value.
*******************************************************************************/
u16 LCD_ReadReg(u8 LCD_Reg)
{
  u16 temp;
  /* Write 16-bit Index (then Read Reg) */
  LCD->LCD_REG = LCD_Reg;
  temp = LCD->LCD_RAM;
  
  temp = LCD->LCD_RAM;
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
  LCD->LCD_REG = R34;
}

/*******************************************************************************
* Function Name  : LCD_ReadRAM
* Description    : Reads the LCD RAM.
* Input          : None
* Output         : None
* Return         : LCD RAM Value.
*******************************************************************************/
u16 LCD_ReadRAM(void)
{
  vu16 dummy;
  /* Write 16-bit Index (then Read Reg) */
  LCD->LCD_REG = R34; /* Select GRAM Reg */
  /* Read 16-bit Reg */
  dummy = LCD->LCD_RAM; 
  return dummy;
}
			 

void Delay(u32 nCount)
{
  u32 TimingDelay; 
  while(nCount--)
  {
    for(TimingDelay=0;TimingDelay<10000;TimingDelay++);
  }
}

/****************************************************************************
* 名    称：LCD_Init())
* 功    能：初始化 LCD 控制器
* 入口参数：无
* 出口参数：无
* 说    明：
* 调用方法：LCD_Init();
****************************************************************************/
void LCD_Init(void)
{
	LCD_LED=0;
	LCD_Configuration();
	delay_ms(50);
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
		LCD_WriteReg(0x26, 0x7000); // Internal Bandgap strength
		LCD_WriteReg(0x20, 0xB0E3); // Internal Vcom strength
		LCD_WriteReg(0x27, 0x0044); // Internal Vcomh/VcomL timing
		LCD_WriteReg(0x2E, 0x7E45); // VCOM charge sharing time  
		//************* Turn On display ******************/
		LCD_WriteReg(0x10, 0x0000); // Sleep mode off.
		delay_ms(30);
		LCD_WriteReg(0x11, 0x6870); // Entry mode setup. 262K type B, take care on the data bus with 16it only
		LCD_WriteReg(0x07, 0x0033); // Display ON	*/
	}	

	LCD_Display_Oir(1);		 	//默认为横屏
	LCD_LED=1;					//点亮背光
	LCD_Clear(WHITE);

} 
/****************************************************************************
* 名    称：LCD_Clear(u16 color)
* 功    能：将屏幕填充成指定的颜色，如清屏，则填充 0xffff
* 入口参数：color      填充值
* 出口参数：无
* 说    明：
* 调用方法：LCD_Clear(0xffff);
****************************************************************************/
void LCD_Clear(u16 color)
{
  u32 index=0;
  LCD_SetCursor(0,0); 
  LCD_WriteRAM_Prepare(); /* Prepare to write GRAM */
  for(index=0;index<76800;index++)
  {
    LCD->LCD_RAM=color;
  }
}
/*******************************************************************************
* Function Name  : LCD_Display_Oir(u8 oir)
* Description    : 设置LCD显示方向
* Input          : oir:0,竖屏；1,横屏
* Output         : None
* Return         : None
*******************************************************************************/
void LCD_Display_Oir(u8 oir)
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
* Function Name  : LCD_SetCursor
* Description    : Sets the cursor position.
* Input          : - Xpos: specifies the X position.
*                  - Ypos: specifies the Y position. 
* Output         : None
* Return         : None
*******************************************************************************/
void LCD_SetCursor(u16 Xpos, u16 Ypos)
{
 	if(lcddev.id==0x8999)
	{	
		if(lcddev.oir)
		{	
			/*横屏*/                                                                                                                                                                                          
			LCD_WriteReg(0x004E, Ypos);
			LCD_WriteReg(0X004F, 319-Xpos);

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
* 名    称：u16 LCD_BGR2RGB(u16 c)
* 功    能：RRRRRGGGGGGBBBBB 改为 BBBBBGGGGGGRRRRR 格式
* 入口参数：c      BRG 颜色值
* 出口参数：RGB 颜色值
* 说    明：内部函数调用
* 调用方法：
****************************************************************************/
u16 LCD_BGR2RGB(u16 c)
{
	u16  r,g,b,rgb;   
	b=(c>>0)&0x1f;
	g=(c>>5)&0x3f;
	r=(c>>11)&0x1f;	 
	rgb=(b<<11)+(g<<5)+(r<<0);		 
	return(rgb);
} 
/****************************************************************************
* 名    称：void LCD_SetWindows(u16 StartX,u16 StartY,u16 EndX,u16 EndY)
* 功    能：设置窗口区域
* 入口参数：StartX     行起始座标
*           StartY     列起始座标
*           EndX       行结束座标
*           EndY       列结束座标
* 出口参数：无
* 说    明：
* 调用方法：LCD_SetWindows(0,0,100,100)；
****************************************************************************/
__inline void LCD_SetWindows(u16 StartX,u16 StartY,u16 EndX,u16 EndY)
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
	LCD_SetCursor(StartX,StartY);

}
/****************************************************************************
* 名    称：void LCD_Fill(u16 StartX,u16 StartY,u16 EndX,u16 EndY,u16 color)
* 功    能：在指定区域内填充单个颜色
* 入口参数：(sx,sy),(ex,ey):填充矩形对角坐标,区域大小为:(ex-sx+1)*(ey-sy+1)   
*			color:要填充的颜色
* 出口参数：无
* 说    明：
* 调用方法：
****************************************************************************/
void LCD_Fill(u16 StartX,u16 StartY,u16 EndX,u16 EndY,u16 color)
{                   
    u32 n;
	//设置窗口
	if(lcddev.oir)
	{	
	   	LCD_SetWindows(StartY,319-EndX,EndY,319-StartX);
		//LCD_SetCursor(StartY,319-EndX);
	}else
	{
		LCD_SetWindows(StartX,StartY,EndX,EndY);
		//LCD_SetCursor(StartX,StartY);
	}
	//LCD_SetCursor(StartX,StartY);
	LCD_WriteRAM_Prepare();  //开始写入GRAM		   	   
	n=(u32)(EndY-StartY+1)*(EndX-StartX+1);    
	while(n--) LCD->LCD_RAM=color;//显示所填充的颜色. 
	//恢复设置
	LCD_SetWindows(0,0,239,319);    
}    
/****************************************************************************
* 名    称：u16 LCD_ReadPoint(u16 x,u16 y)
* 功    能：获取指定座标的颜色值
* 入口参数：x      行座标
*           y      列座标
* 出口参数：当前座标颜色值
* 说    明：
* 调用方法：i=LCD_ReadPoint(10,10);
****************************************************************************/
u16 LCD_ReadPoint(u16 x,u16 y)
{
 	//if(x>=lcddev.width||y>=lcddev.height)return 0;	//超过了范围,直接返回		   
	LCD_SetCursor(x,y);	
	return (LCD_BGR2RGB(LCD_ReadRAM()));
}

/*****************************************************************************
** 函数名称: LCD_DrawPoint
** 功能描述: 画一个点
** 入口参数：x      行座标
**           y      列座标
** 出口参数：
** 说    明：
*****************************************************************************/
__inline void LCD_DrawPoint(u16 x,u16 y)
{
	//if ( (x>320)||(y>240) ) return;
	LCD_SetCursor(x,y);		//设置光标位置 
	LCD_WriteRAM_Prepare();//开始写入GRAM
	LCD->LCD_RAM=POINT_COLOR; 
}
//------------------------------------------------------------------------------------------------------------------
#if USE_uCGUI==0 
/*****************************************************************************
** 函数名称: LCD_DrawLine
** 功能描述: 在指定的两侧位置画一条线
**				x1,y1:起点坐标度  x2,y2:终点坐标 
** 出口参数：
** 说    明：
*****************************************************************************/ 
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2)
{
	u16 t; 
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
		LCD_DrawPoint(uRow,uCol);//画点 
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
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2)
{
	LCD_DrawLine(x1,y1,x2,y1);
	LCD_DrawLine(x1,y1,x1,y2);
	LCD_DrawLine(x1,y2,x2,y2);
	LCD_DrawLine(x2,y1,x2,y2);
}
//在指定位置画一个指定大小的圆
//(x,y):中心点
//r    :半径
void Draw_Circle(u16 x0,u16 y0,u8 r)
{
	int a,b;
	int di;
	a=0;b=r;	  
	di=3-(r<<1);             //判断下个点位置的标志
	while(a<=b)
	{
		LCD_DrawPoint(x0+a,y0-b);             //5
 		LCD_DrawPoint(x0+b,y0-a);             //0           
		LCD_DrawPoint(x0+b,y0+a);             //4               
		LCD_DrawPoint(x0+a,y0+b);             //6 
		LCD_DrawPoint(x0-a,y0+b);             //1       
 		LCD_DrawPoint(x0-b,y0+a);             
		LCD_DrawPoint(x0-a,y0-b);             //2             
  		LCD_DrawPoint(x0-b,y0-a);             //7     	         
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
* 名    称：void LCD_DrawPicture(u16 StartX,u16 StartY,u16 EndX,u16 EndY,u8 *pic)
* 功    能：在指定座标范围显示一副图片
* 入口参数：StartX     行起始座标
*           StartY     列起始座标
*           EndX       行结束座标
*           EndY       列结束座标
            pic        图片头指针
* 出口参数：无
* 说    明：图片取模格式为水平扫描，16位颜色模式
* 调用方法：ili9320_DrawPicture(0,0,100,100,(u16*)demo);
****************************************************************************/
void LCD_DrawPicture(u16 StartX,u16 StartY,u16 EndX,u16 EndY,u8 *pic)
{
 	 u32 n;
  
  	u16 *bitmap = (u16 *)pic;
	if(lcddev.oir)
	{	
	   	LCD_SetWindows(StartY,319-EndX,EndY,319-StartX);
		//LCD_SetCursor(StartY,319-EndX);
	}else
	{
		LCD_SetWindows(StartX,StartY,EndX,EndY);
		//LCD_SetCursor(StartX,StartY);
	}
	//LCD_SetCursor(StartX,StartY);
 	LCD_WriteRAM_Prepare();
  	n=(u32)(EndY-StartY+1)*(EndX-StartX+1);    
	while(n--) LCD->LCD_RAM=*bitmap++;
	
	//恢复设置
	LCD_SetWindows(0,0,239,319);
}
									  
//在指定位置显示一个字符
//x,y:起始坐标
//num:要显示的字符:" "--->"~"
//size:字体大小 12/16
//mode:叠加方式(1)还是非叠加方式(0)
void LCD_ShowChar(u16 x,u16 y,u8 num,u8 size,u8 mode)
{  							  
    u8 temp,t1,t;
	u16 y0=y;
	u16 colortemp=POINT_COLOR;      			     
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
				LCD_DrawPoint(x,y);	
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
		        if(temp&0x80)LCD_DrawPoint(x,y); 
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
u32 LCD_Pow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}			 
//显示数字,高位为0,则不显示
//x,y :起点坐标	 
//len :数字的位数
//size:字体大小
//color:颜色 
//num:数值(0~4294967295);	 
void LCD_ShowNum(u16 x,u16 y,u32 num,u8 len,u8 size)
{         	
	u8 t,temp;
	u8 enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/LCD_Pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				LCD_ShowChar(x+(size/2)*t,y,' ',size,0);
				continue;
			}else enshow=1; 
		 	 
		}
	 	LCD_ShowChar(x+(size/2)*t,y,temp+'0',size,0); 
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
void LCD_ShowxNum(u16 x,u16 y,u32 num,u8 len,u8 size,u8 mode)
{  
	u8 t,temp;
	u8 enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/LCD_Pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				if(mode&0X80)LCD_ShowChar(x+(size/2)*t,y,'0',size,mode&0X01);  
				else LCD_ShowChar(x+(size/2)*t,y,' ',size,mode&0X01);  
 				continue;
			}else enshow=1; 
		 	 
		}
	 	LCD_ShowChar(x+(size/2)*t,y,temp+'0',size,mode&0X01); 
	}
} 
//显示字符串
//x,y:起点坐标
//width,height:区域大小  
//size:字体大小
//*p:字符串起始地址		  
void LCD_ShowString(u16 x,u16 y,u16 width,u16 height,u8 size,u8 *p)
{         
	u8 x0=x;
	width+=x;
	height+=y;
    while((*p<='~')&&(*p>=' '))//判断是不是非法字符!
    {       
        if(x>=width){x=x0;y+=size;}
        if(y>=height)break;//退出
        LCD_ShowChar(x,y,*p,size,0);
        x+=size/2;
        p++;
    }  
}

#endif
