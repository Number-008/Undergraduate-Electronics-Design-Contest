/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2' in SOPC Builder design 'Qsys'
 * SOPC Builder design path: F:/Qsys/Qsys_EP2C5/Qsys.sopcinfo
 *
 * Generated: Sun Jul 28 21:15:16 CST 2013
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
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x5820
#define ALT_CPU_CPU_FREQ 100000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0xf
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x2020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 100000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0xf
#define ALT_CPU_NAME "nios2"
#define ALT_CPU_RESET_ADDR 0x5000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x5820
#define NIOS2_CPU_FREQ 100000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0xf
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x2020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0xf
#define NIOS2_RESET_ADDR 0x5000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_EPCS_FLASH_CONTROLLER
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_NIOS2_QSYS
#define __LCD12864_1602
#define __PWM_IP
#define __TOUCH_SPI


/*
 * KEY configuration
 *
 */

#define ALT_MODULE_CLASS_KEY altera_avalon_pio
#define KEY_BASE 0x6060
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
 * LCD12864 configuration
 *
 */

#define ALT_MODULE_CLASS_LCD12864 LCD12864_1602
#define LCD12864_BASE 0x6050
#define LCD12864_IRQ -1
#define LCD12864_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LCD12864_NAME "/dev/LCD12864"
#define LCD12864_SPAN 16
#define LCD12864_TYPE "LCD12864_1602"


/*
 * PWM configuration
 *
 */

#define ALT_MODULE_CLASS_PWM PWM_IP
#define PWM_BASE 0x6010
#define PWM_IRQ -1
#define PWM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PWM_NAME "/dev/PWM"
#define PWM_SPAN 16
#define PWM_TYPE "PWM_IP"


/*
 * PWM2 configuration
 *
 */

#define ALT_MODULE_CLASS_PWM2 PWM_IP
#define PWM2_BASE 0x6000
#define PWM2_IRQ -1
#define PWM2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PWM2_NAME "/dev/PWM2"
#define PWM2_SPAN 16
#define PWM2_TYPE "PWM_IP"


/*
 * RAM configuration
 *
 */

#define ALT_MODULE_CLASS_RAM altera_avalon_onchip_memory2
#define RAM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define RAM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define RAM_BASE 0x2000
#define RAM_CONTENTS_INFO ""
#define RAM_DUAL_PORT 0
#define RAM_GUI_RAM_BLOCK_TYPE "AUTO"
#define RAM_INIT_CONTENTS_FILE "Qsys_RAM"
#define RAM_INIT_MEM_CONTENT 1
#define RAM_INSTANCE_ID "NONE"
#define RAM_IRQ -1
#define RAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define RAM_NAME "/dev/RAM"
#define RAM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define RAM_RAM_BLOCK_TYPE "AUTO"
#define RAM_READ_DURING_WRITE_MODE "DONT_CARE"
#define RAM_SINGLE_CLOCK_OP 0
#define RAM_SIZE_MULTIPLE 1
#define RAM_SIZE_VALUE 8192
#define RAM_SPAN 8192
#define RAM_TYPE "altera_avalon_onchip_memory2"
#define RAM_WRITABLE 1


/*
 * SPI configuration
 *
 */

#define ALT_MODULE_CLASS_SPI Touch_SPI
#define SPI_BASE 0x6040
#define SPI_IRQ -1
#define SPI_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SPI_NAME "/dev/SPI"
#define SPI_SPAN 16
#define SPI_TYPE "Touch_SPI"


/*
 * SPI_CS2 configuration
 *
 */

#define ALT_MODULE_CLASS_SPI_CS2 altera_avalon_pio
#define SPI_CS2_BASE 0x6030
#define SPI_CS2_BIT_CLEARING_EDGE_REGISTER 0
#define SPI_CS2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SPI_CS2_CAPTURE 0
#define SPI_CS2_DATA_WIDTH 1
#define SPI_CS2_DO_TEST_BENCH_WIRING 0
#define SPI_CS2_DRIVEN_SIM_VALUE 0
#define SPI_CS2_EDGE_TYPE "NONE"
#define SPI_CS2_FREQ 100000000
#define SPI_CS2_HAS_IN 0
#define SPI_CS2_HAS_OUT 1
#define SPI_CS2_HAS_TRI 0
#define SPI_CS2_IRQ -1
#define SPI_CS2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SPI_CS2_IRQ_TYPE "NONE"
#define SPI_CS2_NAME "/dev/SPI_CS2"
#define SPI_CS2_RESET_VALUE 1
#define SPI_CS2_SPAN 16
#define SPI_CS2_TYPE "altera_avalon_pio"


/*
 * SPI_CS3 configuration
 *
 */

#define ALT_MODULE_CLASS_SPI_CS3 altera_avalon_pio
#define SPI_CS3_BASE 0x6020
#define SPI_CS3_BIT_CLEARING_EDGE_REGISTER 0
#define SPI_CS3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SPI_CS3_CAPTURE 0
#define SPI_CS3_DATA_WIDTH 1
#define SPI_CS3_DO_TEST_BENCH_WIRING 0
#define SPI_CS3_DRIVEN_SIM_VALUE 0
#define SPI_CS3_EDGE_TYPE "NONE"
#define SPI_CS3_FREQ 100000000
#define SPI_CS3_HAS_IN 0
#define SPI_CS3_HAS_OUT 1
#define SPI_CS3_HAS_TRI 0
#define SPI_CS3_IRQ -1
#define SPI_CS3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SPI_CS3_IRQ_TYPE "NONE"
#define SPI_CS3_NAME "/dev/SPI_CS3"
#define SPI_CS3_RESET_VALUE 1
#define SPI_CS3_SPAN 16
#define SPI_CS3_TYPE "altera_avalon_pio"


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
#define ALT_STDERR "/dev/jtag_uart"
#define ALT_STDERR_BASE 0x6070
#define ALT_STDERR_DEV jtag_uart
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart"
#define ALT_STDIN_BASE 0x6070
#define ALT_STDIN_DEV jtag_uart
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart"
#define ALT_STDOUT_BASE 0x6070
#define ALT_STDOUT_DEV jtag_uart
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "Qsys"


/*
 * epcs configuration
 *
 */

#define ALT_MODULE_CLASS_epcs altera_avalon_epcs_flash_controller
#define EPCS_BASE 0x5000
#define EPCS_IRQ 0
#define EPCS_IRQ_INTERRUPT_CONTROLLER_ID 0
#define EPCS_NAME "/dev/epcs"
#define EPCS_REGISTER_OFFSET 512
#define EPCS_SPAN 2048
#define EPCS_TYPE "altera_avalon_epcs_flash_controller"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 4
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x6070
#define JTAG_UART_IRQ 1
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/jtag_uart"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * sysid configuration
 *
 */

#define ALT_MODULE_CLASS_sysid altera_avalon_sysid_qsys
#define SYSID_BASE 0x6078
#define SYSID_ID 0
#define SYSID_IRQ -1
#define SYSID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_NAME "/dev/sysid"
#define SYSID_SPAN 8
#define SYSID_TIMESTAMP 1375016821
#define SYSID_TYPE "altera_avalon_sysid_qsys"

#endif /* __SYSTEM_H_ */
