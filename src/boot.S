#include "arm/sysregs.h"
#include "mm/mm.h"

.section ".text.boot"  // Make sure the linker puts this at the start of the kernel image

.global _start  // Execution starts here

_start:
    // Check processor ID is zero (executing on main core), else hang
    mrs     x1, mpidr_el1
    and     x1, x1, #3
    cbz     x1, master_proc
    // We're not on the main core, so hang in an infinite wait loop
proc_hang:  wfe
    b       proc_hang
master_proc:  // We're on the main core!


    ldr x0, =SCTLR_VALUE_MMU_DISABLED
    msr SCTLR_EL1, x0   

    ldr x0, =HCR_VALUE
    msr HCR_EL2, x0 //setts execution state for el1 to be aarch64


    //SCR_EL3 - secure configuration register
    ldr x0, =SCR_VALUE   
    msr SCR_EL3,x0      //sets the exceutions tate control for lower exception levels and sets el2 to be aarch64
    
    ldr x0, =SPSR_VALUE
    msr SPSR_EL3,x0 //holds the saved procces state for when an exception is taken to el3 //like arthimetic flags 
    //in the saved process state teh exception level is el1

    adr x0, el1_entry
    msr ELR_EL3, x0
    eret
el1_entry:

    // Set stack to start below our code
    ldr     x1, =_start
    mov     sp, x1

    // Clean the BSS section
    ldr     x1, =__bss_start     // Start address
    ldr     w2, =__bss_size      // Size of the section
bss_clear:
    cbz     w2, kernel_startup              // Quit loop if zero
    str     xzr, [x1], #8
    sub     w2, w2, #1
    cbnz    w2, bss_clear               // Loop if non-zero

    // Jump to our main() routine in C (make sure it doesn't return)
kernel_startup:
    bl      kernel_main

    b       proc_hang
    // In case it does return, halt the master core too
