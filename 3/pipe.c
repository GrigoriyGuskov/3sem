/*

Программа аргументом командной строки имя файла, а затем передает его содержимое через pipe от родителя к ребенку.
Ребенок передает содержимое файла на стандартный вывод

*/
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
	
	
	int pipefd[2];
	
	int p = -1;
	
	p = pipe(pipefd);
	
	if(p == -1)
		abort();
	
	int f = -1;
	
	f = fork();
	
	if(f == -1)
		abort();
	
	if(f == 0)	{	//child read
		close(pipefd[1]);
		
		char buf[20];
		
		int sum = 0;
		
		for(unsigned int r = read(pipefd[0], buf, 20); r > 0; ) {
			sum += r;
			write(STDOUT, buf, r);
			r = read(pipefd[0], buf, 20);
		}
		
		printf("\n%d bytes was read\n", sum);
		
		close(pipefd[0]);
	}
	
	if(f) {			//parent write
		close(pipefd[0]);
		
		int fd = -1;
	
		fd = open(argv[1], O_RDONLY);
	
		if(fd == -1)
			abort();
		
		char buf[20];
		int sum = 0;
		for(unsigned int r = read(fd, buf, 20); r > 0; ) {
			sum += r;
			write(pipefd[1], buf, r);
			r = read(fd, buf, 20);
			
		}
		
		printf("\n%d bytes was written\n", sum);
		
		close(pipefd[1]);
	}
	
	return 0;
}