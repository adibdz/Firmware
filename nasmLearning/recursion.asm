section .text
	global _start
_start:
	mov	bl, 3
	call	proc_fact
	add	al, 30h
	mov	[fact], ax

	mov	eax, 0x4
	mov	ebx, 0x1
	mov	ecx, msg
	mov	edx, len
	int	0x80

	mov	eax, 0x4
	mov	ebx, 0x1
	mov	ecx, fact
	mov	edx, 1
	int	0x80

	mov	eax, 0x1
	int	0x80

	proc_fact:
	cmp	bl, 1
	jg	do_calculation
	mov	ax, 1
	ret

	do_calculation:
	dec	bl
	call	proc_fact
	inc	bl
	mul	bl
	ret

section .data
	msg	db 'Factorial 3 is:', 0xa
	len	equ $-msg

section .bss
	fact	resb 1
