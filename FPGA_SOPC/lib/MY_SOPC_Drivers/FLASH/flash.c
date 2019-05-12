#include "sys/alt_flash.h"
#include <stdlib.h>
#include <stdio.h>
//#include <unistd.h>
#include "flash.h"
#include "ili9320.h"
#include "app.h"

void Flash_ReadData(void)
{
	alt_flash_fd* fd;
	int ret_code=0 ;

	//打开FLASH设备
	fd = alt_flash_open_dev(FLASH);
	if(fd)
	{
		//读FLASH中的数据,成功后返回值为0
		//ili9320_ShowString(100,120,180,16,16,"Reading...",BLUE,WHITE);
		ret_code = alt_read_flash(fd,FLASH_OFFSET,data_in,512);
		if(ret_code != 0)
		{
			//printf("Can't read flash device\n");
			ili9320_ShowString(100,100,180,16,16,"Can't read flash device",RED,WHITE);
			delay_ms(1000);
			exit(-1);
		}
		else
		{
			//printf("Read Flash Device Successfully.\n");

			//ili9320_ShowString(100,120,180,16,16,"Read Successfully",BLUE,WHITE);
		}

	}
	else
	{
		//printf("Can't open flash device\n");
		ili9320_ShowString(100,100,180,16,16,"Can't open flash device",RED,WHITE);
		delay_ms(1000);
	}
	alt_flash_close_dev(fd);

}


void Flash_WriteData(void)
{
	alt_flash_fd* fd;
	int ret_code=0 ;

	fd = alt_flash_open_dev(FLASH);
	if(fd)
	{
		//单独块擦除
		ret_code =alt_erase_flash_block(fd,
			FLASH_OFFSET,
			Block_Size);

		if(ret_code != 0)
		{
			ili9320_ShowString(100,100,180,16,16,"Can't erase flash block",RED,WHITE);
			delay_ms(1000);
			exit(-1);
		}
		else
		{

			ili9320_ShowString(100,120,180,16,16,"Saving of data ...",BLUE,WHITE);
			//向FLASH中写数据，成功后返回值为0
			ret_code = alt_write_flash(fd,FLASH_OFFSET,data_in,512);
			delay_ms(500);
			if(ret_code != 0)
			{
				ili9320_ShowString(100,100,180,16,16,"Can't write flash device",RED,WHITE);
				delay_ms(1000);
				exit(-1);
			}
			else
			{
				ili9320_ShowString(100,120,180,16,16,"Save successfully ",BLUE,WHITE);
				delay_ms(500);
			}
		}
	}
	else
	{
		ili9320_ShowString(100,100,180,16,16,"Can't open flash device",RED,WHITE);
		delay_ms(1000);
	}

	alt_flash_close_dev(fd);
}









