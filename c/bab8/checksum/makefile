encrypt.o: encrypt.c encrypt.h
	gcc -c encrypt.c -o encrypt.o
checksum.o: checksum.c checksum.h
	gcc -c checksum.c -o checksum.o
liblowsecurity.a: encrypt.o checksum.o
	ar -rcs liblowsecurity.a encrypt.o checksum.o
tescode.o: tescode.c encrypt.h checksum.h
	gcc -c tescode.c -o tescode.o
tescode: tescode.o liblowsecurity.a
	gcc tescode.o -I. -L. -llowsecurity -o tescode
