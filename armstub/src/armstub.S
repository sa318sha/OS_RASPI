.globl _start

_start:
    ldr w0, kernel_main
    br x0


.ltorg

.org 0xf0
.globl stub_magic
    .word 0x5afe570b

.org 0xf4
.globl stub_version
stub_version:
    .word 0

.org 0xfc
.globl kernel_main
kernel_main:
    .word 0x80000