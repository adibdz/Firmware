#include <stdio.h>

typedef struct {
	const char *name;
	unsigned int age:3;
} cat;

void cetak(cat *hewan) {
	hewan->age = (*hewan).age + 1;
	printf("\n1. %s berumur %i\n", (*hewan).name, hewan->age);
	// (*t).age + 1 pointer ke age nilainya tambahkan 1, karena *t adalah variabel pointer
	// (*t).age = t->age
}

int main(int argc, char *argv[]) {
	cat tom  = {"Tom Pussy Cat", 1};
	cat jerry  = {"Jerry Mouse", 1};
	cetak(&tom);
	cetak(&jerry);
	printf("\n2. %s berumur %i\n", tom.name, tom.age);
	printf("\n3. %s berumur %i\n", jerry.name, jerry.age);
	return 1;
}
