#include "util/printf.h"
#include "interrupts/irq.h"
#include "util/common.h"
#include "peripherals/interrupts.h"
#include "peripherals/aux_addresses.h"
#include "peripherals/mini_UART.h"
#include "peripherals/timer_addresses.h"

const u32 interval_1 = CLOCKHZ;
u32 cur_val_1=0;
void timer_init(){
    cur_val_1 = TIMER_REGS->CLO;
    cur_val_1 += interval_1;
    TIMER_REGS->COMPARE[1] = cur_val_1;
}