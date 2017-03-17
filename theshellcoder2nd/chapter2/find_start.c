#include <stdio.h>

unsigned int find_start() {
	__asm__("movl %esp, %eax");
}

int main() {
	printf("0x%x\n", find_start());
}
