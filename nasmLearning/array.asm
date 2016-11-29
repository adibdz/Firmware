



section .text
	global _start
_start:
	mov	eax, 3
	mov	ebx, 0
	mov	ecx, x

	top:
	add	ebx, [ecx]
	inc	ecx
	dec	eax
	jnz	top

	done:
	add	ebx, '0'
	mov	[sum], byte bl

	display:
	mov	eax, 0x4
	mov	ebx, 0x1
	mov	ecx, sum
	mov	edx, 0x1
	int	0x80

	mov	eax, 0x1
	int	0x80

section .data
	x	db 2,4,3
	;sum	db 0

section .bss
	sum	resb 1
