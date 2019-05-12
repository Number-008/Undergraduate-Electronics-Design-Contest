#ifndef APP_H_
#define APP_H_
#include "alt_types.h"
#include "system.h"
#include "io.h"
#define Read_RAM(addr) 	IORD(RAM_READ_BASE,addr)
extern alt_u8 Y0;
extern alt_u8 X0;
extern alt_u8 save_control;
extern alt_u8 data_in[1024];
extern alt_u16 Vpp;

void DispFrame(void);
void DispWave(void);
void Vpp_printf(void);
void Play_data(void);

#endif /* APP_H_ */
