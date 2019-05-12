/*
 * clk_div.h
 *
 *  Created on: 2013-5-18
 *      Author: qin
 */

#ifndef DIV_H_
#define DIV_H_
#include "system.h"
#include "alt_types.h"
#include "io.h"
extern alt_u8 LCKDIV;
extern alt_u8 VDIV;
//extern alt_u16 Vpp;

#define WriteClkDiv(data) 		IOWR(DIV_BASE,0, data)
void WrClkDiv(alt_u8 n);
void WrVDiv(alt_u8 n);
void Vpp_printf(void);
//void Ctrl_printf(void);
#endif /* CLK_DIV_H_ */
