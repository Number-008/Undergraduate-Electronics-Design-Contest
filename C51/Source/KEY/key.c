#include"key.h"
#include"delay.h"
#include"lcd.h"	
#include"ad9851.h"
#include"ads7818.h"
bit k=0;
u8 PGA=0x02;
//u16 Vr=0x7f6;

void KEYIRQ(void)interrupt 0
{

	if ((READ_INT0 & 0x03)!=0x03)
	{
		delay(10);
		if ((READ_INT0 & 0x01)!=0x01)
		{
			switch (KEY_1)
			{
				case 0xFE://S1
					  {
					   	Fraq++;
						if(Fraq<0||Fraq>20000)Fraq=0;
						//while(KEY_1==0xFE);
						AD9851WriteData();
						printf_Fraq();
						delay(80);	
					   	
					  }
					break;
				case 0xFD://S2 
					{
					 	Fraq+=10;
						if(Fraq<0||Fraq>20000)Fraq=0;
						//while(KEY_1==0xFD);
						AD9851WriteData();
						printf_Fraq();
						delay(80);	
					 		
					}
					break;
				case 0xFB://S3 
					{
					  	Fraq+=100;
						if(Fraq<0||Fraq>20000)Fraq=0;
						//while(KEY_1==0xFB);
						AD9851WriteData();
						printf_Fraq();
						delay(80);				

					}
					break;
				case 0xF7://S4 
					{
					  	Fraq+=1000;
						if(Fraq<0||Fraq>20000)Fraq=0;
						//while(KEY_1==0xF7);
						AD9851WriteData();
						printf_Fraq();
						delay(80);	
					 	
					}
					break;
				case 0xEF://S5 
					{
						Fraq--;
						if(Fraq<0||Fraq>20000)Fraq=20000;
						//while(KEY_1==0xEF);	
						AD9851WriteData();
						printf_Fraq();
						delay(80);	

					}
					break;
				case 0xDF://S6 
					{
					 	Fraq-=10;
						if(Fraq<0||Fraq>20000)Fraq=20000;
						//while(KEY_1==0xDF);
						AD9851WriteData();
						printf_Fraq();
						delay(80);
					 		
					}
					break;
				case 0xBF://S7
					{
					 	Fraq-=100;
						if(Fraq<0||Fraq>20000)Fraq=20000;
						//while(KEY_1==0xBF);
						AD9851WriteData();
						printf_Fraq();
						delay(80);		 	
					
					} 
					break;
				case 0x7F://S8 
					{
					 	Fraq-=1000;
						if(Fraq<0||Fraq>20000)Fraq=20000;
						//while(KEY_1==0x7F);
						AD9851WriteData();
						printf_Fraq();
						delay(80);	
					}
					break;
				default:
					break;
			}
		}

		if ((READ_INT0 & 0x02)!=0x02)
		{
			switch (KEY_2)
			{
				case 0xFE://S9 
					{
					  	Phase++;
						//if(Phase<0 || Phase>=32)Phase=0;
						//while(KEY_2==0xFE);	
						AD9851WriteData();
						printf_Phase();
						delay(80);
						
					}break;
				case 0xFD://S10
					{
						while(KEY_2==0xFD);	
						k=~k;
				
					}break;
				case 0xFB://S11
					break;
				case 0xF7://S12
					{
			
					 	while(KEY_2==0xF7);
						PGA++;
						if(PGA<0 || PGA>3) PGA=3;
						switch (PGA)
						{
							case 0:
							{
								PGA_A0=0;
								PGA_A1=0;
								LCD_ShowString(0,1,"1   ");
							}break;
							case 1:
							{
								PGA_A0=1;
								PGA_A1=0;
								LCD_ShowString(0,1,"10  ");
							}break;
							case 2:
							{
								PGA_A0=0;
								PGA_A1=1;
								LCD_ShowString(0,1,"100 ");
							}break;
							case 3:
							{
								PGA_A0=1;
								PGA_A1=1;
								LCD_ShowString(0,1,"1000");
							}break;
							default:
								break;
						}		
					
					}
					break;
				case 0xEF://S13
					{
					 	Phase--;
						//if(Phase<0||Phase>31)Phase=31;
						//while(KEY_2==0xEF);
						//AD9851WriteData();
						AD9851WriteData();
						printf_Phase();	
						delay(80);				 	
				
					}
					break;
				case 0xDF://S14
				{
//					  while(KEY_2==0xDF);
//					  fb++;
				
				
				
				}
					break;
				case 0xBF://S15
				{
				
//					while(KEY_2==0xBF);
//					fb--;
				
				
				
				}
					break;
				case 0x7F://S16
					{
						while(KEY_2==0x7F);
					 				
					 	while(KEY_2==0xF7);
						PGA--;
						if(PGA<0 || PGA>3) PGA=0;
						switch (PGA)
						{
							case 0:
							{
								PGA_A0=0;
								PGA_A1=0;
								LCD_ShowString(0,1,"1   ");
							}break;
							case 1:
							{
								PGA_A0=1;
								PGA_A1=0;
								LCD_ShowString(0,1,"10  ");
							}break;
							case 2:
							{
								PGA_A0=0;
								PGA_A1=1;
								LCD_ShowString(0,1,"100 ");
							}break;
							case 3:
							{
								PGA_A0=1;
								PGA_A1=1;
								LCD_ShowString(0,1,"1000");
							}break;
							default:
								break;
						}		
					
					}

					break;
				default:
					break;
			}
		}
	}

}
