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
  int   offset;//��ַ��ʼ��ƫ����
  int   region_size;//��������Ĵ�С
  int   number_of_blocks;//����Ŀ���
  int   block_size;//������ÿһ��Ĵ�С
}flash_region;*/

void Get_FlashInfo(void);
alt_u32 Flash_ReadLenByte( alt_u16 offset, alt_u8 nByte);
void Flash_WriteLenByte(alt_u16 offset, alt_u32 data, alt_u8 nByte);
void Flash_WriteLenByteData(alt_u16 offset,alt_u32 *data, alt_u8 nByte,alt_u16 length);
void Flash_ReadLenByteData(alt_u16 offset,alt_u32 *dest_addr,alt_u8 nByte,alt_u16 length);
#endif /* FLASH_H_ */
