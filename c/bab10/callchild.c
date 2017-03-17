#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include "error.h"

int main() {
	int i = 0;
	for( ; i < 10; i++) {
		__PID_T_TYPE pid = fork();
		if(pid == -1) {
			error("fork fail");
		}
		if(pid == 0) {
			if(execl("childforwait", "childforwait", "Make it easy", (char *) NULL) == -1) {
				error("exec() fail");
			}
		}
		int pid_status;
		if(waitpid(pid, &pid_status, 0) == -1) {
			error("waitpid fail");
		}
	}
	fprintf(stdout, "This text should print at last\n");
}
