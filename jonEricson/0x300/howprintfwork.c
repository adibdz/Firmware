#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void howprintfworks();

int main(int argc, char *argv[]) {
	if(argc < 2) {
		printf("Usage: %s <text to print>\n", argv[0]);
		exit(0);
	}
	howprintfworks(argv[1]);
	return 0;
}

void howprintfworks(char *a) {
	char text[16];
	strcpy(text, a);
	printf("text: %s\n",text);
	printf(text);
	puts("\n");
}
