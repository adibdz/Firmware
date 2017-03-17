#include <stdlib.h>
#include <stdio.h>

int main(int agrc, char *argv[]) {
	printf("Band Name : %s\n", argv[1]);
	printf("Album\t: %s - Song: %s\n", getenv("Album"), getenv("Song"));
	return 0;
}
