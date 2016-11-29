.data
	hello1:
		.asciz "Hi all\n"
	hello2:
		.asciz "Hi function\n"

.text
	.globl _start

	.type MyFuntion, @function
	
	# Passing argument via register
	MyFunction:
		movl $4, %eax
		movl $1, %ebx
		int $0x80
		ret

	_start:
		nop

		leal hello1, %ecx
		movl $7, %edx
		call MyFunction

		leal hello2, %ecx
		movl $12, %edx
		call MyFunction

	ExitCall:
		movl $1, %eax
		movl $0, %ebx
		int $0x80
