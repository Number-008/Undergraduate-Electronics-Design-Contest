#include "ili9320.h"
#include "stdlib.h"
#include "font.h"
#include "unistd.h"
#include "app.h"
//����LCD��Ҫ����
//Ĭ��Ϊ����
_lcd_dev lcddev;

void delay_ms(alt_u16 n)
{
	usleep(n*1000);
}
/*******************************************************************************
* Function Name  : LCD_WriteReg
* Description    : д�Ĵ���.
* Input          : - LCD_Reg: �Ĵ�����ַ
*                  - LCD_RegValue: Ҫд�������.
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
* Description    : ���Ĵ���
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
* ��    �ƣ�ili9320_Initializtion()
* ��    �ܣ���ʼ�� LCD ������
* ��ڲ�������
* ���ڲ�������
* ˵    ����
* ���÷�����ili9320_Initializtion();
****************************************************************************/
void ili9320_Initializtion(void)
{

	LCD_LED(0);
	LCD_WriteReg(0x0000,0x0001);
	delay_ms(50); // delay 50 ms 
	lcddev.id = LCD_ReadReg(0x0000);
	if(lcddev.id==0x8999)	   //��Ӧ������ICΪSSD1289
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
	ili9320_Display_Oir(1);		 	//Ĭ��Ϊ����
	LCD_LED(1);					//��������
	ili9320_Clear(WHITE);

} 
/****************************************************************************
* ��    �ƣ�ili9320_Clear(alt_u16 color)
* ��    �ܣ�����Ļ����ָ������ɫ��������������� 0xffff
* ��ڲ�����color      ���ֵ
* ���ڲ�������
* ˵    ����
* ���÷�����ili9320_Clear(0xffff);
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
* Description    : ����LCD��ʾ����
* Input          : oir:0,������1,����
* Output         : None
* Return         : None
*******************************************************************************/
void ili9320_Display_Oir(alt_u8 oir)
{
	if(oir)
	{
		/*����*/
		lcddev.oir=1;
		lcddev.width=319;
		lcddev.height=239;	
	}else
	{
	   	/*����*/
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
			/*����*/                                                                                                                                                                                          
			LCD_WriteReg(0x004E, 239-Ypos);
			LCD_WriteReg(0X004F, Xpos);

		}else
		{
		  	/*����*/                                                                     
			LCD_WriteReg(0x004E, Xpos);
			LCD_WriteReg(0X004F, Ypos);
		}
	}else 
	{
		if(lcddev.oir)
		{	
			/*����*/
			LCD_WriteReg(R32, Xpos);
			LCD_WriteReg(R33, Ypos);
		}else
		{
			/*����*/
			LCD_WriteReg(R32, Ypos);
			LCD_WriteReg(R33, 319-Xpos);
		}
	}
}

