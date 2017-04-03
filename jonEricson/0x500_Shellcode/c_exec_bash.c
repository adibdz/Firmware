#include <unistd.h>
#include <stdio.h>

/* jika sudah bisa, coba dengan priviledge
 * escalation.
 */

int main() {
	char path[] = "/bin/sh"; /* atau *path */
	// printf("sizeof path: %d \n", sizeof(path));
	char *argv[] = {path, 0};
	// argv[0] = path;
	// argv[1] = 0;
	execve(path, argv, NULL);

	// char *args[] = {"/bin/sh/", 0};
	// setreuid(0,0);
	// execve("/bin/sh",args,0);
	//
	return 0;
}
