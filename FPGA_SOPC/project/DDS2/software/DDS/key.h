#ifndef KEY_H_
#define KEY_H_

#include "system.h"
#include "unistd.h"//��ʱ����usleep

#define KEY_INPUT *(volatile unsigned char *) KEY_BASE  //�������������ַ��ַ

//#define KEY_INPUT *(volatile unsigned long *)(KEY_BASE | (1 << 31))//����������ʱ

extern void key(void);

#endif /* KEY_H_ */
