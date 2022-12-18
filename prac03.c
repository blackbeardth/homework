// Practical 03
// WAP to report behaviour of Linux Kernel including information on configured
// memory, amount of free and used memory(memory information).
// Written by Chirag Wadhwa for the University of Delhi

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	printf("\nKernel Version:\n");
	system("cat /proc/sys/kerenel/osrelease");
	printf("\nConfigured free and used memory:\n");
	system("cat /proc/meminfo | awk 'NR == 1, NR == 2 {print}'");

	return 0;
}