#include "peripherals/aux/mini_UART/mini_UART.h"
#include "mm/utils.h"
#include "util/printf.h"


void kernel_main()
{
    uart_init();
    // init_printf(0,uart_putc);
    // int el = get_el();
    // printf("Exception level: %d \r\n", el);
    uart_write("Hello world!\n");
    volatile int i =1;
    while (i){
        // uart_write("Hello world!\n");
        uart_writeByte(uart_readByte());
    }
    uart_write("does it skip!\n");
}