/****************************************************************************
* ��    �ƣ�alt_u16 ili9320_BGR2RGB(alt_u16 c)
* ��    �ܣ�RRRRRGGGGGGBBBBB ��Ϊ BBBBBGGGGGGRRRRR ��ʽ
* ��ڲ�����c      BRG ��ɫֵ
* ���ڲ�����RGB ��ɫֵ
* ˵    �����ڲ���������
* ���÷�����
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
* ��    �ƣ�void ili9320_SetWindows(alt_u16 StartX,alt_u16 StartY,alt_u16 EndX,alt_u16 EndY)
* ��    �ܣ����ô�������
* ��ڲ�����StartX     ����ʼ����
*           StartY     ����ʼ����
*           EndX       �н�������
*           EndY       �н�������
* ���ڲ�������
* ˵    ����
* ���÷�����ili9320_SetWindows(0,0,100,100)��
****************************************************************************/
__inline void ili9320_SetWindows(alt_u16 StartX,alt_u16 StartY,alt_u16 EndX,alt_u16 EndY)
{
	if(lcddev.id==0x8999)
  	{
		//����ͼƬ��ʾ���ڴ�С
		LCD_WriteReg(0x44,StartX|EndX<<8);  //����ˮƽ����GRAM��ʼ��ַ(���ֽ�Ϊ��ʼ��ַ�����ֽ�Ϊ������ַ)
		LCD_WriteReg(0x45,StartY);		    //���ô��ڵ�Y����Ŀ�ʼλ��
		LCD_WriteReg(0x46,EndY);			//���ô��ڵ�Y����Ľ���λ��
  	}else 
	{										
		LCD_WriteReg(R80, StartX); 			//ˮƽ����GRAM��ʼ��ַ
		LCD_WriteReg(R81, EndX); 			//ˮƽ����GRAM������ַ
		LCD_WriteReg(R82, StartY);			//��ֱ����GRAM��ʼ��ַ
		LCD_WriteReg(R83, EndY);			//��ֱ����GRAM������ַ	
	}
	ili9320_SetCursor(StartX,StartY);

}
/****************************************************************************
* ��    �ƣ�void ili9320_Fill(alt_u16 StartX,alt_u16 StartY,alt_u16 EndX,alt_u16 EndY,alt_u16 color)
* ��    �ܣ���ָ����������䵥����ɫ
* ��ڲ�����(sx,sy),(ex,ey):�����ζԽ�����,�����СΪ:(ex-sx+1)*(ey-sy+1)   
*			color:Ҫ������ɫ
* ���ڲ�������
* ˵    ����
* ���÷�����
****************************************************************************/
void ili9320_Fill(alt_u16 StartX,alt_u16 StartY,alt_u16 EndX,alt_u16 EndY,alt_u16 color)
{                   
    alt_u32 n;
    alt_u8 temp=0;
	//���ô���
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
	LCD_WriteRAM_Prepare();  //��ʼд��GRAM		   	   
	n=(alt_u32)(EndY-StartY+1)*(EndX-StartX+1);
	while(n--) WriteRAM(color);//��ʾ��������ɫ
	//�ָ�����
	ili9320_SetWindows(0,0,239,319);
	lcddev.oir=temp;
}    
/****************************************************************************
* ��    �ƣ�alt_u16 LCD_ReadPoint(alt_u16 x,alt_u16 y)
* ��    �ܣ���ȡָ���������ɫֵ
* ��ڲ�����x      ������
*           y      ������
* ���ڲ�������ǰ������ɫֵ
* ˵    ����
* ���÷�����i=LCD_ReadPoint(10,10);
****************************************************************************/
alt_u16 ili9320_GetPoint(alt_u16 x,alt_u16 y)
{
 	//if(x>=lcddev.width||y>=lcddev.height)return 0;	//�����˷�Χ,ֱ�ӷ���		   
	ili9320_SetCursor(x,y);	
	return (ili9320_BGR2RGB(LCD_ReadRAM()));
}

