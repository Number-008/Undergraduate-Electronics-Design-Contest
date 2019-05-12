/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2' in SOPC Builder design 'NIOS2'
 * SOPC Builder design path: F:/Qsys/DSO_2014_1/NIOS2.sopcinfo
 *
 * Generated: Thu May 15 17:47:05 CST 2014
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CNT_EN configuration
 *
 */

#define ALT_MODULE_CLASS_CNT_EN altera_avalon_pio
#define CNT_EN_BASE 0x24a0
#define CNT_EN_BIT_CLEARING_EDGE_REGISTER 0
#define CNT_EN_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CNT_EN_CAPTURE 0
#define CNT_EN_DATA_WIDTH 1
#define CNT_EN_DO_TEST_BENCH_WIRING 0
#define CNT_EN_DRIVEN_SIM_VALUE 0
#define CNT_EN_EDGE_TYPE "NONE"
#define CNT_EN_FREQ 100000000
#define CNT_EN_HAS_IN 0
#define CNT_EN_HAS_OUT 1
#define CNT_EN_HAS_TRI 0
#define CNT_EN_IRQ -1
#define CNT_EN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CNT_EN_IRQ_TYPE "NONE"
#define CNT_EN_NAME "/dev/CNT_EN"
#define CNT_EN_RESET_VALUE 1
#define CNT_EN_SPAN 16
#define CNT_EN_TYPE "altera_avalon_pio"


/*
 * CNT_IRQ configuration
 *
 */

#define ALT_MODULE_CLASS_CNT_IRQ altera_avalon_pio
#define CNT_IRQ_BASE 0x2490
#define CNT_IRQ_BIT_CLEARING_EDGE_REGISTER 0
#define CNT_IRQ_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CNT_IRQ_CAPTURE 0
#define CNT_IRQ_DATA_WIDTH 1
#define CNT_IRQ_DO_TEST_BENCH_WIRING 0
#define CNT_IRQ_DRIVEN_SIM_VALUE 0
#define CNT_IRQ_EDGE_TYPE "NONE"
#define CNT_IRQ_FREQ 100000000
#define CNT_IRQ_HAS_IN 1
#define CNT_IRQ_HAS_OUT 0
#define CNT_IRQ_HAS_TRI 0
#define CNT_IRQ_IRQ -1
#define CNT_IRQ_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CNT_IRQ_IRQ_TYPE "NONE"
#define CNT_IRQ_NAME "/dev/CNT_IRQ"
#define CNT_IRQ_RESET_VALUE 1
#define CNT_IRQ_SPAN 16
#define CNT_IRQ_TYPE "altera_avalon_pio"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x1820
#define ALT_CPU_CPU_FREQ 100000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1a
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EXCEPTION_ADDR 0x2000020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 100000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 1
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x1a
#define ALT_CPU_NAME "nios2"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_RESET_ADDR 0x0


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x1820
#define NIOS2_CPU_FREQ 100000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x1a
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EXCEPTION_ADDR 0x2000020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 1
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x1a
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_RESET_ADDR 0x0


/*
 * DIV configuration
 *
 */

#define ALT_MODULE_CLASS_DIV DIV_IP
#define DIV_BASE 0x24f8
#define DIV_IRQ -1
#define DIV_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DIV_NAME "/dev/DIV"
#define DIV_SPAN 4
#define DIV_TYPE "DIV_IP"


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_EPCS_FLASH_CONTROLLER
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_QSYS
#define __DDS_48_IP
#define __DIV_IP
#define __FREQ_MS_DJD
#define __LED_OUT
#define __RAM_READ
#define __RAM_WRET
#define __TFT_IP
#define __TOUCH_SPI


/*
 * KEY configuration
 *
 */

