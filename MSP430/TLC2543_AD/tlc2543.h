/*
 * tlc2543.h
 *
 *  Created on: 2013-7-29
 *      Author: Qin Hai Cheng
 */

#ifndef TLC2543_H_
#define TLC2543_H_

void TLC2543Init(void);
u16 Read_TLC2543(u8 chx_num);
void Printf_AD(u8 chx_num,char *DisBuf,u8 x);

#endif /* TLC2543_H_ */
