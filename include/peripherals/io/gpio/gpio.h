#pragma once
#include "util/common.h"
#include "peripherals/io/io_addresses.h"


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



typedef enum _GPIO_PUPDCTNL{
    GPNORES =0,
    GPUPRES =1,
    GPDOWNRES =2,
    GPRESERVED =3,
}GPIO_PUPDCTNL;

// u32 gpio_set_func(u8 pinNumber, GPIO_func);
// #define WAY1

#if defined(WAY1)

u32 gpio_general(u8 pinNumber, u8 value, u8 field_size, u32 baseAddress);
u32 gpio_select  (u8, GPIO_func);
u32 gpio_set(u8 pinNumber, u8 value);
u32 gpio_clear(u8 pinNumber, u8 value);
u32 gpio_pull(u8 pinNumber, GPIO_PUPDCTNL value );
u32 gpio_select_alternate(u8 pin, GPIO_func val);

#else


void gpio_pin_set_func(u8 pinNumber, GPIO_func func);

void gpio_pin_output_set(u8 pinNumber, u8 newVal);
void gpio_pin_output_clear(u8 pinNumber);
void gpio_pin_level(u8 pinNumber);
void gpio_pin_event_status(u8 pinNumber);
void gpio_pin_rising_edge_detect(u8 pinNumber);
void gpio_pin_falling_edge_detect(u8 pinNumber);
void gpio_pin_high_detect(u8 pinNumber);
void gpio_pin_low_detect(u8 pinNumber);
void gpio_pin_async_rising_edge_detect(u8 pinNumber);
void gpio_pin__asyncfalling_edge_detect(u8 pinNumber);
void gpio_pin_resistor_enable (u8 pinNumber,GPIO_PUPDCTNL resistor_val);

#endif

// #ifndef _IO_FILE
// #define _IO_FILE
// void mmio_write(unsigned long reg, unsigned int val);
// unsigned int mmio_read(long reg);

// #endif