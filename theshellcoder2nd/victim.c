#include <string.h>

int main(int argc, char *argv[]) {
	char little_array[5];

	if(argc > 1)
		strcpy(little_array, argv[1]);
}