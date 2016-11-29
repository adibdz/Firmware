section .data
	userMsg db 	'Please enter a number: ', 0xa
	lenUserMsg equ	$ - userMsg
	dispMsg	db	'You have entered: '
	lenDispMsg equ	$ - dispMsg

section .bss
	num resb 5

section .text
	global _start
	_start:

	;User Prompt
	mov eax, 0x4
	mov ebx, 0x1
	mov ecx, userMsg
	mov edx, lenUserMsg
	int 0x80

	;Read and store user input
	mov eax, 0x3
	mov ebx, 0x0
	mov ecx, num
	mov edx, 5
	int 80h

	;Prompt dispMsg
	mov eax, 0x4
	mov ebx, 0x1
	mov ecx, dispMsg
	mov edx, lenDispMsg
	int 80h

	;Prompt num
	mov eax, 0x4
	mov ebx, 0x1
	mov ecx, num
	mov edx, 5
	int 80h

	mov eax, 0x1
	int 80h 
