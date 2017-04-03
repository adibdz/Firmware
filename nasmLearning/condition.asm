


section .text
	global _start
_start:
	l1:
	mov	eax, 0x4
	mov	ebx, 0x1
	mov	ecx, num
	mov	edx, 0x1
	int	0x80
	
	sub	[num], byte '0'

	mov	al, [num]
	inc	byte al
	mov	[num], al

	add	[num], byte '0'

	cmp	al, byte 10
	jle	l1

	mov	eax, 0x1
	int	0x80

section .data
	num db '1' 
