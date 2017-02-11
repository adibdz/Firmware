#include <stdio.h>
#include <string.h>

int main() {
	const char *str = "Megatron";
	const char *ptr = str; /* Assigment value */

	printf("&str\t\t: %p\n", &str);
	printf("str\t\t: %p\n", str);
	printf("&ptr\t\t: %p\n", &ptr);
	printf("ptr\t\t: %p\n---------------------\n", ptr);
	printf("*(&str)\t\t: %p\n", *(&str));
	printf("*(&ptr)\t\t: %p\n", *(&ptr));
	printf("(void*) *(&str)\t: %p\n",(void*) *(&str));
	printf("*(*(&ptr))\t: %c\n", *(*(&ptr)));
	printf("*str\t\t: %c\n", *str);
	printf("*ptr\t\t: %c\n", *ptr);
	printf("str\t\t: %s\n", str);
	printf("ptr\t\t: %s\n", ptr); /* %s expected (char *) argument */
	printf("&str[0]\t\t: %p\n", &str[0]);
	printf("&ptr[0]\t\t: %p\n", &ptr[0]);
	printf("str[0]\t\t: %c\n", str[0]); /* %c expected "The Char" on memory */
	printf("&str[0]\t\t: %s\n", &str[0]);
	/* %s expected address of "The Char" on memory" */
}
