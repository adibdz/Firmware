section .data
	count	dw 0
	value	db 15

section .text
	global _start
_start:
	inc word	[count]
	dec byte	[value]

	mov	ebx, count
	inc word	[ebx]

	mov 	esi, value
	dec byte	[esi]
	
	mov	eax, 0x1
	int	0x80
