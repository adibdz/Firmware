
section .text
	global _start
_start:
	call	display
	mov	eax, 1
	int	0x80

	display:
	mov	ecx, 256

	l1:
	push	ecx
	mov	eax, 0x4
	mov	ebx, 0x1
	mov	ecx, achar
	mov	edx, 0x1
	int	0x80
	pop	ecx
	;mov	dx, [achar]
	;cmp	byte [achar], 0dh
	inc	byte [achar]
	loop	l1
	ret

section .data
	achar	db '0'
