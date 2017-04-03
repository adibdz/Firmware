.data
	helloWorld:	
		.ascii "Hello World!"
	byteLocation:	
		.byte 10
	int32:		
		.int 2
	int16:		
		.short 3
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
		

		# AT&T format: <source>, <destination>

		
		# 1. mov immediate value into register
		movl $10, %eax
		
		# 2. mov immediate value into memory location
		movw $50, int16

		# 3. mov data between registers
		movl %eax, %ebx

		# 4. mov data from memory to registers
		movl int32, %eax # int32 tanpa $ berarti mov isinya int32

		# 5. mov data from register to memory
		movb $2, %al
		movb %al, byteLocation

		# 6. mov data into an indexed memory location
		# Location is decided by BaseAddress(Offset, Index, DataSize)
		# Offset and Index must be registers, Datasize can be a numerical value

		movl $0, %ecx
		movl $2, %edi
		movl $22, integerArray(%ecx, %edi, 4)

		# 7. Indirect addressing using registers
		movl $int32, %eax # $int32 dg $ berarti mov addressnya int32
		movl (%eax), %ebx # (%eax) berisi addressnya int32 maka %ebx sekarang berisi value 2

		movl $9, (%eax) # mereplace value dari int32, karena isi dari %eax adalah address dari int32


		# Exit
		movl $1, %eax
		movl $0, %ebx
		int $0x80
