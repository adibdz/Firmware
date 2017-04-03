.data

	HelloWorld:
		.asciz "Hello World!\n",

	CallDemo:
		.asciz "Call works!\n"

.text

	.globl _start
	
	_start:
		nop

		# Unconditional Branching

		Call CallMe

		movl $4, %eax
		movl $1, %ebx
		movl $HelloWorld, %ecx
		movl $13, %edx
		int $0x80

		jmp ExitProgram

		CallMe: #fungsi
			movl $4, %eax
			movl $1, %ebx
			movl $CallDemo, %ecx
			movl $12, %edx
			int $0x80
			ret

		ExitProgram: # fungsi
			# Exit the program
			movl $1, %eax
			movl $0, %ebx
			int $0x80
