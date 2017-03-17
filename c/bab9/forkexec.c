#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "error.h"
#include <sys/wait.h>

int main() {
	int i;
	char *allsong[] = {"Satu Hati", "Ada Apa Denganmu", "Langit Tak Mendengar"};
	char *allalbum[] = {"Sahabat", "Bintang Di Surga", "Alexandria"};
	char *bandname = "Peterpan";
	char song[30];
	char album[30];
	for(i = 0 ; i < 3; i++) {
		__PID_T_TYPE pid = fork();
		if( pid == -1) {
			error("fork fail");
			return 1;
		}
		if( pid == 0) {
			sprintf(album, "Album=%s", allalbum[i]);
			sprintf(song, "Song=%s", allsong[i]);
			char *envp[] = {album, song, (char *) NULL};
			if(execle("pchild", "pchild", bandname, (char *) NULL, envp) == -1) {
				error("exec fail");
				return 1;
			}
		}
		int pidstatus;
		if(waitpid(pid, &pidstatus, 0) == -1) {
			error("waitpid fail");
		}
	}
	fprintf(stdout, "This text will be printed last\n");
	return 0;
}
