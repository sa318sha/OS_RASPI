#include "mini_UART.h"
#include "utils.h"
#include "printf.h"
#include "peripherals/aux.h"

void kernel_main()
{
    uart_init();
    struct AuxRegs* aux = (struct AuxRegs*)(AUX_BASE);
    aux->enables
    init_printf(0,uart_putc);
    int el = get_el();
    printf("Exception level: %d \r\n", el);
    uart_write("Hello world!\n");
    while (1){
        uart_writeByte(uart_readByte());
    }
}