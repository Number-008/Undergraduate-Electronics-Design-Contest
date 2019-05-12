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

#define WR_KEY_EDGE_CAP(data)   IOWR(KEY_addr, 3, data)//����ز���Ĵ���
#define WR_KEY_IRQ_MASK(data)   IOWR(KEY_addr, 2, data)//����KEY���ж� ��1--����0--����
#define RD_KEY            		IORD(KEY_addr, 0)      //��key

//void KeyDown_interrupts(void* context, alt_u32 id);
void Init_Key(void);

#endif /* KEY_H_ */
