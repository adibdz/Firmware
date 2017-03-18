#include <stdio.h>

void cetakStack();

int main(int argc, char *argv[]) {
	if(argc != 2) {
		printf("Use: ./fmt <your string>\n");
		return 1;
	}

	cetakStack( argv[1] );

	return 0;
}

void cetakStack( char *argv ) {
	printf( argv );
	printf("\n");
}
