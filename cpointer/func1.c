#include <stdlib.h>

int *calledFunction(int *);

int main() {
	int a = 10, *b;
	b = calledFunction(&a);
}

int *calledFunction(int *x) {
	int d = 40, *e, *f;
	e = x; /* Isinya x (address a=10) kasi ke e. So
			  e point ke a=10 */
	f = malloc(sizeof(int));
	*f = *e + d; /*e = ambil nilai dimana dia point
				   *f = nilai dimana f point, update/ganti
				   dg nilai dari *e + d */
	return f;
}

