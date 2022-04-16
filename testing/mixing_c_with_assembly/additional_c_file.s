	.file	"additional_c_file.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"hello %i"
	.text
	.globl	func
	.type	func, @function
func:
.LFB23:
	.cfi_startproc
	endbr64
	movq	test(%rip), %rax
	cmpb	$0, (%rax)
	je	.L8
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
.L3:
	movb	$53, (%rax)
	movq	test(%rip), %rax
	movsbl	(%rax), %edx
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movq	test(%rip), %rax
	cmpb	$0, (%rax)
	jne	.L3
	movl	$33, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
.L8:
	movl	$33, %eax
	ret
	.cfi_endproc
.LFE23:
	.size	func, .-func
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
