#include "djd.h"
#include "lcd12864.h"
#include "sys/alt_stdio.h"


int main()
{
	LCD_Init();//lcd12864≥ı ºªØ
	LCD_ShowString(1,1,"OK");
	while(1)
	{
		DJDaut(ReadDJD());
	}
    return 0;
}

