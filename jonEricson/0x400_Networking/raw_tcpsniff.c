#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "hacking.h"

void fatal(char *);

int main(void) {
	int i, recv_length, sockfd;
	u_char buffer[9000];

	if((sockfd = socket(PF_INET, SOCK_RAW, IPPROTO_TCP)) == -1)
		fatal("in socket");

	for(i=0; i<3; i++) {
		recv_length = recv(sockfd, buffer, 8000, 0);
		printf("Got a %d byte packet\n", recv_length);
		dump(buffer, recv_length);
	}
}

void fatal(char *message) {
	char err_message[100];
	strcpy(err_message, "[!!] Fatal Error ");
	strncat(err_message, message, 83);
	perror(err_message);
	exit(-1);
}
