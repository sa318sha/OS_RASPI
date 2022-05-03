#pragma once

#include "util/common.h"
#include "peripherals/addresses/base_addresses.h"

#define CLOCKHZ 1000000 //1mhz

#define TIMER_BASE (PBASE + 0x3000)

struct SYSTEM_TIMER_REGS{
    vol32 CS;
    vol32 CLO;
    vol32 CHI;
    vol32 COMPARE[4];
};

#define SYS_TIMER_REGS ((struct SYSTEM_TIMER_REGS *)(TIMER_BASE))