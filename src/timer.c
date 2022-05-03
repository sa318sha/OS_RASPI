#include "util/printf.h"
#include "util/common.h"
#include "peripherals/addresses/system_timer_addresses.h"
#include "peripherals/addresses/interrupts_addresses.h"

const u32 interval_1 = CLOCKHZ;
u32 cur_val_1=0;
void timer_init(){
    cur_val_1 = SYS_TIMER_REGS->CLO;
    cur_val_1 += interval_1;
    SYS_TIMER_REGS->COMPARE[1] = cur_val_1;
}

void handle_timer_1(){
    
    cur_val_1 += interval_1;
    SYS_TIMER_REGS->COMPARE[1] = cur_val_1;
    SYS_TIMER_REGS->CS |= SYS_TIMER_1_IRQ;

    printf("1 second has passed\n");
}