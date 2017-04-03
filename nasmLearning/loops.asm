


section .text
	global _start
_start:
	mov	ecx, 10
	mov	eax, '1' ; mengapa ada petik? karena yg dicetak adalah char.
			 ; 1 disini adalah char sedangkan 10 adalah desimal

	l1:
	mov	[num], eax

	mov	eax, 0x4
	mov	ebx, 0x1
	push	ecx
	mov	ecx, num ; cetaknya disini
	mov	edx, 0x1
	int	0x80

	mov	eax, [num]
	sub	eax, '0'
	inc	eax
	add	eax, '0'
	pop	ecx

	loop l1

	mov	eax, 0x1
	int	0x80

section .bss
	num resb 1
