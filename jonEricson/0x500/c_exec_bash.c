#include <unistd.h>

int main() {
	char path[] = "/bin/sh\x00";
	char *argv[2];
	argv[0] = path;
	argv[1] = "\x00";
	char *envp = argv[1]; 
	execve(path, argv, &envp);
	return 0;
}
