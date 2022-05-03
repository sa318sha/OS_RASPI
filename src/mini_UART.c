#include "peripherals/addresses/aux_addresses.h"
#include "peripherals/mini_UART.h"
#include "util/common.h"
#include "mm/basic_mm.h"
#include "peripherals/gpio.h"
#include "mm/utils.h"
#include "util/printf.h"

#define TXD_mini_UART 14
#define RXD_mini_UART 15

void uart_init(){

    gpio_pin_set_func(TXD_mini_UART,GFAlt5);
    gpio_pin_set_func(RXD_mini_UART,GFAlt5);
    gpio_pin_resistor_enable(TXD_mini_UART,GPNORES);
    gpio_pin_resistor_enable(RXD_mini_UART,GPNORES);
    

    REGS_AUX->AUX_ENABLES =1;   //enables mini_uart
    REGS_AUX->AUX_MU_CNTL =0;   //disables transmission-recieving bits
    REGS_AUX->AUX_MU_IER =0xD;    //1st (0) bit enables recieve interrupt 2nd bit enables transmit (1) (swapped order from datasheet)
    // REGS_AUX->AUX_MU_IIR =0xC6; //can be ommited - bit 1:2 are clearing transmit and recieve fifo, bit 0 is check if there is interrupt pending bit 7:6 are read only
                                //for checking if the FIFO of transmit and recieve are enabled
                                //will clear them one of the tutoirals had this value as 0xC6
    REGS_AUX->AUX_MU_LCR =3; // 8 bit transimitting -must be 3 to have it working 
    REGS_AUX->AUX_MU_MCR =0; // setst he recieve line to high by default
    
    // REGS_AUX->AUX_MU_IIR = 0xC6; //disable interrupts
    REGS_AUX->AUX_MU_BAUD = AUX_MU_BAUD_RATE(115200);
    delay(150);
    REGS_AUX->AUX_MU_CNTL =3;   //enables RX/TX

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
    if(c == '\n'){
        uart_writeByte('\r');
    }
    uart_writeByte(c);
}

char uart_readByte(){
    
    while (!(REGS_AUX->AUX_MU_LSR & 1));//{
    //     uart_writeByte('a');
    // }
    return (REGS_AUX->AUX_MU_IO & 0xFF);
}

void handle_uart(){
    // printf("AUX_IRQ register: %X\n", REGS_AUX->AUX_IRQ);
    // printf("interruptstatus byte: %X\n",(REGS_AUX->AUX_MU_IIR & 0xF));
    while((REGS_AUX->AUX_MU_IIR & 4)==4 ){//status register to check if there is a byte pending
            printf("UART RECIEVED: ");
            uart_writeByte((char)uart_readByte());
            printf("\n");
        }
    // printf("AUX_IRQ register: %X\n", REGS_AUX->AUX_IRQ);
    
    // printf("interruptstatus byte: %X\n",(REGS_AUX->AUX_MU_IIR & 0xF));
}
