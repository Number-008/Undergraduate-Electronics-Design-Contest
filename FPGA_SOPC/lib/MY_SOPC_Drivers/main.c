#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "includes.h"                      //uc/os-II总头文件
#include "alt_ucosii_simple_error_check.h"//错误处理软件模块
#include "app.h"
#include "led.h"
#include "key.h"
#include "ili9320.h"
#include "djd.h"
#include "div.h"
#include "dds.h"
#include "altera_avalon_pio_regs.h"

//定义任务栈大小
#define   TASK_STACKSIZE1       4096
#define   TASK_STACKSIZE2       10240
#define   TASK_STACKSIZE3       5120

//定义个任务任务栈
OS_STK    print_task1_stk[TASK_STACKSIZE1];
OS_STK    print_task2_stk[TASK_STACKSIZE2];
OS_STK    print_task3_stk[TASK_STACKSIZE3];

/*分配各任务优先级 */
#define PRINT_TASK1_PRIORITY      	3
#define PRINT_TASK2_PRIORITY      	4
#define PRINT_TASK3_PRIORITY      	5

void PrintTask1(void* pdata)
{

	OS_CPU_SR cpu_sr;
	while(1)
	{
		/*利用临界区来保护共享变量*/
		OS_ENTER_CRITICAL();//关闭总中断
		//OSSchedLock(); /* 停止任务调度 */
		KeyScan();
		OS_EXIT_CRITICAL();//打开总中断
		//OSSchedUnlock(); /* 恢复任务调度 */
		OSTimeDlyHMSM(0,0,0,10);	//延时，让出CPU使用权
	}

}

void PrintTask2(void* pdata)
{
	OS_CPU_SR cpu_sr;
	while(1)
	{
		OS_ENTER_CRITICAL();//关闭总中断
		//OSSchedLock(); /* 停止任务调度 */
		DispWave();
		if(save_control & 0x80)
			DJDaut(cp());
		OS_EXIT_CRITICAL();//打开总中断
		//OSSchedUnlock(); /* 恢复任务调度 */
		OSTimeDlyHMSM(0,0,0,15);
	}

}
void PrintTask3(void* pdata)
{
	OS_CPU_SR cpu_sr;
	while(1)
	{
		OS_ENTER_CRITICAL();//关闭总中断
		//OSSchedLock(); /* 停止任务调度 */
		if(!(save_control & 0x80))
		{
			 ReadDJD();
			DJDaut(djd_Freq);
		}
		NOT_LED;
		OS_EXIT_CRITICAL();//打开总中断
		//OSSchedUnlock(); /* 恢复任务调度 */
		OSTimeDlyHMSM(0,0,0,25);
	}

}
int main(int argc,char* argv[],char* envp[])
{
	INT8U return_code = OS_NO_ERR;

	OS_CPU_SR cpu_sr;
	OS_ENTER_CRITICAL();//关闭总中断

	IOWR_ALTERA_AVALON_PIO_DATA(TRIG_S_BASE, 0x01);
	IOWR_ALTERA_AVALON_PIO_DATA(TRIG_D_BASE, 127);
	WR_LED(0x09);
	ili9320_Initializtion();
	ili9320_Clear(BLUE);
	WrClkDiv(LCKDIV);
	WrVDiv(VDIV);
	DispFrame();
	DDS_OUT(Freq);
	//IOWR_ALTERA_AVALON_PIO_DATA(TRIG_S_BASE, 0x00);
	IOWR_ALTERA_AVALON_PIO_DATA(RAM_WREN_BASE, 0x01);
	usleep(1);
	IOWR_ALTERA_AVALON_PIO_DATA(CNT_EN_BASE, 0x01);
	usleep(1);
	IOWR_ALTERA_AVALON_PIO_DATA(CNT_EN_BASE, 0x00);
	usleep(1);
	IOWR_ALTERA_AVALON_PIO_DATA(CNT_EN_BASE, 0x01);

	OS_EXIT_CRITICAL();//打开总中断
	//OSInit();
	/*创建任务*/

	return_code = OSTaskCreateExt(PrintTask1,
									  NULL,
									  (void *)&print_task1_stk[TASK_STACKSIZE1],
									  PRINT_TASK1_PRIORITY,
									  PRINT_TASK1_PRIORITY,
									  print_task1_stk,
									  TASK_STACKSIZE1,
									  NULL,
									  0);
		alt_ucosii_check_return_code(return_code);
		return_code = OSTaskCreateExt(PrintTask2,
									  NULL,
									  (void *)&print_task2_stk[TASK_STACKSIZE2],
									  PRINT_TASK2_PRIORITY,
									  PRINT_TASK2_PRIORITY,
									  print_task2_stk,
									  TASK_STACKSIZE2,
									  NULL,
									  0);
		alt_ucosii_check_return_code(return_code);
		return_code = OSTaskCreateExt(PrintTask3,
									  NULL,
									  (void *)&print_task3_stk[TASK_STACKSIZE3],
									  PRINT_TASK3_PRIORITY,
									  PRINT_TASK3_PRIORITY,
									  print_task3_stk,
									  TASK_STACKSIZE3,
									  NULL,
									  0);
		alt_ucosii_check_return_code(return_code);

	OSStart();/*调用OSStart()启动uc/os-II*/
	return 0;
}

