	.file	"program1.c"
	.text
	.section .rdata,"dr"
.LC1:
	.ascii "Enter n: \0"
.LC2:
	.ascii "%d\0"
.LC3:
	.ascii "Product = %lf\12\0"
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	call	__main
	leaq	.LC1(%rip), %rcx
	call	printf
	leaq	.LC2(%rip), %rcx
	leaq	44(%rsp), %rdx
	call	scanf
	movl	44(%rsp), %ecx
	testl	%ecx, %ecx
	jle	.L6
	movl	$1, %eax
	pxor	%xmm0, %xmm0
	pxor	%xmm2, %xmm2
	addl	$1, %ecx
	cvtsi2sdl	%eax, %xmm0
	leal	1(%rax), %edx
	movsd	.LC0(%rip), %xmm1
	cvtsi2sdl	%edx, %xmm2
	testb	$1, %al
	je	.L3
	.p2align 4
	.p2align 3
.L8:
	divsd	%xmm0, %xmm2
	mulsd	%xmm2, %xmm1
	cmpl	%ecx, %edx
	je	.L2
.L4:
	movl	%edx, %eax
	pxor	%xmm0, %xmm0
	pxor	%xmm2, %xmm2
	cvtsi2sdl	%eax, %xmm0
	leal	1(%rax), %edx
	cvtsi2sdl	%edx, %xmm2
	testb	$1, %al
	jne	.L8
.L3:
	divsd	%xmm2, %xmm0
	mulsd	%xmm0, %xmm1
	cmpl	%ecx, %edx
	jne	.L4
.L2:
	movq	%xmm1, %rdx
	leaq	.LC3(%rip), %rcx
	call	printf
	xorl	%eax, %eax
	addq	$56, %rsp
	ret
.L6:
	movsd	.LC0(%rip), %xmm1
	jmp	.L2
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC0:
	.long	0
	.long	1072693248
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (MinGW-W64 x86_64-ucrt-mcf-seh, built by Brecht Sanders, r1) 14.2.0"
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
