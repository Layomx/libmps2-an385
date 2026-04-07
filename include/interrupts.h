/*
 * This file defines the complete interrupt number table for the AN385 Cortex-M3 system. Negative numbers are Cortex-M3 exceptions (ARM-defined); positive numbers are external (peripheral) IRQs routed through the NVIC. 
 * */

#ifndef AN385_INTERRUPTS_H
#define AN385_INTERRUPTS_H

#include <stdint.h>

typdef int32_t IRQn_Type; // Signed because Cortex-M3 exceptions have negative indices. Peripheral IRQs start at 0

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








#endif
