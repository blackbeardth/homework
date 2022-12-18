// Practical 05
// WAP to copy files using system calls
// Written by Chirag Wadha for the University of Delhi

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void copy(int, int);
void display(int);

int main(int argc, char *argv[]) {
	int fold, fnew;
	if(argc != 3) {
		printf("Two arguments Required...");
		exit(-1);
	}
	fold = open(argv[1], 0);
	if (fold == -1) {
		printf("Unable to open the file\n%s", argv[1]);
		exit(-1);
	}
	fnew = creat(argv[2], 0666);
	if (fnew == -1) {
		printf("unable to create the file%s\n", argv[2]);
		exit(-1);
	}
	copy(fold, fnew);
	exit(0);
	close(fold);
	close(fnew);
	fnew = open(argv[2], 0);
	printf("new file:\n");
	close(fnew);
	exit(0);
}
void copy(int old, int new) {
	int count = 0;
	char buffer[512];
	while((count = read(old, buffer, sizeof(buffer))) > 0) {
		write(new, buffer, count);
	}
}
void display(int fnew) {
	int count = 0, i;
	char buffer[512];
	while((count = read(fnew, buffer, sizeof(buffer))) > 0) {
		for (int i = 0; i < count; i++) {
			printf("%c", buffer[i]);
		}
	}
	for (int i = 0; i < count; i++) {
		printf("%c", buffer[i]);
	}
}
