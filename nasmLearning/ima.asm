;ima = Indirect Memory Addressing

section .data
	myTable times 10 dw 0

section .text
	global _start
_start:
	mov ebx, [myTable]
	mov [ebx], dword 4
	add ebx, 0x2
	mov [ebx], dword 5

	mov eax, 0x1
	int 0x80
