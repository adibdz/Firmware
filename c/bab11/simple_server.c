#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "error.h"

#define PORT 7890

int opensocket();
void bindsocket();
void listening();
int readin();
int say();
void handlingsignal();
int catchsignal();

int socketserver;

int main(void) {
	int  socketclient, recvlen, loop = 0;
	struct sockaddr_in clientaddr;
	socklen_t clientaddrlen;
	char buffer[100];

	if(catchsignal(SIGINT, handlingsignal) == -1)
		error("Cannot map handler");

	socketserver = opensocket();
	bindsocket(socketserver, PORT);
	listening(socketserver, 2);
	printf("[+] server: ready\n");

	while(1) {
		clientaddrlen = sizeof(clientaddr);
		if((socketclient = accept(socketserver, (struct sockaddr *)&clientaddr, &clientaddrlen)) == -1)
			error("accepting connection");
		printf("[+] server: got connection from %s port %d\n", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
		__PID_T_TYPE pid;
		if((pid = fork()) == -1)
			error("fork() fail");
		fprintf(stdout, "[+] pid (in server): %d - loop: %d\n", pid, loop);
		if(pid == 0) {
			fprintf(stdout, "[+] pid (in child): %d - loop: %d\n", pid, loop);
			close(socketserver);
			say(socketclient, "Simple Server Version 1.0\r\nKnock Knock!!\r\n");
			recvlen = readin(socketclient, buffer, sizeof(buffer));
			while(recvlen > 0) {
				printf("[+] child: receive %d bytes\n", recvlen);
				printf("[+] message: %s\n", buffer);
				recvlen = readin(socketclient, buffer, sizeof(buffer));
			}
			close(socketclient);
			exit(1);
		}
		loop++;
		puts("loop exceuted!!\n");
		close(socketclient);
	}
	return 0;
}

int opensocket() {
	if((socketserver = socket(PF_INET, SOCK_STREAM, 0)) == -1)
		error("in socket");
	return socketserver;
}

void bindsocket(int socket, int port) {
	struct sockaddr_in hostaddr;
	socklen_t hostaddrlen;
	int yes = 1;

	if(setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
		error("setting socket option SO_REUSEADDR");
	hostaddr.sin_family = AF_INET;
	hostaddr.sin_port = htons(port);
	hostaddr.sin_addr.s_addr = 0;
	memset(&(hostaddr.sin_zero), '\0', 8);

	hostaddrlen = sizeof(hostaddr);
	if(bind(socket, (struct sockaddr *)&hostaddr, hostaddrlen) == -1)
		error("binding to socket");
}

void listening(int socket, int n) {
	if(listen(socket, n) == -1)
		error("listening on socket");
}

int catchsignal(int sig, void (*handler)(int)) {
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	return sigaction(sig, &action, NULL);
}

void handlingsignal(int sig) {
	if(socketserver) close(socketserver);
	printf("\nSIGINT:%d - Bye !!\n", sig);
	exit(1);
}

int say(int socket, char *s) {
	if(send(socket, s, strlen(s), 0) == -1)
		error("send() fail");
}

int readin(int socket, char *buf, int sizeofbuf) {
	int c;
	if((c = recv(socket, buf, sizeofbuf, 0)) == -1)
		error("readin fail");
	// printf("c: %d\n", c);
	c -= 1;
	// if(buf[c] == '\n') printf("Yes true\n");
	buf[c] = '\0';
	// printf("buf[c-0]: %08x\n", buf[c-0]);
	// printf("buf[c-1]: %c\n", buf[c-1]);
	// printf("buf[c-2]: %c\n", buf[c-2]);
	// printf("buf[c-3]: %c\n", buf[c-3]);
	// printf("buf[c-4]: %c\n", buf[c-4]);
	// printf("buf[c-5]: %c\n", buf[c-5]);
	return c;
}
