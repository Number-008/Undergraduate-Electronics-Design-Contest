#ifndef KEY_H_
#define KEY_H_

#include "system.h"
#include "unistd.h"//延时函数usleep

#define KEY_INPUT *(volatile unsigned char *) KEY_BASE  //代表按键的输入地址地址

//#define KEY_INPUT *(volatile unsigned long *)(KEY_BASE | (1 << 31))//开二级缓存时

extern void key(void);

#endif /* KEY_H_ */
