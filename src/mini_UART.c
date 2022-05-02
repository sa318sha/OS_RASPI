#include "peripherals/aux_addresses.h"
#include "peripherals/mini_UART.h"
#include "util/common.h"
#include "mm/basic_mm.h"
#include "peripherals/gpio.h"

#define TXD_mini_UART 14
#define RXD_mini_UART 15

void uart_init(){

    gpio_pin_set_func(TXD_mini_UART,GFAlt5);
    gpio_pin_set_func(RXD_mini_UART,GFAlt5);
    gpio_pin_resistor_enable(TXD_mini_UART,GPNORES);
    gpio_pin_resistor_enable(RXD_mini_UART,GPNORES);
    

    REGS_AUX->AUX_ENABLES =1;
    REGS_AUX->AUX_MU_CNTL =0;
    REGS_AUX->AUX_MU_IIR =2;
    REGS_AUX->AUX_MU_LCR =3; // 8 bit transimitting
    REGS_AUX->AUX_MU_MCR =0; // 8 bit transimitting
    
    // REGS_AUX->AUX_MU_IIR = 0xC6; //disable interrupts
    REGS_AUX->AUX_MU_BAUD = AUX_MU_BAUD_RATE(115200);
    // REGS_AUX->AUX_MU_IER
    // mm_write(&REGS_AUX->AUX_ENABLES, 1); //enable UART1
    // mm_write(&REGS_AUX->AUX_MU_IER, 0);
    // mm_write(&REGS_AUX->AUX_MU_CNTL, 0);
    // mm_write(&REGS_AUX->AUX_MU_LCR, 3); //8 bits
    // mm_write(&REGS_AUX->AUX_MU_MCR, 0);
    // mm_write(&REGS_AUX->AUX_MU_IER, 0);
    // mm_write(&REGS_AUX->AUX_MU_IIR, 0xC6); //disable interrupts
    // mm_write(&REGS_AUX->AUX_MU_BAUD, AUX_MU_BAUD_RATE(115200));


    
    // mm_write(&REGS_AUX->AUX_MU_CNTL, 3); //enable RX/TX
    REGS_AUX->AUX_MU_CNTL =3;

    uart_writeByte('\r');
    uart_writeByte('\n');
    uart_writeByte('\r');
    uart_writeByte('\n');
    uart_writeByte('\r');
    uart_writeByte('\n');

}
void uart_write(char *buffer){
    while (*buffer != '\0') {
       if (*buffer == '\n'){
           uart_writeByte('\r');
       } 
       uart_writeByte(*buffer);
       buffer++;
    }
}
// unsigned int uart_isWriteByteReady() { return mm_read(&REGS_AUX->AUX_MU_LSR) & 0x20; }
// unsigned int uart_isReadByteReady() { return mm_read(&REGS_AUX->AUX_MU_LSR) & 0x01; }



void uart_writeByte(char ch) {
    while (!(REGS_AUX->AUX_MU_LSR & 0x20)); 
    REGS_AUX->AUX_MU_IO = ch;
}

void uart_putc(void *p, char c){
    uart_writeByte(c);
}

char uart_readByte(){
    
    while (!(REGS_AUX->AUX_MU_LSR & 1));//{
    //     uart_writeByte('a');
    // }
    return (REGS_AUX->AUX_MU_IO & 0xFF);
}