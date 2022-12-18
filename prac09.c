// Practical 09
// WAP to implement non-preemptive priority based sheduling algorithm
// Written by Chirag Wadhwa for University of Delhi

#include <stdio.h>

int main(void) {
	int bt[20], p[20], wt[20], tat[20], pr[20],
		i, j, n, total = 0, pos, temp;
	float avg_wt, avg_tat;
	printf("Enter total number of processes: ");
	scanf("%d", &n);
	printf("Enter burst time and priority:\n");
	for (i = 0; i < n; i++) {
		printf("Process %d: ", i + 1);
		scanf("%d %d", &bt[i], &pr[i]);
		p[i] = i + 1; // p[i] = process id
	}
	//sorting burst time, priority and process number in ascending order using selection sort
	for (i = 0; i < n; i++) {
		pos = i;
		for (j = i + 1; j < n; j++) {
			if (pr[j] < pr[pos]) 
				pos = j;
		}
		temp = pr[i];
		pr[i] = pr[pos];
		pr[pos] = temp; // exchange priority of i and pos 
		temp = bt[i];
		bt[i] = bt[pos];
		bt[pos] = temp;// exchange burst time of i and pos 
		temp = p[i];
		p[i] = p[pos];
		p[pos] = temp;// exchange process id of i and pos
	}
	//wt[0] = 0;  //waiting time for first process is zero
	//calculate waiting time
	for (i = 1; i < n; i++) {
		wt[i] = 0;
		for (j = 0; j < i; j++) 
			wt[i] += bt[j];
		total += wt[i];
	}
	avg_wt = (float)total / n;
	total = 0;
	printf("\n Process\tBurst Time\t"
			"Waiting Time\tTurn Around Time\n");
	printf("===================================================================\n");
	for (i = 0; i < n; i++) {
		tat[i] = bt[i] + wt[i];
		total += tat[i];
		printf("    %d\t\t   %d\t\t   %d\t\t   %d\n", p[i], bt[i], wt[i], tat[i]); 
	}
	avg_tat = (float)total / n;
	printf("\nAverage Waiting Time: %.2f", avg_wt);
	printf("\nAverage Turnaround Time: %.2f\n", avg_tat);

	return 0;

}