#define ALT_MODULE_CLASS_KEY altera_avalon_pio
#define KEY_BASE 0x24c0
#define KEY_BIT_CLEARING_EDGE_REGISTER 0
#define KEY_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KEY_CAPTURE 0
#define KEY_DATA_WIDTH 8
#define KEY_DO_TEST_BENCH_WIRING 0
#define KEY_DRIVEN_SIM_VALUE 0
#define KEY_EDGE_TYPE "NONE"
#define KEY_FREQ 100000000
#define KEY_HAS_IN 0
#define KEY_HAS_OUT 0
#define KEY_HAS_TRI 1
#define KEY_IRQ -1
#define KEY_IRQ_INTERRUPT_CONTROLLER_ID -1
#define KEY_IRQ_TYPE "NONE"
#define KEY_NAME "/dev/KEY"
#define KEY_RESET_VALUE 255
#define KEY_SPAN 16
#define KEY_TYPE "altera_avalon_pio"


/*
 * LED configuration
 *
 */

#define ALT_MODULE_CLASS_LED LED_OUT
#define LED_BASE 0x2400
#define LED_IRQ -1
#define LED_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LED_NAME "/dev/LED"
#define LED_SPAN 32
#define LED_TYPE "LED_OUT"


/*
 * RAM_READ configuration
 *
 */

#define ALT_MODULE_CLASS_RAM_READ RAM_READ
#define RAM_READ_BASE 0x1000
#define RAM_READ_IRQ -1
#define RAM_READ_IRQ_INTERRUPT_CONTROLLER_ID -1
#define RAM_READ_NAME "/dev/RAM_READ"
#define RAM_READ_SPAN 2048
#define RAM_READ_TYPE "RAM_READ"


/*
 * RAM_WR configuration
 *
 */

#define ALT_MODULE_CLASS_RAM_WR RAM_WRET
#define RAM_WR_BASE 0x2000
#define RAM_WR_IRQ -1
#define RAM_WR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define RAM_WR_NAME "/dev/RAM_WR"
#define RAM_WR_SPAN 1024
#define RAM_WR_TYPE "RAM_WRET"


/*
 * RAM_WREN configuration
 *
 */

#define ALT_MODULE_CLASS_RAM_WREN altera_avalon_pio
#define RAM_WREN_BASE 0x24b0
#define RAM_WREN_BIT_CLEARING_EDGE_REGISTER 0
#define RAM_WREN_BIT_MODIFYING_OUTPUT_REGISTER 0
#define RAM_WREN_CAPTURE 0
#define RAM_WREN_DATA_WIDTH 1
#define RAM_WREN_DO_TEST_BENCH_WIRING 0
#define RAM_WREN_DRIVEN_SIM_VALUE 0
#define RAM_WREN_EDGE_TYPE "NONE"
#define RAM_WREN_FREQ 100000000
#define RAM_WREN_HAS_IN 0
#define RAM_WREN_HAS_OUT 1
#define RAM_WREN_HAS_TRI 0
#define RAM_WREN_IRQ -1
#define RAM_WREN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define RAM_WREN_IRQ_TYPE "NONE"
#define RAM_WREN_NAME "/dev/RAM_WREN"
#define RAM_WREN_RESET_VALUE 1
#define RAM_WREN_SPAN 16
#define RAM_WREN_TYPE "altera_avalon_pio"


/*
 * SPI configuration
 *
 */

#define ALT_MODULE_CLASS_SPI Touch_SPI
#define SPI_BASE 0x2460
#define SPI_IRQ -1
#define SPI_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SPI_NAME "/dev/SPI"
#define SPI_SPAN 16
#define SPI_TYPE "Touch_SPI"


/*
 * SSD1298 configuration
 *
 */

#define ALT_MODULE_CLASS_SSD1298 TFT_IP
#define SSD1298_BASE 0x24d0
#define SSD1298_IRQ -1
#define SSD1298_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SSD1298_NAME "/dev/SSD1298"
#define SSD1298_SPAN 16
#define SSD1298_TYPE "TFT_IP"


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone II"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag"
#define ALT_STDERR_BASE 0x24e8
#define ALT_STDERR_DEV jtag
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag"
#define ALT_STDIN_BASE 0x24e8
#define ALT_STDIN_DEV jtag
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag"
#define ALT_STDOUT_BASE 0x24e8
#define ALT_STDOUT_DEV jtag
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "NIOS2"


