#pragma once

#include "util/common.h"
#include "peripherals/base_addresses.h"
#define AUX_BASE (PBASE + 0x00215000)
//mini UART
struct AuxRegs {
    vol32 AUX_IRQ;
    vol32 AUX_ENABLES;
    vol32 reserved[14];
    vol32 AUX_MU_IO;
    vol32 AUX_MU_IER;
    vol32 AUX_MU_IIR;
    vol32 AUX_MU_LCR;
    vol32 AUX_MU_MCR;
    vol32 AUX_MU_LSR;
    vol32 AUX_MU_MSR;
    vol32 AUX_MU_SCRATCH;
    vol32 AUX_MU_CNTL;
    vol32 AUX_MU_STAT;
    vol32 AUX_MU_BAUD;

};


#define REGS_AUX ((struct AuxRegs *)(AUX_BASE))
#define SYSTEM_CLOCK_FREQUENCY 500000000
#define AUX_MU_BAUD_RATE(baud) (SYSTEM_CLOCK_FREQUENCY/(8*baud)-1)



// #define AUX_IRQ (AUX_BASE + 0x0)
// #define AUX_ENABLES (AUX_BASE + 0x04)
// #define AUX_MU_IO_REG (AUX_BASE + 0x40)
// #define AUX_MU_IER_REG (AUX_BASE + 0x44)
// #define AUX_MU_IIR_REG (AUX_BASE + 0x48)
// #define AUX_MU_LCR_REG (AUX_BASE + 0x4c)
// #define AUX_MU_MCR_REG (AUX_BASE + 0x50)
// #define AUX_MU_LSR_REG (AUX_BASE + 0x54)
// #define AUX_MU_MSR_REG (AUX_BASE + 0x58)
// #define AUX_MU_SCRATCH (AUX_BASE + 0x5c)
// #define AUX_MU_CNTL_REG (AUX_BASE + 0x60)
// #define AUX_MU_STAT_REG (AUX_BASE + 0x64)
// #define AUX_MU_BAUD_REG (AUX_BASE + 0x68)

// #define SYSTEM_CLOCK_FREQUENCY 500000000







