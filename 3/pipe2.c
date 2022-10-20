/*

Программа создает 4 процесса.
Главный родительский процесс принимает сообщения от трёх других.
Дети берут аргумент командной строки, соответствующий их номеру и передают через единый pipe родителю.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>




int main(int argc, char ** argv) {
	
	int pipefd[2];
	int p = -1;
	
	p = pipe(pipefd);
	
	if(p == -1)
		abort();
	
	int id = 0;
	
	int f = -1;
	
	for(int i = 0; i < 2; i++) {
		f = fork();
		if(f == -1)
			abort();
		
		id = (id << 1) + !(f || 0); 
	}
	
	if(id == 0) { //parent
		close(pipefd[1]);
		char buf[100] = {'\0'};
		int chid = 0;
		for(unsigned int r = read(pipefd[0], buf, 99); r > 0; ) {
			
			chid = buf[0] - '0';
			
			switch(chid) {
				case 1:
					printf("My second child: ");
					break;
					
				case 2:
					printf("My first child : ");
					break;
					
				case 3:
					printf("Child of my first child: ");
					break;
					
				default:
					printf("Unknown child: ");
					break;
			}
			
			printf("%s\n", buf + 1);
			
			r = read(pipefd[0], buf, 99);
			
		}
		
		
		
		close(pipefd[0]);
		
	} else {
		close(pipefd[0]);
		char id_let = '0' + id;
		char buf[100] = {'\0'};
		//char message[99] = {"Some message\n"};
		
		
		
		buf[0] = id_let;
		
		strncat(buf, argv[id], 98);
		
		write(pipefd[1], buf, 99);
		
		close(pipefd[1]);
		
	}
	
	
	return 0;
}