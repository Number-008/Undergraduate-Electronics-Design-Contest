/*
 * key.h
 *
 *  Created on: 2013-1-24
 *      Author: qin
 */

#ifndef KEY_H_
#define KEY_H_
#include "system.h"
#include "alt_types.h"
#include "io.h"

#define KEY_addr KEY_BASE

#define WR_KEY_EDGE_CAP(data)   IOWR(KEY_addr, 3, data)//Çå±ßÑØ²¶»ñ¼Ä´æÆ÷
#define WR_KEY_IRQ_MASK(data)   IOWR(KEY_addr, 2, data)//ÆÁ±ÎKEYµÄÖÐ¶Ï £»1--ÔÊÐí£¬0--ÆÁ±Î
#define RD_KEY            		IORD(KEY_addr, 0)      //¶Ákey

//void KeyDown_interrupts(void* context, alt_u32 id);
void Init_Key(void);

#endif /* KEY_H_ */
