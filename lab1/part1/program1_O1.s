	.file	"program1.c"
	.text
	.section .rdata,"dr"
.LC1:
	.ascii "Enter n: \0"
.LC2:
	.ascii "%d\0"
.LC3:
	.ascii "Product = %lf\12\0"
	.text
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
	movl	44(%rsp), %r9d
	testl	%r9d, %r9d
	jle	.L6
	addl	$2, %r9d
	movl	$2, %edx
	movsd	.LC0(%rip), %xmm1
	jmp	.L5
	.p2align 6
.L8:
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%edx, %xmm0
	pxor	%xmm2, %xmm2
	cvtsi2sdl	%ecx, %xmm2
.L4:
	divsd	%xmm2, %xmm0
	mulsd	%xmm0, %xmm1
	addl	$1, %edx
	cmpl	%r9d, %edx
	je	.L2
.L5:
	leal	-1(%rdx), %ecx
	movl	%ecx, %r8d
	shrl	$31, %r8d
	leal	(%rcx,%r8), %eax
	andl	$1, %eax
	subl	%r8d, %eax
	cmpl	$1, %eax
	je	.L8
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%ecx, %xmm0
	pxor	%xmm2, %xmm2
	cvtsi2sdl	%edx, %xmm2
	jmp	.L4
.L6:
	movsd	.LC0(%rip), %xmm1
.L2:
	movq	%xmm1, %rdx
	leaq	.LC3(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$56, %rsp
	ret
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
