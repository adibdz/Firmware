#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct island {
	const char *name;
	const char *opens;
	const char *closes;
	struct island *next;
} island;

void display(island *i) {
	// island *i = start;
	printf("\n- awal i point ke %p\n\n", i);
	for(; i != NULL; i = i->next) {
		printf("i point ke %p : Pulau: %sOpen %s - %s\n", i, (*i).name, i->opens, i->closes);
	}
	printf("\n- akhir i point ke %p\n", i);
}

island *create(char *name) {
	island *i = malloc(sizeof(island));
	i->name =  (const char *)  strdup(name);
	i->opens = "09:00";
	i->closes = "17:00";
	i->next = NULL;
	return i;
}

void release(island *start) {
	island *i = start;
	island *next = NULL;
	const char *name_address = NULL;
	for(; i != NULL; i = next) {
		next = (*i).next;
		printf("[+].....done...-> Freeing %p-%s", i, (*i).name);
		name_address = (*i).name; // problem still here <<< const string to pointer
		free((void* )name_address);
		free(i);
	}
}

int main(int argc, char *argv[]) {
	island *start = NULL;
	island *i = NULL;
	island *next = NULL;
	char name[80];

	for(; fgets(name, sizeof(name), stdin) != NULL; i = next) {
		next = create(name);
		if(start == NULL) {
			start = next;
			printf("next point ke %p next->next = %p\n", next, (*next).next);
		}
		if(i != NULL) {
			i->next = next;
			printf("i point ke %p i->next = %p\n", i, (*i).next);
			printf("next point ke %p next->next = %p\n", next, (*next).next);
		}
	}
	display(start);
	release(start);

	return 1;
}
