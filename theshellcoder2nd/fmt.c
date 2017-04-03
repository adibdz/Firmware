#include <stdio.h>

int main(int argc, char *argv[]) {
	if(argc != 2) {
		printf("Use: ./fmt <your string>\n");
		return 1;
	}

	printf( argv[1] );
	printf("\n");

	return 0;
}
