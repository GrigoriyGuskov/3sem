#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include "fifo.h"

int main(int argc, char ** argv) {
	
	if(argc < 3) {
		printf("Too few arguments\n");
		abort();
	}
	
	char fifo_read[20] = {'\0'};
	char fifo_write[20] = {'\0'};
	
	
	strcat(fifo_read, argv[1]);
	strcat(fifo_read, FIFO_PATH);
	
	strcat(fifo_write, argv[2]);
	strcat(fifo_write, FIFO_PATH);

	
	remove(fifo_write);

	mkfifo(fifo_write, 0777);
	
	char fl = 0;
	
	for(scanf("%c", &fl); fl != 'q'; ) {
		
		if(fl == 's') {
			my_write(fifo_write);
		} else if(fl == 'r') {
			my_read(fifo_read);
		} else if(fl == '\n') {
		} else {
			printf("Unknown command\n");
		}
		scanf("%c", &fl);
	}
		

	
	return 0;
}