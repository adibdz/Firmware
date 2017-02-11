#include <stdio.h>

int main() {
	const char *a = "Dzulfikar Adib";

	printf("Isi a\t\t : %p\n", a);
	printf("Address &a\t : %p\n", &a);
	printf("a[0]\t\t : %c\n", a[0]);
	printf("&a[0]\t\t : %p\n", &a[0]);
	printf("&a[1]\t\t : %p\n", &a[1]);
	printf("&a[2]\t\t : %p\n", &a[2]);

	/* kenapa a dan &a berbeda?
	 * karena a adalah pointer variabel
	 */
}
