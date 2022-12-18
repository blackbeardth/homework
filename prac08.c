// Practical 08
// WAP to implement SJF(Shorterst Job first) scheduling algorithm.
// Written by Chirag Wadhwa for the University of Delhi

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int bt[20], p[20], wt[20], tat[20],
	    i, j, n, total = 0, pos, temp;
	float avg_wt, avg_tat;

	printf("\nEnter number of processes: ");
	scanf("%d", &n);
	printf("Enter burst time(in milliseconds):\n");
	for (i = 0; i < n; i++) {
		printf("Process %d: ", i + 1);
		scanf("%d", &bt[i]);
		p[i] = i + 1;
	}
	//sorting burst time in ascending order using selection sort
	for (i = 0; i < n; i++) {
		pos = i;
		for (j = i + 1; j < n; j++) {
			if (bt[j] < bt[pos])
				pos = j;
		}
		temp = bt[i];
		bt[i] = bt[pos];
		bt[pos] = temp;// swap burst time of i and pos
		temp = p[i];
		p[i] = p[pos];
		p[pos] = temp;// swap process id of i and pos
	}
	//wt[0] = 0;  //waiting time for first process will be zero
	//calculate waiting time
	for (i = 1; i < n; i++) {
		wt[i] = 0;
		for (j = 0; j < i; j++)
			wt[i] += bt[j];
		total += wt[i];
	}
	avg_wt = (float)total / n;
	total = 0;

	system("clear");

	printf("\n Process | \tBurst time(in ms)  | Waiting Time(in ms)   | Turn Around Time(in ms)\n");
	printf("==================================================================================");
	for (i = 0; i < n; i++) {
		tat[i] = bt[i] + wt[i];
		total += tat[i];
		printf("\n%-10d |\t\t%-10d |\t\t%-10d |\t\t%-10d", p[i], bt[i], wt[i], tat[i]);
	}
	avg_tat = (float)total / n;
	printf("\n\nAvertage Waiting Time: %.2f ms", avg_wt);
	printf("\n\nAvertage Turnaround Time: %.2f ms\n", avg_tat);

	return 0;

}