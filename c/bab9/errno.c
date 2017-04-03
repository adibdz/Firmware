#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main() {
	/* Mistake /sbin/ipconfig should be /sbin/ifconfig */
	char *args[] = {"/sbin/ipconfig", "eth0", (char *) NULL};
	if( execv("/sbin/ipconfig", args) == -1 ) {
		if( execlp("ipconfig", "ipconfig", (char *) NULL ) == -1 ) {
			fprintf(stderr, "Cannot run : %s\n", strerror(errno));
			return 1; /*what this return number mean ?*/
		}
	}
	return 0;
}
