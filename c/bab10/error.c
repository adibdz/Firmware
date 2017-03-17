#include "error.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

void error(char *m) {
	fprintf(stderr, "%s : %s\n", m, strerror(errno));
	_exit(1);
}
