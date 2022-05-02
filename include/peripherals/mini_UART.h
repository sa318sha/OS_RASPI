#pragma once

#include "util/common.h"
// #define AUX_OFFSET = MAIN_PERIPHERALS + 0x2215000 //FE215000





// #define SYSTEM_CLOCK_FREQUENCY 500000000
void uart_init();

void uart_write(char *buffer);
void uart_putc(void *p, char c);

// char uart_isWriteByteReady();
// char uart_isReadByteReady();

void uart_writeByte(char ch);
char uart_readByte();

