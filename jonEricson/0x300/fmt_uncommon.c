#include <stdio.h>
#include <stdlib.h>

int main() {
	int A = 5, B = 7, count_one, count_two;

	printf("Muhammad Adib Dzulfikar %n Muhammad Adib Dzulfikar %n\n",
			&count_one, &count_two);
	printf("count_one: %d\n", count_one);
	printf("count_two: %d\n", count_two);
	printf("A is %d and is at %08x. B is %d.\n", A, &A, B);
	exit(0);
}
