#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int main(int argc, char **argv) {
	if(argc < 2) 
		abort();
	
	struct stat info;
	
	int f = stat(argv[1], &info);
	
	if(f)
		abort();
	
	
	printf("File name: %s\n", argv[1]);
	
	printf("ID of device containing file: %lu\n", info.st_dev);
	printf("Inode number: %lu\n", info.st_ino);
	printf("File type and mode: %u\n", info.st_mode);
	printf("Number of hard links: %lu\n", info.st_nlink);
	printf("User ID of owner: %u\n", info.st_uid);
	printf("Group ID of owner: %u\n", info.st_gid);
	printf("Device ID (if special file): %lu\n", info.st_rdev);
	printf("Total size, in bytes: %lu\n", info.st_size);
	printf("Block size for filesystem I/O: %lu\n", info.st_blksize);
	printf("Number of 512B blocks allocated: %lu\n", info.st_blocks);
	
	printf("Time of last access: %lu\n", info.st_atime);
	printf("Time of last modification: %lu\n", info.st_mtime);
	printf("Time of last status change: %lu\n", info.st_ctime);
	
	

	
	
	return 0;
}