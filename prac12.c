// Practical 12
// WAP to caluclate sum of n number susing Thread library
// Written by Chirag Wadhwa for the University of Delhi

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum; // Data shared among threads
void *runner(void *param); // the thread

int main(int argc, char *argv[]) {
	// Thread calculates the sum of numbers from
	// 1 to argv[1](an integer)
	pthread_t tid; // thread identifier
	pthread_attr_t attr; // set of thread attributes
	if(argc != 2) {
		fprintf(stderr, "usage: ./prac12.out <integer_value>\n");
		return -1;
	}
	if (atoi(argv[1]) < 0) {
		// atoi() converts character string int integer value
		fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
		return -1;
	}
	pthread_attr_init(&attr); // get default attributes
	pthread_create(&tid, &attr, runner, argv[1]);
	pthread_join(tid, NULL); // wait for thread to exit
	printf("SUM = %d\n", sum);
	return 0;
}
void *runner(void *param) {
	int i, upper = atoi(param);
	sum = 0;
	for (i = 1; i <= upper; i++)
		sum += i;
	pthread_exit(0);
}