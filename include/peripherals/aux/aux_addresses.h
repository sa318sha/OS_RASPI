#pragma once

#include "common.h"
#include "peripherals/base_addresses.h"
#define AUX_BASE (PBASE + 0x00215000)
//mini UART
struct AuxRegs {
    vol32 irq_status;
    vol32 enables;
    vol32 reserved[14];
    vol32 mu_io;
    vol32 mu_ier;
    vol32 mu_lcr;
    vol32 mu_lcr;
    vol32 mu_mcr;
    vol32 mu_lsr;
    vol32 mu_scrtch;
    vol32 mu_cntl;
    vol32 mu_stat;
    vol32 mu_baud;

};


#define REGS_AUX ((struct AuxRegs *)(AUX_BASE))





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







