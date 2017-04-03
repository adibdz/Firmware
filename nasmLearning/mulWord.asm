


section .text
	global _start
_start:
	mov	ax, '9'
	sub	ax, '0'

	mov	bx, [data]
	;sub	bx, '0'

	mul	bx

	;add	ax, word  '0'
	mov	[res],word ax

	mov	ecx, msg
	mov	edx, len
	mov	ebx, 0x1
	mov	eax, 0x4
	int	0x80

	mov	ecx, res
	mov	edx, 0x2
	mov	ebx, 0x1
	mov	eax, 0x4
	int	0x80

	mov	eax, 0x1
	int	0x80
	
section .data
	msg	db "The result is: ", 0xa,0xd
	len	equ $-msg
	data	dw 5

section .bss
	res	resw 1
