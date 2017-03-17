#include <stdio.h>

void funct1();
void funct2();

int main() {
	char *string1 = "DDDD";
	char *string2[] = {"AAAA", 0};
	// printf("string2: %p\n", string2);
	// char string3[2][4] = {"BBBB", "0"};
	// *string2 = "CCCC";
	funct1(string1, string2);
	funct2(string2, string2, string1, string1);

	return 0;
}

void funct1(const char *a, char const *b[]) {
	printf("a:\t%s\n", a);
	printf("b[0]:\t%s\n", b[0]);
	printf("*b:\t%s\n", *b);
	printf("**b:\t%c\n", **b);
}

void funct2(const char *z, const char **aa, char const *bb[], char const cc[]) {
	printf("z:\t%p\n", z);
	printf("aa:\t%s\n",*aa);
	printf("aa[0]:\t%s\n",aa[0]);
	// printf("*bb:\t%s\n", *bb); /* Segmentation Fault */
	printf("bb:\t%s\n", (char *) bb);
	printf("(char *) &bb[0]:\t%s\n", (char *) &bb[0]);
	printf("cc:\t%s\n", cc);
}
