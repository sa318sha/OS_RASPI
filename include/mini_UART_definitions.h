#ifndef UART_DEFINITIONS
#define UART_DEFINITIONS


#include "base_addresses.h"
// #define AUX_OFFSET = MAIN_PERIPHERALS + 0x2215000 //FE215000



#define AUX_BASE (MAIN_PERIPHERALS + 0x2215000)
//mini UART

#define AUX_IRQ (AUX_BASE + 0x0)
#define AUX_ENABLES (AUX_BASE + 0x04)
#define AUX_MU_IO_REG (AUX_BASE + 0x40)
#define AUX_MU_IER_REG (AUX_BASE + 0x44)
#define AUX_MU_IIR_REG (AUX_BASE + 0x48)
#define AUX_MU_LCR_REG (AUX_BASE + 0x4c)
#define AUX_MU_MCR_REG (AUX_BASE + 0x50)
#define AUX_MU_LSR_REG (AUX_BASE + 0x54)
#define AUX_MU_MSR_REG (AUX_BASE + 0x58)
#define AUX_MU_SCRATCH (AUX_BASE + 0x5c)
#define AUX_MU_CNTL_REG (AUX_BASE + 0x60)
#define AUX_MU_STAT_REG (AUX_BASE + 0x64)
#define AUX_MU_BAUD_REG (AUX_BASE + 0x68)

#define SYSTEM_CLOCK_FREQUENCY 500000000
#define AUX_MU_BAUD_RATE(baud) ((SYSTEM_CLOCK_FREQUENCY/(baud*8))-1)


// #define SYSTEM_CLOCK_FREQUENCY 500000000
void uart_init();
void uart_write(char *buffer);
void uart_writeByte(unsigned char ch);
void uart_putc(void *p, char c);
unsigned int uart_isWriteByteReady();
unsigned int uart_isReadByteReady();
char uart_readByte();


#endif