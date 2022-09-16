#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char ** argv) {
	
	if(argc < 2)
		abort();
	
	int fd = -1;
	
	fd = open(argv[1], O_WRONLY | O_CREAT, 00777);
	
	if(fd == -1) {
		printf("Can't open %s\n", argv[1]);
		abort();
	}
	
	char buf[20] = {"Hello, World!\n"};
	
	printf("%ld bytes was written\n", write (fd, buf, sizeof(buf)));
	
	
	close(fd);
	
	return 0;
}