/*
 * dds configuration
 *
 */

#define ALT_MODULE_CLASS_dds DDS_48_IP
#define DDS_BASE 0x2450
#define DDS_IRQ -1
#define DDS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DDS_NAME "/dev/dds"
#define DDS_SPAN 16
#define DDS_TYPE "DDS_48_IP"


/*
 * djd configuration
 *
 */

#define ALT_MODULE_CLASS_djd freq_ms_djd
#define DJD_BASE 0x24e0
#define DJD_IRQ -1
#define DJD_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DJD_NAME "/dev/djd"
#define DJD_SPAN 8
#define DJD_TYPE "freq_ms_djd"


/*
 * epcs_flash configuration
 *
 */

#define ALT_MODULE_CLASS_epcs_flash altera_avalon_epcs_flash_controller
#define EPCS_FLASH_BASE 0x0
#define EPCS_FLASH_IRQ 0
#define EPCS_FLASH_IRQ_INTERRUPT_CONTROLLER_ID 0
#define EPCS_FLASH_NAME "/dev/epcs_flash"
#define EPCS_FLASH_REGISTER_OFFSET 512
#define EPCS_FLASH_SPAN 2048
#define EPCS_FLASH_TYPE "altera_avalon_epcs_flash_controller"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER
#define ALT_TIMESTAMP_CLK none


/*
 * jtag configuration
 *
 */

#define ALT_MODULE_CLASS_jtag altera_avalon_jtag_uart
#define JTAG_BASE 0x24e8
#define JTAG_IRQ 1
#define JTAG_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_NAME "/dev/jtag"
#define JTAG_READ_DEPTH 64
#define JTAG_READ_THRESHOLD 8
#define JTAG_SPAN 8
#define JTAG_TYPE "altera_avalon_jtag_uart"
#define JTAG_WRITE_DEPTH 64
#define JTAG_WRITE_THRESHOLD 8


/*
 * sdram configuration
 *
 */

#define ALT_MODULE_CLASS_sdram altera_avalon_new_sdram_controller
#define SDRAM_BASE 0x2000000
#define SDRAM_CAS_LATENCY 3
#define SDRAM_CONTENTS_INFO
#define SDRAM_INIT_NOP_DELAY 0.0
#define SDRAM_INIT_REFRESH_COMMANDS 2
#define SDRAM_IRQ -1
#define SDRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDRAM_IS_INITIALIZED 1
#define SDRAM_NAME "/dev/sdram"
#define SDRAM_POWERUP_DELAY 100.0
#define SDRAM_REFRESH_PERIOD 15.625
#define SDRAM_REGISTER_DATA_IN 1
#define SDRAM_SDRAM_ADDR_WIDTH 0x17
#define SDRAM_SDRAM_BANK_WIDTH 2
#define SDRAM_SDRAM_COL_WIDTH 9
#define SDRAM_SDRAM_DATA_WIDTH 16
#define SDRAM_SDRAM_NUM_BANKS 4
#define SDRAM_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_SDRAM_ROW_WIDTH 12
#define SDRAM_SHARED_DATA 0
#define SDRAM_SIM_MODEL_BASE 0
#define SDRAM_SPAN 16777216
#define SDRAM_STARVATION_INDICATOR 0
#define SDRAM_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_TYPE "altera_avalon_new_sdram_controller"
#define SDRAM_T_AC 5.5
#define SDRAM_T_MRD 3
#define SDRAM_T_RCD 20.0
#define SDRAM_T_RFC 70.0
#define SDRAM_T_RP 20.0
#define SDRAM_T_WR 14.0


/*
 * sysid configuration
 *
 */

#define ALT_MODULE_CLASS_sysid altera_avalon_sysid_qsys
#define SYSID_BASE 0x24f0
#define SYSID_ID 0
#define SYSID_IRQ -1
#define SYSID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_NAME "/dev/sysid"
#define SYSID_SPAN 8
#define SYSID_TIMESTAMP 1400146849
#define SYSID_TYPE "altera_avalon_sysid_qsys"


