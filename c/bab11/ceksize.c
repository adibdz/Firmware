#include <stdio.h>
#include <string.h>

int main() {
	char buf[100] = {"adib dzulfikar"};
	printf("sizeof(buf): %d\n", sizeof(buf));
	printf("strlen(buf): %d\n", strlen(buf));
	printf("buf: %s\n", buf);
}
