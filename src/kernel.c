#include "peripherals/mini_UART.h"
#include "mm/utils.h"
#include "util/printf.h"
#include "interrupts/irq.h"
#include "peripherals/aux_addresses.h"


void kernel_main()
{
    init_printf(0,uart_putc);
    uart_init();
    
    int el = get_el();
    printf("Exception level: %d \r\n", el);
    printf("Hello world!\n");


    irq_init_vectors();
    enable_interrupt_controller();
    
    irq_enable();
    printf("enabled irq\n\n");
    printf("AUX_MU_LSR: %X\n\n",REGS_AUX->AUX_MU_LSR);
    // printf("vector table address: %d", irq_init_vectors());
    while (1){

        if(REGS_AUX->AUX_MU_LSR & 0x1){
            printf("%X\n",REGS_AUX->AUX_MU_LSR);
            printf("yes\n");
        }
        // uart_write("Hello world!\n");
       
    }
    printf("does it skip!\n");
}