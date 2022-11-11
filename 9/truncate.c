#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>



int main(int argc, char **argv) {
	if(argc < 2) 
		abort();
	
	int fd = open(argv[1], O_RDWR | O_CREAT);
	
	struct stat info;
	
	int f = fstat(fd, &info);
	
	if(f)
		abort();
	
	unsigned long size = info.st_size;
	
	ftruncate(fd, size + 20);
	
	lseek(fd, size, SEEK_SET);
	
	write(fd, "Additional text", sizeof("Additional text"));
	
	
	
	
	return 0;
}