/*****************************************************************************
** ��������: ili9320_SetPoint
** ��������: дһ����
** ��ڲ�����x      ������
**           y      ������
** ���ڲ�����
** ˵    ����
*****************************************************************************/
__inline void ili9320_SetPoint(alt_u16 x,alt_u16 y,alt_u16 color)
{
	if ( (x>320)||(y>240) ) return;
	ili9320_SetCursor(x,y);		//���ù��λ�� 
	LCD_WriteRAM_Prepare();//��ʼд��GRAM
	WriteRAM(color);
}
__inline void ili9320_SetPoint2(alt_u16 x,alt_u16 y,alt_u16 color)
{
	if ((x<10)||(x>310)||(y<20 )||(y>220) ) return;
	ili9320_SetCursor(x,y);		//���ù��λ��
	LCD_WriteRAM_Prepare();//��ʼд��GRAM
	WriteRAM(color);

}
//------------------------------------------------------------------------------------------------------------------
#if (USE_uCGUI==0)
/*****************************************************************************
** ��������: ili9320_DrawLine
** ��������: ��ָ��������λ�û�һ����
**				x1,y1:��������  x2,y2:�յ����� 
** ���ڲ�����
** ˵    ����
*****************************************************************************/ 
void ili9320_DrawLine(alt_u16 x1, alt_u16 y1, alt_u16 x2, alt_u16 y2,alt_u16 color)
{
	alt_u16 t;
	int xerr=0,yerr=0,delta_x,delta_y,distance; 
	int incx,incy,uRow,uCol; 
	delta_x=x2-x1; //������������ 
	delta_y=y2-y1; 
	uRow=x1; 
	uCol=y1; 
	if(delta_x>0)incx=1; //���õ������� 
	else if(delta_x==0)incx=0;//��ֱ�� 
	else {incx=-1;delta_x=-delta_x;} 
	if(delta_y>0)incy=1; 
	else if(delta_y==0)incy=0;//ˮƽ�� 
	else{incy=-1;delta_y=-delta_y;} 
	if( delta_x>delta_y)distance=delta_x; //ѡȡ�������������� 
	else distance=delta_y; 
	for(t=0;t<=distance+1;t++ )//������� 
	{  
		//sx(uRow);
		ili9320_SetPoint(uRow,uCol,color);//����
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
	delta_x=x2-x1; //������������
	delta_y=y2-y1;
	uRow=x1;
	uCol=y1;
	if(delta_x>0)incx=1; //���õ�������
	else if(delta_x==0)incx=0;//��ֱ��
	else {incx=-1;delta_x=-delta_x;}
	if(delta_y>0)incy=1;
	else if(delta_y==0)incy=0;//ˮƽ��
	else{incy=-1;delta_y=-delta_y;}
	if( delta_x>delta_y)distance=delta_x; //ѡȡ��������������
	else distance=delta_y;
	for(t=0;t<=distance+1;t++ )//�������
	{
		ili9320_SetPoint2(uRow,uCol,color);//����
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
//������	  
//(x1,y1),(x2,y2):���εĶԽ�����
void ili9320_DrawRectangle(alt_u16 x1, alt_u16 y1, alt_u16 x2, alt_u16 y2,alt_u16 color)
{
	ili9320_DrawLine(x1,y1,x2,y1,color);
	ili9320_DrawLine(x1,y1,x1,y2,color);
	ili9320_DrawLine(x1,y2,x2,y2,color);
	ili9320_DrawLine(x2,y1,x2,y2,color);
}
//��ָ��λ�û�һ��ָ����С��Բ
//(x,y):���ĵ�
//r    :�뾶
void ili9320_DrawCircle(alt_u16 x0,alt_u16 y0,alt_u8 r,alt_u16 color)
{
	int a,b;
	int di;
	a=0;b=r;	  
	di=3-(r<<1);             //�ж��¸���λ�õı�־
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
		//ʹ��Bresenham�㷨��Բ     
		if(di<0)di +=4*a+6;	  
		else
		{
			di+=10+4*(a-b);   
			b--;
		} 						    
	}
} 
/****************************************************************************
* ��    �ƣ�void LCD_DrawPicture(alt_u16 StartX,alt_u16 StartY,alt_u16 EndX,alt_u16 EndY,alt_u8 *pic)
* ��    �ܣ���ָ�����귶Χ��ʾһ��ͼƬ
* ��ڲ�����StartX     ����ʼ����
*           StartY     ����ʼ����
*           EndX       �н�������
*           EndY       �н�������
            pic        ͼƬͷָ��
* ���ڲ�������
* ˵    ����ͼƬȡģ��ʽΪˮƽɨ�裬16λ��ɫģʽ
* ���÷�����ili9320_DrawPicture(0,0,100,100,(alt_u16*)demo);
****************************************************************************/
void ili9320_DrawPicture(alt_u16 StartX,alt_u16 StartY,alt_u16 EndX,alt_u16 EndY,alt_u8 *pic)
{
 	 alt_u32 n;
  
  	alt_u16 *bitmap = (alt_u16 *)pic;
  	alt_u8 temp=0;
  		//���ô���
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
	
	//�ָ�����
	ili9320_SetWindows(0,0,239,319);
}
									  
//��ָ��λ����ʾһ���ַ�
//x,y:��ʼ����
//num:Ҫ��ʾ���ַ�:" "--->"~"
//size:�����С 12/16
//mode:���ӷ�ʽ(1)���Ƿǵ��ӷ�ʽ(0)
void ili9320_ShowChar(alt_u16 x,alt_u16 y,alt_u8 num,alt_u8 size,alt_u8 mode,alt_u16  POINT_COLOR,alt_u16  BACK_COLOR)
{  							  
    alt_u8 temp,t1,t;
	alt_u16 y0=y;
	alt_u16 colortemp=POINT_COLOR;
	//���ô���		   
	num=num-' ';//�õ�ƫ�ƺ��ֵ
	if(!mode) //�ǵ��ӷ�ʽ
	{
	    for(t=0;t<size;t++)
	    {   
			if(size==12)temp=asc2_1206[num][t];  //����1206����
			else temp=asc2_1608[num][t];		 //����1608���� 	                          
	        for(t1=0;t1<8;t1++)
			{			    
		        if(temp&0x80)POINT_COLOR=colortemp;
				else POINT_COLOR=BACK_COLOR;
				ili9320_SetPoint(x,y,POINT_COLOR);	
				temp<<=1;
				y++;
				if(x>=lcddev.width){POINT_COLOR=colortemp;return;}//��������
				if((y-y0)==size)
				{
					y=y0;
					x++;
					if(x>=lcddev.width){POINT_COLOR=colortemp;return;}//��������
					break;
				}
			}  	 
	    }    
	}else//���ӷ�ʽ
	{
	    for(t=0;t<size;t++)
	    {   
			if(size==12)temp=asc2_1206[num][t];  //����1206����
			else temp=asc2_1608[num][t];		 //����1608���� 	                          
	        for(t1=0;t1<8;t1++)
			{			    
		        if(temp&0x80)ili9320_SetPoint(x,y,POINT_COLOR); 
				temp<<=1;
				y++;
				if(x>=lcddev.height){POINT_COLOR=colortemp;return;}//��������
				if((y-y0)==size)
				{
					y=y0;
					x++;
					if(x>=lcddev.width){POINT_COLOR=colortemp;return;}//��������
					break;
				}
			}  	 
	    }     
	}
	POINT_COLOR=colortemp;	    	   	 	  
}   
//m^n����
//����ֵ:m^n�η�.
alt_u32 ili9320_Pow(alt_u8 m,alt_u8 n)
{
	alt_u32 result=1;
	while(n--)result*=m;    
	return result;
}			 
//��ʾ����,��λΪ0,����ʾ
//x,y :�������	 
//len :���ֵ�λ��
//size:�����С
//color:��ɫ 
//num:��ֵ(0~4294967295);	 
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
//��ʾ����,��λΪ0,������ʾ
//x,y:�������
//num:��ֵ(0~999999999);	 
//len:����(��Ҫ��ʾ��λ��)
//size:�����С
//mode:
//[7]:0,�����;1,���0.
//[6:1]:����
//[0]:0,�ǵ�����ʾ;1,������ʾ.
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
//��ʾ�ַ���
//x,y:�������
//width,height:�����С  
//size:�����С
//*p:�ַ�����ʼ��ַ		  
void ili9320_ShowString(alt_u16 x,alt_u16 y,alt_u16 width,alt_u16 height,alt_u8 size,alt_u8 *p,alt_u16  POINT_COLOR,alt_u16  BACK_COLOR)
{         
	alt_u8 x0=x;
	width+=x;
	height+=y;
    while((*p<='~')&&(*p>=' '))//�ж��ǲ��ǷǷ��ַ�!
    {       
        if(x>=width){x=x0;y+=size;}
        if(y>=height)break;//�˳�
        ili9320_ShowChar(x,y,*p,size,0,POINT_COLOR,BACK_COLOR);
        x+=size/2;
        p++;
    }  
}

#endif