/*
 * timer configuration
 *
 */

#define ALT_MODULE_CLASS_timer altera_avalon_timer
#define TIMER_ALWAYS_RUN 0
#define TIMER_BASE 0x2420
#define TIMER_COUNTER_SIZE 32
#define TIMER_FIXED_PERIOD 0
#define TIMER_FREQ 100000000
#define TIMER_IRQ 2
#define TIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_LOAD_VALUE 99999
#define TIMER_MULT 0.0010
#define TIMER_NAME "/dev/timer"
#define TIMER_PERIOD 1
#define TIMER_PERIOD_UNITS "ms"
#define TIMER_RESET_OUTPUT 0
#define TIMER_SNAPSHOT 1
#define TIMER_SPAN 32
#define TIMER_TICKS_PER_SEC 1000.0
#define TIMER_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_TYPE "altera_avalon_timer"


/*
 * trig_d configuration
 *
 */

#define ALT_MODULE_CLASS_trig_d altera_avalon_pio
#define TRIG_D_BASE 0x2470
#define TRIG_D_BIT_CLEARING_EDGE_REGISTER 0
#define TRIG_D_BIT_MODIFYING_OUTPUT_REGISTER 0
#define TRIG_D_CAPTURE 0
#define TRIG_D_DATA_WIDTH 8
#define TRIG_D_DO_TEST_BENCH_WIRING 0
#define TRIG_D_DRIVEN_SIM_VALUE 0
#define TRIG_D_EDGE_TYPE "NONE"
#define TRIG_D_FREQ 100000000
#define TRIG_D_HAS_IN 0
#define TRIG_D_HAS_OUT 1
#define TRIG_D_HAS_TRI 0
#define TRIG_D_IRQ -1
#define TRIG_D_IRQ_INTERRUPT_CONTROLLER_ID -1
#define TRIG_D_IRQ_TYPE "NONE"
#define TRIG_D_NAME "/dev/trig_d"
#define TRIG_D_RESET_VALUE 127
#define TRIG_D_SPAN 16
#define TRIG_D_TYPE "altera_avalon_pio"


/*
 * trig_s configuration
 *
 */

#define ALT_MODULE_CLASS_trig_s altera_avalon_pio
#define TRIG_S_BASE 0x2480
#define TRIG_S_BIT_CLEARING_EDGE_REGISTER 0
#define TRIG_S_BIT_MODIFYING_OUTPUT_REGISTER 0
#define TRIG_S_CAPTURE 0
#define TRIG_S_DATA_WIDTH 1
#define TRIG_S_DO_TEST_BENCH_WIRING 0
#define TRIG_S_DRIVEN_SIM_VALUE 0
#define TRIG_S_EDGE_TYPE "NONE"
#define TRIG_S_FREQ 100000000
#define TRIG_S_HAS_IN 0
#define TRIG_S_HAS_OUT 1
#define TRIG_S_HAS_TRI 0
#define TRIG_S_IRQ -1
#define TRIG_S_IRQ_INTERRUPT_CONTROLLER_ID -1
#define TRIG_S_IRQ_TYPE "NONE"
#define TRIG_S_NAME "/dev/trig_s"
#define TRIG_S_RESET_VALUE 1
#define TRIG_S_SPAN 16
#define TRIG_S_TYPE "altera_avalon_pio"


/*
 * ucosii configuration
 *
 */

