

section .text
	global _start
_start:
	mov 	ax, 0x09
	and	ax, 0x01
	jz	evnn

	mov	eax, 0x4
	mov	ebx, 0x1
	mov	ecx, odd_msg
	mov	edx, len2
	int	0x80

	jmp	outprog

	evnn:
	mov	eax, 0x4
	mov	ebx, 0x1
	mov	ecx, even_msg
	mov	edx, len1
	int	0x80

	outprog:
	mov	eax, 0x1
	int	0x80

section .data
	even_msg	db 'Even Number!', 0xa
	len1		equ $-even_msg
	odd_msg		db 'Odd Number!'
	len2		equ $-odd_msg
