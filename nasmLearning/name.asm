section .text
	global _start
_start:
	;Writing name 'Adib  Dzulfikar'
	mov	eax, 0x4
	mov	ebx, 0x1
	mov	ecx, name
	mov	edx, nameLength
	int	0x80

	mov	[name], dword 'ACE'	
	
	mov	eax, 0x4
	mov	ebx, 0x1
	mov	ecx, name
	mov	edx, nameLength
	int	80h

	mov	eax, name
	inc	eax
	inc	eax
	inc	eax
	inc	eax
	inc	eax
	inc	eax
	mov	[eax], dword 0x696c7553
	inc	eax
	inc	eax
	inc	eax
	inc	eax
	mov	[eax], dword 0x20202073
	inc	eax
	inc	eax
	inc	eax
	inc	eax
	mov	[eax], dword 0x00000a20
	
	mov	eax, 0x4
	mov	ebx, 0x1
	mov	ecx, name
	mov	edx, nameLength
	int	80h

	mov	eax, 0x1
	int	0x80

section .data
	name		db 'Adib  Dzulfikar', 0xa
	nameLength	equ $-name