#define OS_ARG_CHK_EN 1
#define OS_CPU_HOOKS_EN 1
#define OS_DEBUG_EN 1
#define OS_EVENT_NAME_SIZE 32
#define OS_FLAGS_NBITS 16
#define OS_FLAG_ACCEPT_EN 1
#define OS_FLAG_DEL_EN 1
#define OS_FLAG_EN 1
#define OS_FLAG_NAME_SIZE 32
#define OS_FLAG_QUERY_EN 1
#define OS_FLAG_WAIT_CLR_EN 1
#define OS_LOWEST_PRIO 20
#define OS_MAX_EVENTS 60
#define OS_MAX_FLAGS 20
#define OS_MAX_MEM_PART 60
#define OS_MAX_QS 20
#define OS_MAX_TASKS 10
#define OS_MBOX_ACCEPT_EN 1
#define OS_MBOX_DEL_EN 1
#define OS_MBOX_EN 1
#define OS_MBOX_POST_EN 1
#define OS_MBOX_POST_OPT_EN 1
#define OS_MBOX_QUERY_EN 1
#define OS_MEM_EN 1
#define OS_MEM_NAME_SIZE 32
#define OS_MEM_QUERY_EN 1
#define OS_MUTEX_ACCEPT_EN 1
#define OS_MUTEX_DEL_EN 1
#define OS_MUTEX_EN 1
#define OS_MUTEX_QUERY_EN 1
#define OS_Q_ACCEPT_EN 1
#define OS_Q_DEL_EN 1
#define OS_Q_EN 1
#define OS_Q_FLUSH_EN 1
#define OS_Q_POST_EN 1
#define OS_Q_POST_FRONT_EN 1
#define OS_Q_POST_OPT_EN 1
#define OS_Q_QUERY_EN 1
#define OS_SCHED_LOCK_EN 1
#define OS_SEM_ACCEPT_EN 1
#define OS_SEM_DEL_EN 1
#define OS_SEM_EN 1
#define OS_SEM_QUERY_EN 1
#define OS_SEM_SET_EN 1
#define OS_TASK_CHANGE_PRIO_EN 1
#define OS_TASK_CREATE_EN 1
#define OS_TASK_CREATE_EXT_EN 1
#define OS_TASK_DEL_EN 1
#define OS_TASK_IDLE_STK_SIZE 512
#define OS_TASK_NAME_SIZE 32
#define OS_TASK_PROFILE_EN 1
#define OS_TASK_QUERY_EN 1
#define OS_TASK_STAT_EN 1
#define OS_TASK_STAT_STK_CHK_EN 1
#define OS_TASK_STAT_STK_SIZE 512
#define OS_TASK_SUSPEND_EN 1
#define OS_TASK_SW_HOOK_EN 1
#define OS_TASK_TMR_PRIO 0
#define OS_TASK_TMR_STK_SIZE 512
#define OS_THREAD_SAFE_NEWLIB 1
#define OS_TICKS_PER_SEC TIMER_TICKS_PER_SEC
#define OS_TICK_STEP_EN 1
#define OS_TIME_DLY_HMSM_EN 1
#define OS_TIME_DLY_RESUME_EN 1
#define OS_TIME_GET_SET_EN 1
#define OS_TIME_TICK_HOOK_EN 1
#define OS_TMR_CFG_MAX 16
#define OS_TMR_CFG_NAME_SIZE 16
#define OS_TMR_CFG_TICKS_PER_SEC 10
#define OS_TMR_CFG_WHEEL_SIZE 2
#define OS_TMR_EN 0


/*
 * wren configuration
 *
 */

#define ALT_MODULE_CLASS_wren altera_avalon_pio
#define WREN_BASE 0x2440
#define WREN_BIT_CLEARING_EDGE_REGISTER 0
#define WREN_BIT_MODIFYING_OUTPUT_REGISTER 0
#define WREN_CAPTURE 0
#define WREN_DATA_WIDTH 1
#define WREN_DO_TEST_BENCH_WIRING 0
#define WREN_DRIVEN_SIM_VALUE 0
#define WREN_EDGE_TYPE "NONE"
#define WREN_FREQ 100000000
#define WREN_HAS_IN 0
#define WREN_HAS_OUT 1
#define WREN_HAS_TRI 0
#define WREN_IRQ -1
#define WREN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define WREN_IRQ_TYPE "NONE"
#define WREN_NAME "/dev/wren"
#define WREN_RESET_VALUE 0
#define WREN_SPAN 16
#define WREN_TYPE "altera_avalon_pio"

#endif /* __SYSTEM_H_ */
