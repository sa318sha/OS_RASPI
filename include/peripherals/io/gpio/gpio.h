#pragma once

#include "peripherals/gpio_addresses.h"

typedef enum _GPIO_func{
    GFInput =0,
    GFOutput =1,
    GFAlt0 =4,
    GFAlt1 =5,
    GFAlt2 =6,
    GFAlt3 =7,
    GFAlt4 =3,
    GFAlt5 =2,
}GPIO_func;


unsigned int gpio_general(unsigned int pinNumber, unsigned int value, unsigned int field_size, unsigned int baseAddress);
unsigned int gpio_select  (unsigned int pin_number, unsigned int value);
unsigned int gpio_set     (unsigned int pin_number, unsigned int value);
unsigned int gpio_clear   (unsigned int pin_number, unsigned int value);
unsigned int gpio_pull    (unsigned int pin_number, unsigned int value);
unsigned int gpio_select_alternate(unsigned int pinNumber, unsigned int value);

// #ifndef _IO_FILE
// #define _IO_FILE
// void mmio_write(unsigned long reg, unsigned int val);
// unsigned int mmio_read(long reg);

// #endif