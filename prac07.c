// Practical 07
// WAP to implement round-robin scheduling algorithm.
// Written by Chirag Wadhwa for the University of Delhi

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int count, n, time, remain, flag = 0, time_quantum,
		 wait_time = 0, turnaround_time = 0, at[10], bt[10], rt[10];
	printf("\nEnter total processes: ");
	scanf("%d", &n);
	remain = n;
	for (count = 0; count < n; count++) {
		printf("\nEnter arrival time and burst time for process %d: ", count + 1);
		scanf("%d", &at[count]);
		scanf("%d", &bt[count]);
		rt[count] = bt[count];
	}
	printf("\nEnter time quantum: ");
	scanf("%d", &time_quantum);

	system("clear");

	printf("\n Process\t| Turn around time(ms)  | Waiting Time(ms)\n");
	printf("===========================================================\n");

	for (time = 0, count = 0; remain != 0;) {
		if (rt[count] <= time_quantum && rt[count] > 0) {
			time += rt[count];
			rt[count] = 0;
			flag = 1;
		} else if (rt[count] > 0) {
			rt[count] -= time_quantum;
			time += time_quantum;
		} 
		if (rt[count] == 0 && flag == 1) {
			remain--;
			printf("%10d\t|%10d\t\t| %10d\n", count + 1, time - at[count], time - at[count] - bt[count]);
			wait_time += time - at[count] - bt[count];
			turnaround_time += time - at[count];
			flag = 0;
		}

		if (count == n - 1)
			count = 0;
		else if (at[count + 1] <= time)
			count++;
		else
			count = 0;
	}

	printf("\nAverage waiting time: %.2f ms", (float)(wait_time * (1.0 / n)));
	printf("\nAverage turn around time: %.2f ms\n", (float)(turnaround_time * (1.0/n)));

	return 0;

}