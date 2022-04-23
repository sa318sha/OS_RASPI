#include "mm/basic_mm.h"
#include "util/common.h"
void mm_write(vol64 reg, vol32 val) {
     *(vol32 *)reg = val; 
}
u32 mm_read(vol64 reg) { return *(vol32 *)reg; }

// void memzero(unsigned long src, unsigned long n){
//      for(int i =0; i < n; i++){

//      }
// }