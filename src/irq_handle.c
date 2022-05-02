#include "util/printf.h"
#include "interrupts/irq.h"
#include "util/common.h"
#include "peripherals/interrupts.h"
#include "peripherals/aux_addresses.h"
#include "peripherals/mini_UART.h"
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
    IRQ_ARMC_REGS->PROCESSOR[0].IRQ_SET_EN[0] = AUX_IRQ;
}
void handle_irq(){
    u64 irq;

    irq = IRQ_ARMC_REGS->PROCESSOR[0].IRQ_PENDING[0];
    printf("IRQ VALUES: %X\n",irq);
    while(irq){
        if(irq & AUX_IRQ){
        irq &= ~AUX_IRQ;
        printf("recieved byte: %X",(REGS_AUX->AUX_MU_IO & 0xFF));
        while((REGS_AUX->AUX_MU_IIR & 4)==4 ){
            printf("UART RECIEVED: ");
            uart_writeByte(uart_readByte());
            printf("\n");
        }

        }
    }
    
    

}