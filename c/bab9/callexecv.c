#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "error.h"
#include <sys/wait.h>

int main() {
	char *argv[] = {"execv", "Peterpan", "Masa Lalu Tertinggal", "Menunggu Pa\
gi", (char *) NULL};
	pid_t pid = fork();
	if(pid == 0) {
		if(execv("execv", argv) == -1) {
			printf("Errno number: %d\n", errno);
			error("exec() fail");
		}
	}
	int pids;
	if(waitpid(pid, &pids, 0) == -1) {
		error("waitpid() fail");
	}
	printf("This text will be printed\n");
	return 0;
}
