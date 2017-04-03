
section .text
	global _start
_start:
	mov	esi, s1
	mov	edi, s2
	mov	ecx, 10 ; jika diganti 4 byte (sesuai length string 'adib')
			; maka output program ini adalah 'string sama'. lho ?
			; karena yang dideteksi untuk di compare hanya 4 byte :)
			; sedangkan string ' dz' pada s1 tidak terkena compare
			; karena diluar dari 4 byte:
			; 			' ' = byte ke 5
			;			'd' = byte ke 6
			;			'z' = byte ke 7
		
	cld

	rep	cmpsb
	jz	equal

	;if not equal
	mov	eax, 0x4
	mov	ebx, 0x1
	mov	ecx, msg_neq
	mov	edx, len_neq
	int	0x80
	
	jmp	exit

	;if equal
	equal:
	mov	eax, 0x4
	mov	ebx, 0x1
	mov	ecx, msg_eq
	mov	edx, len_eq
	int	0x80

	exit:
	mov	eax, 0x1
	int	0x80

section .data
	msg_neq	db 'STRING NOT SAME',0xa
	len_neq	equ $-msg_neq
	msg_eq	db 'STRING SAME',0xa
	len_eq	equ $-msg_eq
	s1	db 'adib dz'
	lens1	equ $-s1
	s2	db 'adib'
	lens2	equ $-s2 
