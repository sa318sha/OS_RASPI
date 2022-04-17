#ifndef UART_DEFINITIONS
#define UART_DEFINITIONS


#include "base_addresses.h"
// #define AUX_OFFSET = MAIN_PERIPHERALS + 0x2215000 //FE215000





// #define SYSTEM_CLOCK_FREQUENCY 500000000
void uart_init();
void uart_write(char *buffer);
void uart_writeByte(unsigned char ch);
void uart_putc(void *p, char c);
unsigned int uart_isWriteByteReady();
unsigned int uart_isReadByteReady();
char uart_readByte();


#endif