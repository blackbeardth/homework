// Practical 02
// WAP to report behaviour of Linux Kernel including kernel version, CPU type and model.
// Written by CHirag Wadhwa for the University of Delhi

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	printf("\nKernel version:\n");
	system("cat /proc/sys/kernel/osrelease");
	printf("\nCPU info:\n");
	system("cat /proc/cpuinfo");

	return 0;
}