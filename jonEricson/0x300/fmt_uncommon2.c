#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned int A = 5, B = 7, count_one, count_two;

	printf("ZZZZZ%nAAAAA%n\n", &count_one, &count_two);
	printf("count_one: %d\n", count_one);
	printf("count_two: %d\n", count_two);
	printf("A is %d and is at %p. B is %x.\n", A, &A);
	exit(0);
}
