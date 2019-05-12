/*
 * flash.h
 *
 *  Created on: 2013-1-25
 *      Author: qin
 */

#ifndef FLASH_H_
#define FLASH_H_

#define FLASH "/dev/epcs_flash"
#define Block_Size 0x10000
#define FLASH_OFFSET 0x70000

void Flash_WriteData(void);
void Flash_ReadData(void);
#endif /* FLASH_H_ */
