	.file	"hello.c"
	.text
	.globl	add
	.type	add, @function
add:
.LFB0:
	.cfi_startproc
	endbr64
	leal	(%rdi,%rsi), %eax
	ret
	.cfi_endproc
.LFE0:
	.size	add, .-add
	.globl	hello_string
	.data
	.align 8
	.type	hello_string, @object
	.size	hello_string, 12
hello_string:
	.string	"hello world"
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
