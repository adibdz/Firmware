.data
	HelloWorldString:
		.asciz "Hello World of Assembly!"
	H3llO:
		.asciz "H3llO"
.bss
	.lcomm Destination, 100
	.lcomm DestinationUsingRep, 100
	.lcomm DestinationUsingStos, 100

.text
	.globl _start

	_start:
		nop
		# 1. simple copying using movsb, movsw, movsl

		movl $HelloWorldString, %esi
		movl $Destination, %edi

		movsb
		movsw
		movsl

		# 2. setting / clearing the df flag

		std # set the DF flag
		cld # clear the DF flag

		# 3. using rep
	
		movl $HelloWorldString, %esi
		movl $DestinationUsingRep, %edi
		movl $25, %ecx # set the string length in ECX
		cld
		rep movsl
		std

		# 4. Loading string from memory into EAX register

		cld
		leal HelloWorldString, %esi
		lodsb
		lodsb
		movb $0, %al # ngreset 0x00 di $al

		dec %esi
		lodsw
		movw $0, %ax # ngreset 0x0000 di $ax
		
		subl $2, %esi # make ESI point back to the original string
		lodsl

		# 5. storing strings from EAX to memory

		leal DestinationUsingStos, %edi
		stosb
		stosw
		stosl

		#6. comparing string

		cld
		leal HelloWorldString, %esi
		leal H3llO, %edi
		cmpsb

		dec %esi
		dec %edi
		cmpsw

		subl $2, %esi
		subl $2, %edi
		cmpsl

		# exit
		movl $1, %eax
		movl $0, %ebx
		int $0x80
