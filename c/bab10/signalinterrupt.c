#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "error.h"

void handler();
void handler2();
int catch_signal();

int main() {
	//if(catch_signal(SIGINT, SIG_IGN) == -1) { // IGNORE this signal
	//if(catch_signal(SIGINT, SIG_DFL) == -1) { // << The Default
	if(catch_signal(SIGINT, handler) == -1) { // << Custom Handler
		error("cannot map the handler");
	}
	if(catch_signal(SIGALRM, handler2) == -1) {
		error("cannot map the handler");
	}
	char name[10];
	alarm(10); // up to 10s, give this process SIGALRM
	printf("What is your name? (Pres Ctrl+C | kill -INT|ALRM <pid> | \
wait for 10s | input name)\n");
	fgets(name, 10, stdin);
	raise(SIGINT); // givie any signal to process it self
	printf("This text printed out cz SIG_IGN (signal ignored!)\n");
	return 0;
}

void handler(int sig) {
	printf("\nProgram received SIGINT:%d\n", sig);
	exit(1);
}
void handler2(int sig) {
	printf("\nProgram received SIGALRM:%d\n", sig);
	exit(1);
}
int catch_signal(int sig, void (*handler)(int)) {
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	return sigaction(sig, &action, NULL);
}
