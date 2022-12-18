// Practical 11
// WAP to implement SRJF(Shortest Remaining Job First) scheduling algorithm.
// Written by Chirag Wadhwa for the University of Delhi

#include <stdio.h>

int main(void) {
	int n, ari[10], bur[10], total = 0, i, j, small, temp, procs[100], k, waiting[10], finish[10];
	float tavg = 0.0, wavg = 0.0;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("Enter the arrival time of processes %d:\t", i);
		scanf("%d", &ari[i]);
		printf("Enter the burst time of process %d:\t", i);
		scanf("%d", &bur[i]);
		waiting[i] = 0;
		total += bur[i];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if(ari[i] > ari[j]) {
				temp = ari[i];
				ari[i] = ari[j];
				temp = bur[i];
				bur[i] = bur[j];
				bur[j] = temp;
			}
		}
	}
	for (i = 0; i < total; i++) {
		small =3200;
		for (j = 0; j < n; j++) {
			if ((bur[j] != 0) && (ari[j] <= i) && (bur[j] < small)) {
				small = bur[j];
				k = j;
			}
		}
		bur[k]--;
		procs[i] = k;
	}
	k = 0;
	for (i = 0; i < total; i++) {
		for (j = 0; j < n; j++) {
			if (procs[i] == j) {
				finish[j] = i;
				waiting[j]++;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("\nProcess %d: Finish time -> %d Turn Around Time -> %d Waiting Time - > %d\n", i + 1, finish[i] + 1, (finish[i] - ari[i] + 1), ((finish[i] + 1) - waiting[i] - ari[i]));
		wavg = wavg + ((finish[i] + 1) - waiting[i] - ari[i]);
		tavg = tavg + ((finish[i] - ari[i] + 1));
	}
	printf("\nWAVg - > \t%f\n TAVG -> \t%f\n", (wavg / n), (tavg / n));
	return 0;
}