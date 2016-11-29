section .text
	global _start
_start:
	mov	eax, 0x4
	mov	ebx, 0x1
	mov	ecx, msg
	mov	edx, len
	int	0x80

	mov	eax, 0x4
	mov	ebx, 0x1
	mov	ecx, s2
	mov	edx, 0x9
	int	0x80

	mov	eax, 0x1
	int 	0x80

section .data
	msg db		'Displaying 9 stars',0xa
	len equ		$ - msg
	s2 times	9 db '*'
