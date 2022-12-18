// Practical 10
// WAP to implement preemptive priority based scheduling algorithm

// Written by Chirag Wadhwa for the University of Delhi

#include <stdio.h>

int main(void) {
	int i, j, n, time, sum_wait = 0, sum_turnaround = 0, smallest,
	                   at[10], bt[10], pt[10], rt[10], remain;

	printf("Enter number of processes: ");
	scanf("%d", &n);
	remain = n; // remain in reaming processes
	printf("Enter arrival time, burst time and priority:\n");
	for (i = 0; i < n; i++) {
		printf("Process %d: ", i + 1);
		scanf("%d %d %d", &at[i], &bt[i], &pt[i]);
		rt[i] = bt[i];
	}
	pt[9] = 11;
	printf("\n Process\tTurnaround Time \tWaiting Time\n");
	printf("=====================================================\n");
	for (time = 0; remain != 0; time++) {
		smallest = 9;
		for (i = 0; i < n; i++) {
			if (at[i] <= time && pt[i] < pt[smallest] && rt[i] > 0) {
				smallest = i;
			}
		}
		rt[smallest]--;
		if (rt[smallest] == 0) {
			remain--;
			printf("   %d\t\t    %d\t\t\t   %d\n", smallest + 1,
			       time + 1 - at[smallest], // time + 1 = completion time ; TAT = CT -AT
			       time + 1 - at[smallest - bt[smallest]]); // WT = TAT - BT
			sum_wait += time + 1 - at[smallest] - bt[smallest];
			sum_turnaround += time + 1 - at[smallest];
		}
	}
	printf("\nAverage Waiting Time: %.2f\n", sum_wait * 1.0 / n);
	printf("Average Turnaround Time: %.2f\n", sum_turnaround * 1.0 / n);

	return 0;

}