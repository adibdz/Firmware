BITS 32

section .text
	global _start
_start:
			; _start(argc, argc[]) - push argc[], push argc
	pop eax ; argc
	pop eax ; argv[0] - name of program
	pop eax ; argv[1] - first argument

	xor eax, eax
	xor ebx, ebx
	mov al, 0x1
	int 80h
