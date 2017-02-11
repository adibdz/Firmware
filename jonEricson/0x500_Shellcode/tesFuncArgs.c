#include <stdio.h>

void tesFunctArgs();

int main() {
	char *k[] = {"/bin/sh", NULL};
	printf("k    : %p\n", k);     /* address from 1st value */
	printf("&k   : %p\n", &k);    /* address from 1st value */
	printf("&k[0]: %p\n", &k[0]); /* address from 1st value */
	printf("k[0] : %p\n", k[0]);
	printf(">> k[1] : %p\n", k[1]);
	printf("k[0] : %s\n------------------------------\n", k[0]);
	tesFunctArgs(k[0], k,  k, NULL);
	printf(">> k[1] : %p\n", k[1]);
	printf("&k[1]   : %p\n", &k[1]);
}

void tesFunctArgs(const char *a, const char **aa,  char const *b[], char const *c){
	printf("a     : %p\n", a); /* a is point to /bin/sh */
	printf("&a    : %p\n", &a);
	printf("a     : %s\n", a);
	printf("aa[0] : %p\n", aa[0]);
	printf("aa[0] : %s\n", aa[0]);
	printf("&aa[0]: %p\n", &aa[0]);
	printf("&aa   : %p\n", &aa);
	printf("aa    : %p\n", aa);
	printf("b     : %p\n", b);
	printf("&b    : %p\n", &b);
	printf("b[0]  : %s\n", b[0]);
	printf("b[0]  : %p\n", b[0]);
	printf("&b[0] : %p\n", &b[0]);
	printf("c     : %s\n", c); /* point to NULL */
	printf("b[1]   : %p\n", b[1]);
	const char *name = "AAAA";
	b[1] = name;
	printf("name   : %p\n", name);
	printf("&name  : %p\n", &name);
	printf("name   : %s\n", name);
	printf("b[1]   : %p\n", b[1]);
	printf("&b[1]  : %p\n", &b[1]);
	printf("b[1]   : %s\n----------------------------\n", b[1]);
}

