BITS 32

	jmp short one

two:
	pop ecx
	mov eax, 4
	mov ebx, 1
	mov edx, 15
	int 0x80

exit:
	mov eax, 1
	mov ebx, 0
	int 0x80

one:
	call two
	db "Hello, World!", 0x0a, 0x0d

