#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void howprintfworks();

static int val = 16;

int main(int argc, char *argv[]) {
	if(argc < 2) {
		printf("Usage: %s <text to print>\n", argv[0]);
		exit(0);
	}
	printf("&val: %p\n", &val);
	printf("[before] val: %d\n", val);
	howprintfworks(argv[1]);
	printf("[after] val: %d | val: 0x%08x\n", val, val);
	return 0;
}

void howprintfworks(char *a) {
	char text[16];
	strcpy(text, a);
	printf("text: %s\n",text);
	printf(text);
	puts("\n");
}
