#include <stdio.h>

int main() {
	int i = 0;
	char *url[] = {"Google.com", "Facebook.com", "Yahoo.com"};
	// char *url[] = {"Google.com"};
	for( ; i < 3; i++) {
		fprintf(stdout, "Link : %d\n", i);
		fprintf(stdout, "\t%s\n", url[i]);
	}
	return 0;
}
