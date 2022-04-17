#include "mini_UART.h"
#include "io.h"
#include "gpio.h"

void uart_init(){
    mmio_write(AUX_ENABLES, 1); //enable UART1
    mmio_write(AUX_MU_IER_REG, 0);
    mmio_write(AUX_MU_CNTL_REG, 0);
    mmio_write(AUX_MU_LCR_REG, 3); //8 bits
    mmio_write(AUX_MU_MCR_REG, 0);
    mmio_write(AUX_MU_IER_REG, 0);
    mmio_write(AUX_MU_IIR_REG, 0xC6); //disable interrupts
    mmio_write(AUX_MU_BAUD_REG, AUX_MU_BAUD_RATE(115200));
    gpio_select(14,5);
    gpio_select(15,5);
    mmio_write(AUX_MU_CNTL_REG, 3); //enable RX/TX

}
void uart_write(char *buffer){
    while (*buffer != '\0') {
       if (*buffer == '\n') uart_writeByte('\r');
       uart_writeByte(*buffer);
       buffer++;
    }
}
unsigned int uart_isWriteByteReady() { return mmio_read(AUX_MU_LSR_REG) & 0x20; }
unsigned int uart_isReadByteReady() { return mmio_read(AUX_MU_LSR_REG) & 0x01; }


void uart_writeByte(unsigned char ch) {
    while (!uart_isWriteByteReady()); 
    mmio_write(AUX_MU_IO_REG, (unsigned int)ch);
}

void uart_putc(void *p, char c){
    uart_writeByte(c);
}

char uart_readByte(){
    while(!uart_isReadByteReady());
    return (mmio_read(AUX_MU_IO_REG)&0xFF);
}