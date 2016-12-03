#include <stdio.h>

int main() {
	const char *a = "Dzulfikar Adib";

	printf("Isi a:      %p\n", a);
	printf("Address &a: %p\n", &a);
	printf("a[0]:       %c\n", a[0]);
	printf("&a[0]:      %p\n", &a[0]);

	/* kenapa a dan &a berbeda?
	 * karena a adalah pointer variabel
	 */
}
