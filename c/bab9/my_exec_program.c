#include <unistd.h>

int main() {
	char *my_env[] = {"JUICE=peach and apple", 0};
	execle("dinner_info", "dinner_info", "Yes", 0, my_env);
	return 0;
}
