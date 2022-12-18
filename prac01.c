// practical 1
// WAP(using fork() and/or exec() commands) where parent
// and child execute:
// a) same program, same code.
// b) same program, different code.
// c) before terminating, the parent waits for the child to finish its task.

// Written by Chirag Wadhwa for The University Of Delhi
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// (a)
int main(void) {
	pid_t p;
	p = fork();

	if (p < 0) {
		fprintf(stderr, "Fork Failed");
		return 1;
	}
	printf("My ID is: %11d\nMy parent ID is: %4d\n", getpid(), getppid());

	return 0;
}

// (b)
// int main(void) {
// 	pid_t p;
// 	p = fork();

// 	if (p < 0) {
// 		fprintf(stderr, "Fork Failed");
// 		return 1;
// 	} else if (p == 0) {
// 		printf("I am Child Process\n");
// 		printf("My pid is: %d\n", getpid());
// 	} else {
// 		printf("I am Parent Process\n");
// 		printf("My pid is: %d\n", getpid());
// 	}
// 	return 0;
// }

// (c)
// int main(void) {
// 	pid_t p;
// 	p = fork();
// 	if (p < 0) {
// 		printf("Error\n");
// 		return 1;
// 	} else if (p == 0) {
// 		printf("I am CHild Process\n");
// 		printf("My pid is: %d\n", getpid());
// 	} else {
// 		wait(NULL);
// 		printf("I am Parent Process\n");
// 		printf("My actual pid is is: %d\n", getpid());
// 	}
// 	return 0;
// }