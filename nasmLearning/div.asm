


section .text
	global _start
_start:
	mov	ax, '8'
	sub	ax, '0'
	
	mov	bl, '2'
	sub	bl, '0'

	div	bl
	; Yang mau di dibagi di taruh di ax (16bit)	(dividend)
	; Yang menjadi pembagi ditaruh di bl (8bit)   (divisor)

	add	al, '0'
	mov	[res], al

	mov	ecx, msg
	mov	edx, len
	mov	ebx, 0x1
	mov	eax, 0x4
	int	0x80

	mov	ecx, res
	mov	edx, 0x1
	mov	ebx, 0x1
	mov	eax, 0x4
	int	0x80

	mov	eax, 0x1
	int	0x80
	
section .data
	msg	db "The result is: ", 0xa,0xd
	len	equ $-msg

section .bss
	res	resb 1
