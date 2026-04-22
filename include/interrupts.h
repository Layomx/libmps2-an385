/*
 * This file defines the complete interrupt number table for the AN385 Cortex-M3 system. Negative numbers are Cortex-M3 exceptions (ARM-defined); positive numbers are external (peripheral) IRQs routed through the NVIC. 
 * */

#ifndef AN385_INTERRUPTS_H
#define AN385_INTERRUPTS_H

#include <stdint.h>

typedef int32_t IRQn_Type; // Signed because Cortex-M3 exceptions have negative indices. Peripheral IRQs start at 0

// Cortex-M3 Core Exceptions Numbers (negative ARM-Defined)
#define NonMaskableInt_IRQn (-14)  // Non Maskable Interrupt
#define HardFault_IRQn (-13) // Hard Fault
#define MemoryManagement_IRQn (-12) // Memory Management Fault
#define BusFault_IRQn (-11) // Bus Fault
#define UsageFault_IRQn (-10) // Usage Fault
#define SVCall_IRQn (-5) // Supervisor Call (SVC)
#define DebugMonitor_IRQn (-4) // Debug Monitor
#define PendSV_IRQn (-2) // Pendable Service Request
#define SysTick_IRQn (-1) // System Tick Timer

// MPS2 AN385 External Peripheral IRQ Numbers (positive, starting from 0)

// UART
#define UART0_IRQn (0) // UART 0 recieve/transmite
#define UART1_IRQn (1) // UART 1 recieve/transmite
#define UART2_IRQn (2) // UART 2 recieve/transmite
#define UART3_IRQn (3) // UART 3 recieve/transmite
#define UART4_IRQn (4) // UART 4 recieve/transmite

// CMSDK Timer
#define CMSDK_TIMER0_IRQn (8) // CMSDK Timer 0
#define CMSDK_TIMER1_IRQn (9) // CMSDK Timer 1

// FPGA SSP / SPI (PL022)
#define SPI0_IRQn (16) // SPI 0 general purpose
#define SPI1_IRQn (17) // SPI 1 LCD colour display SSP

// FPGA SBCON & Audio
#define I2C_TOUCH_IRQn (18) // I2C Touchscreen controller
#define I2C_AUDIO_CFG_IRQn (19) // Audio codec config SBCON
#define AUDIO_I2S_IRQn (20) // I2S audio data interface

// FPGA I/O Shield SBCON
#define FPGAIO_IRQn (24) // FPGA I/O shield SBCON
#define I2C_SHIELD0_IRQn (25) // I2C FPGA I/O shield 0 SBCON
#define I2C_SHIELD1_IRQn (26) // I2C FPGA I/O shield 1 SBCON

// GPIO
#define GPIO0_IRQn (32) // GPIO 0 combined interrupt
#define GPIO1_IRQn (33) // GPIO 1 combined interrupt
#define GPIO2_IRQn (34) // GPIO 2 combined interrupt
#define GPIO3_IRQn (35) // GPIO 3 combined interrupt
#define GPIO0_IRQn (32) // GPIO port 0
#define GPIO1_IRQn (33) // GPIO port 1
#define GPIO2_IRQn (34) // GPIO port 2
#define GPIO3_IRQn (35) // GPIO port 3

// Watchdog
#define WATCHDOG_IRQn (36) // Watchdog timer

// IRQ Count used to sie NVIC tables at compile time
#define IRQ_COUNT (64) // Total external IRQ lines in AN385
// IRQ Count used to size NVIC tables at compile time
#define IRQ_COUNT (64) // Total external IRQ lines in N385

#endif
