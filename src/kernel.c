#include "peripherals/mini_UART.h"
#include "mm/utils.h"
#include "util/printf.h"
#include "interrupts/irq.h"

void kernel_main()
{
    uart_init();
    init_printf(0,uart_putc);
    int el = get_el();
    printf("Exception level: %d \r\n", el);
    printf("Hello world!\n");


    irq_init_vectors();
    enable_interrupt_controller();
    
    irq_enable();

    // printf("vector table address: %d", irq_init_vectors());
    while (1){
        // uart_write("Hello world!\n");
       
    }
    printf("does it skip!\n");
}