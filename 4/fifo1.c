#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include "fifo.h"

int main() {
	
	remove(FIFO_PATH);
	
	int mkf = mkfifo(FIFO_PATH, 0777);
	
	if(mkf == -1)
		abort();
	
	
	int f = -1;
	
	f = fork();
	
	
	if(f == -1)
		abort();

	if(f == 0)	{	//child

		int fd = open(FIFO_PATH, O_WRONLY);
		write(fd,"Hello, World!", 14);
		close(fd);
		
	} else {			//parent
		int fd = open(FIFO_PATH, O_RDONLY);
		char buf[20];
		read(fd, buf, 14);
		printf("%s\n", buf);
		close(fd);
		
	}

	return 0;
}