#include "util/printf.h"
#include "util/common.h"
#include "peripherals/addresses/interrupts_addresses.h"
#include "peripherals/addresses/aux_addresses.h"
#include "peripherals/irq.h"
#include "peripherals/mini_UART.h"
#include "peripherals/system_timer.h"
// #include "interrupts/interrupt_defines.h"

const static char ERROR_MESSAGES[16][32] = {
    "SYNC_INVALID_EL1t",
    "IRQ_INVALID_EL1t",  
    "FIQ_INVALID_EL1t",   
    "ERROR_INVALID_EL1t",  
    "SYNC_INVALID_EL1h",   
    "IRQ_INVALID_EL1h",   
    "FIQ_INVALID_EL1h",
    "ERROR_INVALID_EL1h",
    "SYNC_INVALID_EL0_32", 
    "IRQ_INVALID_EL0_32",   
    "FIQ_INVALID_EL0_32",    
    "ERROR_INVALID_EL0_32",   
    "SYNC_INVALID_EL0_64", 
    "IRQ_INVALID_EL0_64", 
    "FIQ_INVALID_EL0_64", 
    "ERROR_INVALID_EL0_64"
};


void show_invalid_entry_message(u64 type, u64 status, u64 address){
    printf("ERROR CAUGHT OF TYPE: %s  (%d)  \nStatus Register: %X\nAddress location: %X\n",ERROR_MESSAGES[type], type, status, address );
    printf("terminating program...");

}

void enable_interrupt_controller(){

    //setting only the aux for now
    IRQ_ARMC_REGS->PROCESSOR[0].IRQ_SET_EN[0] = AUX_IRQ | SYS_TIMER_1_IRQ;
}

//method called when there is a irq interrupt that the interrupt controller allows
void handle_irq(){
    u64 irq;

    irq = IRQ_ARMC_REGS->PROCESSOR[0].IRQ_PENDING[0];
    printf("IRQ VALUES: %X\n",irq);
    while(irq){
        if(irq & AUX_IRQ){
            irq &= ~AUX_IRQ;
            handle_uart();
        }

        if(irq & SYS_TIMER_1_IRQ){
            irq &= ~(SYS_TIMER_1_IRQ);
            handle_timer_1();
        }



    }
    
    

}