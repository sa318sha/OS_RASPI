	.file	"main.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
	endbr64
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	leaq	hello_string(%rip), %rbx
.L2:
	movzbl	(%rbx), %edi
	testb	%dil, %dil
	je	.L5
	movsbl	%dil, %edi
	call	putchar@PLT
	addb	$10, (%rbx)
	addq	$1, %rbx
	jmp	.L2
.L5:
	movl	$10, %edi
	call	putchar@PLT
	movl	$4, %esi
	movl	$3, %edi
	call	add@PLT
	addl	$5, %eax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE23:
	.size	main, .-main
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
