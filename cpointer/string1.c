#include <stdio.h>
#include <string.h>

int main() {
	const char* a = "Dzulfikar Adib";
	unsigned int i;
	printf("sizeof(a): %d\n", sizeof(a));
	printf("strlen(a): %d\n", strlen(a));
	for(i = 0; i<strlen(a); i++) {
		printf("%c", a[i]);
	}
	printf("\n");
	return(0);
}
