#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void error();

int main() {
	char *argv[] = {"execv", "Peterpan", "Masa Lalu Tertinggal", "Menunggu Pa\
gi", (char *) NULL};
	FILE *f = fopen("bandName.txt", "w+");
	if(f == NULL) {
		error("fopen fail");
	}
	pid_t pid = fork();
	if(pid == 0) {
		if(dup2(fileno(f), 1) == -1) {
			error("fileno fail");
		}
		if(execv("execv", argv) == -1) {
			error("exec() fail");
			return 2;
		}
	}
	printf("if use fork() this text will be printed\n");
	return 0;
}

void error(char *m) {
	fprintf(stderr, "%s : %s\n", m, strerror(errno));
	_exit(1);
}
