

section .text
	global _start
_start:
	mov	ecx, len
	mov	esi, s1
	mov	edi, s2

	l1:
	lodsb
	add	al, 02
	stosb
	loop	l1

	;cld
	;rep	movsb

	mov	eax, 0x4
	mov	ebx, 0x1
	mov	ecx, s2
	mov	edx, 20
	int	0x80

	mov	eax, 0x1
	int	0x80

section .data
	s1	db 'sulis dzulfikar'
	len	equ $-s1

section .bss
	s2	resb 10
