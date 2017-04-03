SYS_EXIT	equ 1
SYS_READ	equ 3
SYS_WRITE	equ 4
STDIN		equ 0
STDOUT		equ 1

section .data
	msg1 db "Enter a digit ", 0xa,0xd
	len1 equ $-msg1

	msg2 db "Please enter a second digit", 0xa, 0xd
	len2 equ $-msg2

	msg3 db "The sum is: "
	len3 equ $-msg3

section .bss
	num1 resb 2
	num2 resb 2
	result resb 1

section .text
	global _start
_start:
	mov	eax, SYS_WRITE
	mov	ebx, STDOUT
	mov	ecx, msg1
	mov	edx, len1
	int	0x80	
	
	mov	eax, SYS_READ
	mov	ebx, STDIN
	mov	ecx, num1
	mov	edx, 2
	int	0x80	
	
	mov	eax, SYS_WRITE
	mov	ebx, STDOUT
	mov	ecx, msg2
	mov	edx, len2
	int	0x80	

	mov	eax, SYS_READ
	mov	ebx, STDIN
	mov	ecx, num2
	mov	edx, 2
	int	0x80	

	mov	eax, SYS_WRITE
	mov	ebx, STDOUT
	mov	ecx, msg3
	mov	edx, len3
	int	0x80	

	mov	eax, [num1]
	sub	eax, '0'
	mov	ebx, [num2]
	sub	ebx, '0'

	add	eax, ebx
	add	eax, '0'

	mov	[result], eax

	mov	eax, SYS_WRITE
	mov	ebx, STDOUT
	mov	ecx, result
	mov	edx, 1 
	int	0x80	
	
	mov 	eax, SYS_EXIT
	xor	ebx, ebx
	int	0x80
