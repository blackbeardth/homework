// Practrical 06
// Write a program to implement FCFS(First Come First Serve) scheduling algorithm.
// Written by Chirag Wadhwa for the University of Delhi

#include <stdio.h>

int tim = 0;
int main(void) {
	int n, i, j, b[20], w[20], taround[20], tw = 0, tt = 0;
	float avw, avt;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		printf("\nEnter the burst time(in milliseconds): ");
		scanf("%d", &b[i]);
	}
	for (i = 1; i <= n; i++) {
		w[i] = tim;
		for (j = 1; j <= b[i]; j++) {
			tim++;
			if (j == b[i])
				taround[i] = tim;
		}
	}
	for (int i = 1; i <= n; i++)
		tw = tw + w[i];

	avw = (float)tw / n;
	for (int i = 1; i <= n; i++)
		tt = tt + taround[i];

	avt = (float)tt / n;

	printf("\n Waiting time and turn around time of the processes(in milliseconds)\n");
	printf("=====================================================================\n");
	for (int i = 1; i <= n; i++)
		printf("Process: %-2d -->\t Waiting time: %2d\t Turn around time: %2d\n", i, w[i], taround[i]);
	printf("\n\nAverage waiting time: %.2f ms\n", avw);
	printf("\n\nAverage turn around time: %.2f ms\n", avt);

}