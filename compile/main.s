	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.section	__TEXT,__literal4,4byte_literals
	.align	2
LCPI0_0:
	.long	981651317               ## float 9.9800399E-4
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__Z1sf
	.align	4, 0x90
__Z1sf:                                 ## @_Z1sf
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	movss	LCPI0_0(%rip), %xmm1    ## xmm1 = mem[0],zero,zero,zero
	movss	%xmm0, -4(%rbp)
	mulss	-4(%rbp), %xmm1
	movaps	%xmm1, %xmm0
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__literal4,4byte_literals
	.align	2
LCPI1_0:
	.long	1018610550              ## float 0.0223099999
LCPI1_1:
	.long	1221154528              ## float 412343
LCPI1_2:
	.long	1065353216              ## float 1
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movss	LCPI1_0(%rip), %xmm0    ## xmm0 = mem[0],zero,zero,zero
	movss	LCPI1_1(%rip), %xmm1    ## xmm1 = mem[0],zero,zero,zero
	movss	LCPI1_2(%rip), %xmm2    ## xmm2 = mem[0],zero,zero,zero
	movl	$0, -4(%rbp)
	movss	%xmm2, -8(%rbp)
	movss	-8(%rbp), %xmm2         ## xmm2 = mem[0],zero,zero,zero
	divss	%xmm1, %xmm2
	movss	%xmm2, -12(%rbp)
	mulss	-8(%rbp), %xmm0
	movss	%xmm0, -16(%rbp)
	movss	-12(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	callq	__Z1sf
	movss	%xmm0, -20(%rbp)
	movss	-12(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	mulss	-16(%rbp), %xmm0
	cvttss2si	%xmm0, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__const
	.align	2                       ## @_ZZ1sfE1f
__ZZ1sfE1f:
	.long	981651317               ## float 9.9800399E-4


.subsections_via_symbols
