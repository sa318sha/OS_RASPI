// #define BIT35
// #define LEGACY

#ifndef FILE_ADDRESSES
#define FILE_ADDRESSES

#define LOW_PERIPHERAL
#define VC_SPACE

// 0x7e125000
#if defined(BIT35) 

#define START_ADDRESS = 0x000000000;
#define SDRAM_ARM_1 = 0x000000000;
#define VIDEO_CORE = 0x040000000; //mapped from 0x040000000 downwards defined in config.txt
#define SDRAM_ARM_2 = 0x040000000;
#define L2_CACHE_ALLOC = 0x400000000; 
#define RESERVE_1 = 0x440000000;
#define MAIN_PERIPHERALS = 0x47C000000; 
#define L2_CACHE_NON_ALLOC = 0x480000000;
#define LOCAL_PERIPHERALS = 0x4C0000000; 
#define RESERVED_2 = 0x500000000;
#define PCIE = 0x600000000; 

#define END_ADDRESS = 0x7FFFFFFFF;

#endif 



#if defined(LEGACY)

#define START_ADDRESS = 0x00000000;
#define L2_CACHE_ALLOC = 0x00000000; 
#define RESERVE_1 = 0x40000000;
#define MAIN_PERIPHERALS = 0x7C000000;
#define L2_CACHE_NON_ALLOC = 0x80000000;
#define SDRAM = 0xC0000000; 
#define END_ADDRESS = 0xFFFFFFFF;

#endif


#if defined(LOW_PERIPHERAL)

#define START_ADDRESS 0x0000000000
#define SDRAM_ARM 0x000000000 //to 0x0FC000000 with space inbetween in the ram for VC
#define SDRAM_VC_END 0x040000000
#define SDRAM_VC_START (SDRAM_VC_END - VC_SPACE) 
#define MAIN_PERIPHERALS 0x0FC000000
#define LOCAL_PERIPHERALS 0x0FF800000
//above is 4gb total
//below is the remaining 28gb address space
#define SDRAM_ARM_2 0x100000000
#define L2_CACHE_ALLOC 0x400000000
#define RESERVE_1 0x440000000
#define L2_CACHE_NON_ALLOC 0x480000000
#define RESERVE_2 0x4C0000000
#define PCIE 0x600000000
#define END_ADDRESS 0x7FFFFFFFF






#endif

#endif


// enum {
//     // RAM_OFFSET = 0x000000000,
//     // VIDEO_CORE = 0x040000000,
//     // MAIN_PERIPHERALS = 0x47C000000, //- 0x4_7FFF_FFFF 
//     // LOCAL_PERIPHERALS = 0x4_C000_0000 to
// // 0x4_FFFF_FFFF
//     // MAIN_PERIPHERAL_BASE = 0x7C000000,
    
//     // AUX_BASE = PERIPHERAL_BASE + 0x215000,

// };

// Physical addresses range from 0x4_7C00_0000 to 0x4_7FFF_FFFF for Main peripherals, and from 0x4_C000_0000 to
// 0x4_FFFF_FFFF for ARM Local peripherals.
// If the VPU enables "Low Peripheral" mode then the ARM (only) has Main peripherals available from 0x0_FC00_0000 to
// 0x0_FF7F_FFFF and ARM Local peripherals available from 0x0_FF80_0000 to 0x0_FFFF_FFF

// enum {
//     // PERIPHERAL_BASE = 0xFE000000,
//     // GPFSEL0         = PERIPHERAL_BASE + 0x200000,
//     // GPSET0          = PERIPHERAL_BASE + 0x20001C,
//     // GPCLR0          = PERIPHERAL_BASE + 0x200028,
//     // GPPUPPDN0       = PERIPHERAL_BASE + 0x2000E4
// };



// enum{
//     MAIN_PERIPHERAL_BASE = 0x7C000000,

// };

// enum {
//     GPIO_MAX_PIN       = 53,
//     GPIO_FUNCTION_ALT5 = 2,
// };

// enum {
//     Pull_None = 0,
// };

// // UART

// enum {
//     AUX_BASE        = PERIPHERAL_BASE + 0x215000,
//     AUX_IRQ         = AUX_BASE,
//     AUX_ENABLES     = AUX_BASE + 4,
//     AUX_MU_IO_REG   = AUX_BASE + 64,
//     AUX_MU_IER_REG  = AUX_BASE + 68,
//     AUX_MU_IIR_REG  = AUX_BASE + 72,
//     AUX_MU_LCR_REG  = AUX_BASE + 76,
//     AUX_MU_MCR_REG  = AUX_BASE + 80,
//     AUX_MU_LSR_REG  = AUX_BASE + 84,
//     AUX_MU_CNTL_REG = AUX_BASE + 96,
//     AUX_MU_BAUD_REG = AUX_BASE + 104,
//     AUX_UART_CLOCK  = 500000000,
//     UART_MAX_QUEUE  = 16 * 1024
// };


