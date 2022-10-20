#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include "fifo.h"

void my_write(char * path) {


	int fd = open(path, O_WRONLY);
	
	char wbuf[BUF_SIZE] = {'\0'};
	
	int r = read(STDIN, wbuf, BUF_SIZE);
	write(fd, wbuf, r);
	
	close(fd);
}

void my_read(char * path) {

	int fd = open(path, O_RDONLY );
	
	if(fd == -1){
		printf("Can't read FIFO\n");
	}
		
	
	char rbuf[BUF_SIZE] = {'\0'};
	
	int r = read(fd, rbuf, BUF_SIZE);
	write(STDOUT, rbuf, r);
	close(fd);
}
