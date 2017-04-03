/* menentukan endianness */
#include <stdio.h>

#define LITTLE_ENDIAN 1
#define BIG_ENDIAN 0

int endian();

int main() {
	int val = endian();
	if(val == 1) {
		printf("This computer is LITTLE ENDIAN\n");
	} else {
		printf("This computer is BIG ENDIAN\n");
	}
}

int endian() {
	short int a = 0x0001;
	char const *b = (char*) &a;
	if(b[0] == 1)
		return LITTLE_ENDIAN;
	else
		return BIG_ENDIAN;
}
