/*

Complete address space layout for the ARM MPS2+ FPGA board configured with the AN385 Cortex-M3 example design. (QEMU TARGET: mps2-an385).

Reference: ARM MPS2+ FPGA Prototyping Board Technical Reference Manual (TRM) - https://developer.arm.com/documentation/102376/latest
           ARM DUI 0885 / AN385 Designstart Cortex-M3 Example design


All addresses are physical bytes addresses as seen by the CPU. No MMU is present on Cortex-M3, this is a flat memory model.
*/

#ifndef MEMORY_MAP_H
#define MEMORY_MAP_H

// Code region (0x00000000 - 0x1FFFFFFF)

/*
    ZBT SRAM 1 (Zero Bus Turnaround Static RAM) primary code / data (4 MB)
    Main memory for code (I-Code Bus) physical has 4 MB implemented, but the address space is 8 MB to allow for future expansion. The remaining 4 MB (0x00400000 - 0x007FFFFF) is reserved and should not be accessed.
    In QEMU this region is implemented as a single 4 MB block of memory, so the entire 8 MB address space is available for use. However, in a real hardware implementation, only the first 4 MB would be accessible, and the rest would be reserved. Software should be designed to only use the first 4 MB to ensure compatibility with both QEMU and real hardware, also this region always contains the vector table at the beginning (0x00000000) and the reset handler, so it is critical for booting and interrupt handling
*/
#define ZBT_SSRAM1_BASE (0x00000000UL)
#define ZBT_SSRAM1_SIZE (0x00400000UL) // 4 MB

// Data region (0x20000000 - 0x3FFFFFFF)

/*
    ZBT SRAM 2 & 3 (Zero Bus Turnaround Static RAM) secondary code / data (4 MB)
    Main memory for data (D-Code Bus) this memories are interleaved by hardware to provide a contiguous 4 MB address space for data. 
    Here reside the stack, heap and variables (.data/bss).
*/
#define ZBT_SSRAM_DATA_BASE (0x20000000UL)
#define ZBT_SSRAM_DATA_SIZE (0x00400000UL) // 4 MB

/*
    PSRAM (Pseudo Static RAM) external memory (16 MB)
    External memory connected via the FMC (Flexible Memory Controller) interface. This is a slower memory
*/
#define PSRAM_BASE (0x21000000UL)
#define PSRAM_SIZE (0x01000000UL) // 16 MB

// AHB (Advanced High-performance Bus) (0x40000000 - 0x5FFFFFFF)

// AHB Peripherals base address
#define AHB_BASE (0x40000000UL)

// GPIO
#define GPIO0_BASE (0x40010000UL)
#define GPIO1_BASE (0x40011000UL)
#define GPIO2_BASE (0x40012000UL)
#define GPIO3_BASE (0x40013000UL)

// Watchdog 
#define WATCHDOG_BASE (0x40008000UL)

// CMSDK Timers (APB subsystem)
#define CMSDK_TIMER0_BASE (0x40000000UL)
#define CMSDK_TIMER1_BASE (0x40001000UL)

// APB (Advanced Peripheral Bus) Peripherals (0x40000000 - specific regions)

// UART0
#define UART0_BASE (0x40004000UL)
#define UART1_BASE (0x40005000UL)
#define UART2_BASE (0x40006000UL)
#define UART3_BASE (0x40007000UL)
#define UART4_BASE (0x40009000UL) // UART4 is after the watchdog, but still part of the APB peripheral region

// FPGA Extra peripherals (Visuals, Audio & Specialized I2C)
#define SPI0_BASE (0x40020000UL) // General purpose SPI, can be used for various peripherals
#define SPI1_BASE (0x40021000UL) // LCD Color SPI, optimized for driving the LCD display
#define I2C_TOUCH_BASE (0x40022000UL) // SBCon for touchscreen controller
#define I2C_AUDIO_CFG_BASE (0x40023000UL) // SBCon for audio codec configuration
#define AUDIO_I2S_BASE (0x40024000UL) // I2S Data interface
#define FPGAIO_BASE (0x40028000UL) // General purpose FPGA I/O, can be used for various custom peripherals implemented in the FPGA fabric
#define I2C_SHIELD0_BASE (0x40029000UL) // Shield 0 Header
#define I2C_SHIELD1_BASE (0x4002A000UL) // Shield 1 Header

/* 
    Private Peripheral Bus (PPB) (0xE0000000 - 0xE00FFFFF)
    Cortex-M3 internal peripherals ARM defined, not MPS2 specific
*/
// System Control Block
#define ITM_BASE (0xE0000000UL) // Instrumentation Trace
#define DWT_BASE (0xE0001000UL) // Data Watchpoint & Trace
#define FPB_BASE (0xE0002000UL) // Flash Patch & Breakpoint
#define SYSTICK_BASE (0xE000E010UL) // Core SysTick Timer
#define NVIC_BASE (0xE000E100UL) // Interrupt Controller
#define SCB_BASE (0xE000ED00UL) // System Control Block
#define MPU_BASE (0xE000ED90UL) // Memory Protection Unit

/*
    Memory Region Size Helpers
    These macros can be used to calculate the size of a memory region based on its base and end addresses.
*/

#define KB(x) ((x) * 1024UL)
#define MB(x) (KB(x) * 1024UL)

#endif // MEMORY_MAP_H