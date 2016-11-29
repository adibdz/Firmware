.data
	helloWorld:	
		.ascii "Hello World!"
	byteLocation:	
		.byte 10
	int32:		
		.int 2
	int16:		
		.short 2
	float:		
		.float 10.22
	integerArray:	
		.int 10,20,30,40,50

.bss
	.comm largeBuffer, 10000

.text
	.globl _start
	
	_start:
		nop
		movl $1, %eax
		movl $0, %ebx
		int $0x80
