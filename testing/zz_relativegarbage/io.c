// #include "io.h"
// #include "gpio.h"
// enum {
//     GPIO_MAX_PIN       = 53,
//     GPIO_FUNCTION_ALT5 = 2,
// };

// enum {
//     Pull_None = 0,
// };
// //test

// unsigned int gpio_call(unsigned int pin_number, unsigned int value, unsigned int base, unsigned int field_size, unsigned int field_max) {
//     unsigned int field_mask = (1 << field_size) - 1;
  
//     if (pin_number > field_max) return 0;
//     if (value > field_mask) return 0; 

//     unsigned int num_fields = 32 / field_size;
//     unsigned int reg = base + ((pin_number / num_fields) * 4);
//     unsigned int shift = (pin_number % num_fields) * field_size;

//     unsigned int curval = mmio_read(reg);
//     curval &= ~(field_mask << shift);
//     curval |= value << shift;
//     mmio_write(reg, curval);

//     return 1;
// }

// unsigned int gpio_set     (unsigned int pin_number, unsigned int value) { return gpio_call(pin_number, value, GPSET0, 1, GPIO_MAX_PIN); }
// unsigned int gpio_clear   (unsigned int pin_number, unsigned int value) { return gpio_call(pin_number, value, GPCLR0, 1, GPIO_MAX_PIN); }
// unsigned int gpio_pull    (unsigned int pin_number, unsigned int value) { return gpio_call(pin_number, value, GPPUPPDN0, 2, GPIO_MAX_PIN); }
// unsigned int gpio_function(unsigned int pin_number, unsigned int value) { return gpio_call(pin_number, value, GPFSEL0, 3, GPIO_MAX_PIN); }

// void gpio_useAsAlt5(unsigned int pin_number) {
//     gpio_pull(pin_number, Pull_None);
//     gpio_function(pin_number, GPIO_FUNCTION_ALT5);
// }



// unsigned int get64(unsigned long addr){
//     return *(volatile unsigned int*)addr;
// }
// void set32(unsigned long addr, int val){
//     *(volatile unsigned int*)addr = val;
// }

// unsigned int uart_isWriteByteReady() { return mmio_read(AUX_MU_LSR_REG) & 0x20; }

// void uart_writeByteBlockingActual(unsigned char ch) {
//     while (!uart_isWriteByteReady()); 
//     mmio_write(AUX_MU_IO_REG, (unsigned int)ch);
// }

// void uart_writeText(char *buffer) {
//     while (*buffer) {
//        if (*buffer == '\n') uart_writeByteBlockingActual('\r');
//        uart_writeByteBlockingActual(*buffer++);
//     }
// }