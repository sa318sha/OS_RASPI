#include "arm/sysregs.h"
#include "mm.h"

.section ".text.boot"  // Make sure the linker puts this at the start of the kernel image

.global _start  // Execution starts here

_start:
    // Check processor ID is zero (executing on main core), else hang
    mrs     x1, mpidr_el1       //read multiprocessor affinity register
    and     x1, x1, #3          //main processor has id of 0x00
    cbz     x1, master_core
    b       processor_hang
    // We're not on the main core, so hang in an infinite wait loop
processor_hang:  wfe
    b       processor_hang
master_core:  // We're on the main core!

    ldr	x0, =SCTLR_VALUE_MMU_DISABLED
	msr	sctlr_el1, x0		

	ldr	x0, =HCR_VALUE
	msr	hcr_el2, x0

	ldr	x0, =SCR_VALUE
	msr	scr_el3, x0

	ldr	x0, =SPSR_VALUE
	msr	spsr_el3, x0

	adr	x0, el1_entry		//address to return to
	msr	elr_el3, x0         //will go to el1_entry after returing from exception 3

    eret                    //returns from an exception state

el1_entry:
    // Set stack to start below our code


    // Clean the BSS section
    ldr     x1, =__bss_start     // Start address
    ldr     w2, =__bss_size      // Size of the section
bss_clear:
    cbz     w2, main_routine               // main_routine
    str     xzr, [x1], #8
    sub     w2, w2, #1
    cbnz    w2, bss_clear               // Loop if non-zero

        //is this correct?
        // can move the stack to where we started data since the stack goes down while the loaded kernel goes up
    ldr     x1, =_start
    mov     sp, x1



    // Jump to our main() routine in C (make sure it doesn't return)
main_routine:
    bl      kernel_main
    // In case it does return, halt the master core too
    b       processor_hang

