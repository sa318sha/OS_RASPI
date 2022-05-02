#pragma once

#include "util/common.h"
#include "peripherals/addresses/base_addresses.h"

#define ARMC_BASE       (PBASE + 0xb000)


typedef struct _IRQ_PROCESSOR{
    vol32 IRQ_PENDING[3];
    vol32 RESERVED1;
    vol32 IRQ_SET_EN[3];
    vol32 RESERVED2;
    vol32 IRQ_CLR_EN[3];
    vol32 RESERVED3;
    vol32 IRQ_STATUS[3];
} IRQ_PROCESSOR;

struct ARM_C_IRQ_REGS{
    IRQ_PROCESSOR PROCESSOR[4];

};

#define IRQ_ARMC_REGS ((struct ARM_C_IRQ_REGS *) (ARMC_BASE +0x200))
enum VC_IRQ{
    SYS_TIMER_0_IRQ = (1<<0),
    SYS_TIMER_1_IRQ = (1<<1),
    SYS_TIMER_2_IRQ = (1<<2),
    SYS_TIMER_3_IRQ = (1<<3),
    AUX_IRQ = (1<<29), 
    ARM_IRQ = (1<<30),
};
