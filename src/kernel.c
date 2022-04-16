#include "mini_UART_definitions.h"
#include "utils.h"
#include "printf.h"
#include "mm.h"
void main()
{
    uart_init();
    
    init_printf(0,uart_putc);
    int el = get_el();
    printf("Exception level: %d \r\n", el);
    uart_write("Hello world!\n");
    while (1){
        uart_writeByte(uart_readByte());
    }
}