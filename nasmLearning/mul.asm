


section .text
	global _start
_start:
	mov	al, '3'
	sub	al, '0'
	
	mov	bl, '2'
	sub	bl, '0'

	mul	bl
	; Yang mau di kali di taruh di al	(multiplicand)
	; Yang menjadi pengkali ditaruh di bl   (multiplier)
	; Atau dibalik2 ga masalah karena sifat : a x b = b x a

	add	al, '0'
	mov	[res], al

	mov	ecx, msg
	mov	edx, len
	mov	ebx, 0x1
	mov	eax, 0x4
	int	0x80
	nwln
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
