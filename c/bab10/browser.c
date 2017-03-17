#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include "error.h"

void open_url();

int main() {
	int fdpipe[2];
	if(pipe(fdpipe) == -1) {
		error("pipe() fail");
	}
	__PID_T_TYPE pid = fork();
	if(pid == -1) {
		error("fork() fail");
	}
	if(pid == 0) {
		dup2(fdpipe[1], 1);
		close(fdpipe[0]);
		if(execl("link", "link", (char *) NULL) == -1) {
			error("exec() fail");
		}
	}
	int pidstatus;
	if(waitpid(pid, &pidstatus, 0) == -1) {
		error("waitpid fail");
	}
	dup2(fdpipe[0], 0);
	close(fdpipe[1]);
	char link[30];
	while(fgets(link, 30, stdin) != NULL) {
		if(link[0] == '\t') { 
			//fprintf(stdout, "%s", link);
			open_url(link + 1);
		}
	}
	return 0;
}

void open_url(char *url) {
	__PID_T_TYPE pid = fork();
	if(pid == 0) {
		char link[30];
		// sprintf(link, "x-www-browser '%s' &",url);
		// system(link);
 		sprintf(link, "%s", url);
 		if(execlp("x-www-browser", "x-www-browser", link, (char *) NULL) == -1) {
 			error("exec() browser fail");
		}
	}
	int pidstatus;
	if(waitpid(pid, &pidstatus, 0) == -1) {
		error("waitpid browser fail()");
	}
	fprintf(stdout, "Browser done\n");
}
