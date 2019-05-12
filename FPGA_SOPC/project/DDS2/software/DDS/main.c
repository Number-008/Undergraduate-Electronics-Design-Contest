#include "lcd12864.h"
#include "stdio.h"
#include "system.h"
#include "dds.h"
#include "key.h"
#include "altera_avalon_pio_regs.h"
int main(void)
{
	alt_u8 n1,n2;
	LCD_Init();//lcd12864≥ı ºªØ
	DDS_Init();
	LCD_ShowString(1,1,"Wave");
	LCD_ShowString(9,1,"Pha=");
	LCD_ShowString(1,2,"Fre=");
	n1=IORD_ALTERA_AVALON_PIO_DATA(SW_BASE) & 0x03;
	n2=n1;
	DDS_RAM_WR(n1);

	while(1)
	{
		n1=IORD_ALTERA_AVALON_PIO_DATA(SW_BASE) & 0x03;
		usleep(2000);
		if(n1!=n2)
		{
			DDS_RAM_WR(n1);
			n2=n1;
		}
		key();
	}
    return 0;
}

