#include "mm.h"

// void test(void * a, char b){
//      *(volatile unsigned int*)a = b;
// }

void mmio_write(unsigned long reg, unsigned int val) {
     *(volatile unsigned int *)reg = val; 
}
unsigned int mmio_read(long reg) { return *(volatile unsigned int *)reg; }