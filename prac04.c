// Practical 04
// WAP to print file details including owner permissions, file access time,
// where file name is given as an argument
// Written by Chirag Wadhwa for the University of Delhi

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>

int main(int argc, char *argv[3]) {
	struct stat buffer;
	for (int i = 1; i < argc; i++) {
		printf("File name: %s\n", argv[i]);
		if (stat(argv[i], &buffer) < 0)
			printf("An error occured, can not get file info...\n");
		else {
			printf("Owner: %d\nGid: %d\n", buffer.st_uid, buffer.st_gid);
			printf("Access Permission: %d\n", buffer.st_mode);
			printf("Last modified time: %s", ctime(&buffer.st_mtime));
		}
	}
	return 0;
}