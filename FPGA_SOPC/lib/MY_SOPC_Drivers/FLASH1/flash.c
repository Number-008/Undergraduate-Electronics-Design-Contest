/*
 *  flash.c
 *  功能：对单独的块进行读写，可写入单独的块里的指定地址；
 *  Created on: 2013-1-25
 *  Author: Qin Hai Cheng
 */
#include "sys/alt_flash.h"
#include <stdlib.h>
#include <stdio.h>
//#include <unistd.h>
#include "flash.h"

void Get_FlashInfo(void)
{
	alt_flash_fd* fd;
	flash_region* regions;
	int number_of_regions;
	alt_u8 i;
	int ret_code=0 ;
	//打开FLASH设备
	fd = alt_flash_open_dev(FLASH);
	if(fd == 0)
	{
		printf("Can't open flash device\n");
		exit(-1);
	}
	else
	{
		printf("Open Flash Device Successfully.\n");

		/*获得FLASH信息*/
		ret_code = alt_get_flash_info(fd,
				&regions,
				&number_of_regions);
		for(i=0;i<number_of_regions;i++)
			{
				printf("Start:0x%x, End:0x%x, Number of Blocks:%d, Block Size:0x%x, Region size:0x%x\n",
					(regions+i)->offset,
					(regions+i)->region_size+(regions+i)->offset,
					(regions+i)->number_of_blocks,
					(regions+i)->block_size,
					(regions+i)->region_size);

			}
		}

	//关闭FLASH设备
	alt_flash_close_dev(fd);

}

//从flash偏移量为offset字节开始读取长度为length个字节的数据
//该函数用于读出8bit,16bit 或者32bit 的数据
//length:要写入数据的长度1,2,4
alt_u32 Flash_ReadLenByte( alt_u16 offset, alt_u8 nByte)
{
	alt_flash_fd* fd;
	int ret_code=0 ;
	alt_u8 i,dest[nByte];
	alt_u32 temp=0;
	//打开FLASH设备
	fd = alt_flash_open_dev(FLASH);
    if(fd)
    {
		//读FLASH中的数据,成功后返回值为0
		ret_code = alt_read_flash(fd,FLASH_OFFSET+offset,dest,nByte);
		if(ret_code != 0)
		{
			printf("Can't read flash device\n");
			exit(-1);
		}
		else
		{
			printf("Read Flash Device Successfully.\n");
			for(i=0;i<nByte;i++)
			{
				temp <<= 8;
				temp += dest[nByte-1-i];
			}
			//return temp;
		}


	}
    else
    	printf("Can't open flash device\n");
	alt_flash_close_dev(fd);
	return temp;
}

//在指定的块地址开始写入length个字节数据
//不擦除其他地址的数据
//该函数用于写入8bit,16bit 或者32bit 的数据
//length:要写入数据的长度1,2,4
void Flash_WriteLenByte(alt_u16 offset, alt_u32 data, alt_u8 nByte)
{
	alt_flash_fd* fd;
	int ret_code=0 ;
	alt_u8 i;
	alt_u8 temp [Block_Size];

	fd = alt_flash_open_dev(FLASH);
	if(fd)
	{
		ret_code = alt_read_flash(fd,FLASH_OFFSET,temp,Block_Size);
		if(ret_code != 0)
		{
			printf("Can't read flash device\n");
			exit(-1);
		}
		else
		{
			printf("Read Flash Device Successfully.\n");

			//单独块擦除
			ret_code =alt_erase_flash_block(fd,
				FLASH_OFFSET,
				Block_Size);

			if(ret_code != 0)
			{
				printf("Can't erase flash block\n");
				exit(-1);
			}
			else
			{
				printf("Erase flash block Successfully\n");
				for(i=0;i<nByte;i++)
				{
					temp[offset+i] = data >>(8*i) & 0xff;
				}

				ret_code =alt_write_flash_block(fd,
										FLASH_OFFSET,
										FLASH_OFFSET,
										temp,
										Block_Size);
				if(ret_code != 0)
				{
					printf("Can't write flash block\n");
					exit(-1);
				}
				else
				{
					printf("Write flash block successfully\n");
				}
			}
		}
	}
	else
		printf("Can't open flash device\n");

}

void Flash_ReadLenByteData(alt_u16 offset,alt_u32 *dest_addr,alt_u8 nByte,alt_u16 length)
{
	alt_flash_fd* fd;
	int ret_code=0 ;
	alt_u8 i;
	alt_u16 j;
	alt_u8 read_data[nByte*length];
	//打开FLASH设备
	fd = alt_flash_open_dev(FLASH);
	if(fd)
	{
		//读FLASH中的数据,成功后返回值为0
		ret_code = alt_read_flash(fd,FLASH_OFFSET+offset,read_data,nByte*length);
		if(ret_code != 0)
		{
			printf("Can't read flash device\n");
			exit(-1);
		}
		else
		{
			printf("Read Flash Device Successfully.\n");
			for(j=1;j<=length;j++)
			{
				for(i=0;i<nByte;i++)
				{
					*dest_addr <<= 8;
					*dest_addr += read_data[j*nByte-1-i];
				}
				dest_addr++;
			}
			dest_addr = dest_addr-length;
		}


	}
	else
		printf("Can't open flash device\n");
	alt_flash_close_dev(fd);

}

//在指定的块地址开始写入length个字节数据
//不擦除其他地址的数据
//该函数用于写入8bit,16bit 或者32bit 的数据
//nByte:要写入数据的长度1,2,4
void Flash_WriteLenByteData(alt_u16 offset,alt_u32 *data, alt_u8 nByte,alt_u16 length)
{
	alt_flash_fd* fd;
	int ret_code=0 ;
	alt_u8 i;
	alt_u16 j;
	alt_u8 temp [Block_Size];

	fd = alt_flash_open_dev(FLASH);
	if(fd)
	{
		ret_code = alt_read_flash(fd,FLASH_OFFSET,temp,Block_Size);
		if(ret_code != 0)
		{
			printf("Can't read flash device\n");
			exit(-1);
		}
		else
		{
			printf("Read Flash Device Successfully.\n");

			//单独块擦除
			ret_code =alt_erase_flash_block(fd,
				FLASH_OFFSET,
				Block_Size);

			if(ret_code != 0)
			{
				printf("Can't erase flash block\n");
				exit(-1);
			}
			else
			{
				printf("Erase flash block Successfully\n");
				for(j=0;j<length;j++)
				{
					for(i=0;i<nByte;i++)
					{
						temp[offset+i+j*nByte] = *(data+j) >>(8*i) & 0xff;

					}
				}
				ret_code =alt_write_flash_block(fd,
										FLASH_OFFSET,
										FLASH_OFFSET,
										temp,
										Block_Size);
				if(ret_code != 0)
				{
					printf("Can't write flash block\n");
					exit(-1);
				}
				else
				{
					printf("Write flash block successfully\n");
				}
			}
		}
	}
	else
		printf("Can't open flash device\n");
alt_flash_close_dev(fd);

}









