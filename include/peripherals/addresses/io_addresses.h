#pragma once

#include "util/common.h"
#include "peripherals/addresses/base_addresses.h"
// #include "include/register_structs.h"

#define GPIO_BASE (PBASE + 0x00200000)
//mini UART

typedef struct GPIOPinData{
    vol32 reserved;
    vol32 data[2];
}GPIOPinData;

struct GPIORegs{
    vol32 GPFSEL[6];
    GPIOPinData GPFSET;
    
    GPIOPinData GPCLR;
    GPIOPinData GPLEV;
    GPIOPinData GPEDS;
    GPIOPinData GPREN;
    GPIOPinData GPFEN;
    GPIOPinData GPHEN;
    GPIOPinData GPLEN;
    GPIOPinData GPAREN;
    GPIOPinData GPAFEN;
    vol32 reserved[21];
    vol32 GPIO_PUP_PDN_CNTRL_REG[4];

};

#define GPIOR ((struct GPIORegs *)(GPIO_BASE)) //address of gpio_base become the address of the pointer and all the values it points to are offset by 4
//meaning that gpfsel will have teh address but the value of that address is going to be that value of gpfsel or something

// #define GPIO_REG ((struct GPIOREGS*)(GPIO_BASE)) 

// #define GPFSEL0 (GPIO_BASE + 0x00)
// #define GPFSEL1 (GPIO_BASE + 0x04)
// #define GPFSEL2 (GPIO_BASE + 0x08)
// #define GPFSEL3 (GPIO_BASE + 0x0c)
// #define GPFSEL4 (GPIO_BASE + 0x10)
// #define GPFSEL5 (GPIO_BASE + 0x14)

// // #define GFSEL_

// // struct GenericRegisterInfo GPFSEL; 

// #define GPSET0 (GPIO_BASE + 0x1c)
// #define GPSET1 (GPIO_BASE + 0x20)

// #define GPCLR0 (GPIO_BASE + 0x28)
// #define GPCLR1 (GPIO_BASE + 0x2c)

// #define GPLEV0 (GPIO_BASE + 0x34)
// #define GPLEV1 (GPIO_BASE + 0x38)

// #define GPEDS0 (GPIO_BASE + 0x40)
// #define GPEDS1 (GPIO_BASE + 0x44)

// #define GPREN0 (GPIO_BASE + 0x4c)
// #define GPREN1 (GPIO_BASE + 0x50)
// #define GPFEN0 (GPIO_BASE + 0x58)
// #define GPFEN1 (GPIO_BASE + 0x5c)

// #define GPHEN0 (GPIO_BASE + 0x64)
// #define GPHEN1 (GPIO_BASE + 0x68)
// #define GPLEN0 (GPIO_BASE + 0x70)
// #define GPLEN1 (GPIO_BASE + 0x74)

// #define GPAREN0 (GPIO_BASE + 0x7c)
// #define GPAREN1 (GPIO_BASE + 0x80)
// #define GPAFEN0 (GPIO_BASE + 0x88)
// #define GPAFEN1 (GPIO_BASE + 0x8c)

// #define GPIO_PUP_PDN_CNTRL_REG0 (GPIO_BASE + 0xe4)
// #define GPIO_PUP_PDN_CNTRL_REG1 (GPIO_BASE + 0xe8)
// #define GPIO_PUP_PDN_CNTRL_REG2 (GPIO_BASE + 0xec)
// #define GPIO_PUP_PDN_CNTRL_REG3 (GPIO_BASE + 0xf0)


