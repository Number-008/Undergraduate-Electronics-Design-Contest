/*
 * flash.h
 *
 *  Created on: 2013-1-25
 *  Author: Qin Hai Cheng
 */

#ifndef FLASH_H_
#define FLASH_H_

#define FLASH "/dev/epcs"
#define Block_Size 0x10000
#define FLASH_OFFSET 0x70000

/*typedef struct flash_region
{
  int   offset;//地址初始的偏移量
  int   region_size;//擦除区域的大小
  int   number_of_blocks;//区域的块数
  int   block_size;//区域中每一块的大小
}flash_region;*/

void Get_FlashInfo(void);
alt_u32 Flash_ReadLenByte( alt_u16 offset, alt_u8 nByte);
void Flash_WriteLenByte(alt_u16 offset, alt_u32 data, alt_u8 nByte);
void Flash_WriteLenByteData(alt_u16 offset,alt_u32 *data, alt_u8 nByte,alt_u16 length);
void Flash_ReadLenByteData(alt_u16 offset,alt_u32 *dest_addr,alt_u8 nByte,alt_u16 length);
#endif /* FLASH_H_ */
