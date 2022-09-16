#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

enum STREAMS {
	STDIN = 0,
	STDOUT,
	STDERR,
};

int main(int argc, char ** argv) {
	
	if(argc < 2)
		abort();
	
	int fd = -1;
	
	fd = open(argv[1], O_RDONLY);
	
	if(fd == -1)
		abort();
	
	char buf[20];
	
	for(unsigned int r = read(fd, buf, 20); r > 0; ) {
		write(STDOUT, buf, r);
		r = read(fd, buf, 20);
	}
	
	printf("\n");
	
	
	
	close(fd);
	
	return 0;
}