section .text
	global _start
_start:
	xor eax, eax
	xor ecx, ecx
	xor ebx, ebx
	mov ecx, msg
	lea eax, [ecx+8]
	mov ebx, ecx
	add ebx, 8

exit:
	mov eax, 1
	mov ebx, 0
	int 0x80

section .data
	msg db '/bin/shXAAAABBBB'
