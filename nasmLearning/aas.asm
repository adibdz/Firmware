

section .text
	global _start
_start:
	;sub	ah, ah
	mov	al, '9'
	sub	al, '3'
	aas
	or	al, 30h
	mov	[res], al

	mov	eax, 0x4
	mov	ebx, 0x1
	mov	ecx, msg
	mov	edx, len
	int	0x80

	mov	eax, 0x4
	mov	ebx, 0x1
	mov	ecx, res
	mov	edx, 0x1
	int	0x80

	mov	eax, 0x1
	int	0x80

section .data
	msg	db 'The result is: ', 0xa
	len	equ $-msg

section .bss
	res	resb 1
