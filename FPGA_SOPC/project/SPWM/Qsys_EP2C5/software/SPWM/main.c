#include "key.h"
#include "lcd12864.h"
#include"dds.h"

int main()
{ 
	LCD_Init();
	printf_Freq();
	while (1)
	{
		KeyScan();

	}
	return 0;
}