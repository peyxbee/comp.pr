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
	leaq	44(%rsp), %rdx
	leaq	.LC2(%rip), %rcx
	call	scanf
	movl	44(%rsp), %r8d
	testl	%r8d, %r8d
	jle	.L5
	movsd	.LC0(%rip), %xmm1
	addl	$1, %r8d
	movl	$1, %eax
	.p2align 6
	.p2align 4
	.p2align 3
.L4:
	movl	%eax, %edx
	pxor	%xmm0, %xmm0
	pxor	%xmm2, %xmm2
	movl	%eax, %ecx
	andl	$1, %edx
	cvtsi2sdl	%ecx, %xmm0
	addl	$1, %eax
	cvtsi2sdl	%eax, %xmm2
	testl	%edx, %edx
	je	.L3
	movapd	%xmm0, %xmm3
	movapd	%xmm2, %xmm0
	movapd	%xmm3, %xmm2
.L3:
	divsd	%xmm2, %xmm0
	mulsd	%xmm0, %xmm1
	cmpl	%r8d, %eax
	jne	.L4
.L2:
	movq	%xmm1, %rdx
	leaq	.LC3(%rip), %rcx
	call	printf
	xorl	%eax, %eax
	addq	$56, %rsp
	ret
.L5:
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
