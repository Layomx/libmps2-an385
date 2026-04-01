/*

    This is the one header file applications should include to gain access to the complete HDL and PAL for the ARM MPS2+ FPGA board configured with the AN385 Cortex-M3 example design. (QEMU TARGET: mps2-an385).

*/

#ifndef MPS2_AN385_H
#define MPS2_AN385_H

// HDL
#include "memory_map.h"
#include "interrupts.h"

// Boards specific configs
#include "../boards/mps2_an385/mps2_an385_memory.h"
#include "../boards/mps2_an385/mps2_an385_irq.h"

// PAL
#include "peripherals/uart.h"
#include "peripherals/gpio.h"
#include "peripherals/systick.h"

// Lib version
#define MPS2_AN385_HDL_PAL_VERSION_MAJOR (1U)
#define MPS2_AN385_HDL_PAL_VERSION_MINOR (0U)
#define MPS2_AN385_HDL_PAL_VERSION_PATCH (0U)

#endif // MPS2_AN385_H