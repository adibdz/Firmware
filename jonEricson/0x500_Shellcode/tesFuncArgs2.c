#include <stdio.h>

int main() {
	const char *a = "AAAA";
	const char *b = "BBBB";
	const char *c = "CCCC";
	const char *d = "DDDD";

	const char **z = &a;

	char const **args[] = {&a, b, c ,d, z};
	// char const *args[] = {a, b, c ,d, *z};

	printf("a\t\t: %p\n", a);
	printf("&a\t\t: %p\n", &a);
	printf("b\t\t: %p\n", b);
	printf("&b\t\t: %p\n", &b);
	printf("c\t\t: %p\n", c);
	printf("&c\t\t: %p\n", &c);
	printf("d\t\t: %p\n", d);
	printf("&d\t\t: %p\n\n", &d);
	printf("args\t\t: %p\n", args);
	printf("&args\t\t: %p\n\n", &args);
	printf("args[0]\t\t: %p\n", args[0]);
	printf("args[0]\t\t: %s\n", *args[0]);
	printf("&args[0]\t: %p\n\n", &args[0]);
	printf("args[1]\t\t: %p\n", args[1]);
	printf("args[1]\t\t: %s\n", args[1]);
	printf("&args[1]\t: %p\n\n", &args[1]);
	printf("args[2]\t\t: %p\n", args[2]);
	printf("args[2]\t\t: %s\n", args[2]);
	printf("&args[2]\t: %p\n", &args[2]);
}
