section .text
	global _start
_start:
	mov	ecx, len	; sama dg comps, berdasar jumlah byte dari
				; string yang akan di cari. Jika diisi 2 byte
				; maka pencarian pada string 'adib' (4byte)
				; akan menhasilkan not found. Karena pencarian
				; hanya mencapai byte ke 2 ('b') sedang 'i' ada
				; di byte ke-3
	mov	edi, my_string
	mov	al, 'i'

	cld
	repne	scasb		; ketika ketemu string 'i' maka akan diset flag
				; ZF. Maka pencarian akan langsung berhenti.

				; REPNE/REPNZ : conitional repeat. It repeats the operation while zero flag is not set.

				; REPE/REPZ : conditional repeat. It repeats the operation while zero flag is set.

				; ZF ketika result dari operasi aritmatik
				; bernilai true maka di set ke 0. Jika hasilnya
				; false maka diset ke 1
	je 	found

	; if not found
	mov	eax, 0x4
	mov	ebx, 0x1
	mov	ecx, msg_notfound
	mov	edx, len_notfound
	int	0x80
	jmp	exit

	; found
	found:
	mov	eax, 0x4
	mov	ebx, 0x1
	mov	ecx, msg_found
	mov	edx, len_found
	int	0x80

	exit:
	mov	eax, 0x1
	int	0x80

section .data
	my_string	db 'adib'
	len	equ $-my_string
	msg_found	db 'found!'
	len_found	equ $-msg_found
	msg_notfound	db 'not found!'
	len_notfound	equ $-msg_notfound
	
