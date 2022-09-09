#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main() {
	
	int f = -1;
	
	f = fork();
	
	int ppid = 0, pid = 0;
	
	if(f == -1)
		abort();
	
	if(f == 0)	{	//child
		ppid = getppid();
		pid = getpid();
	
		printf("I'm child\nppid = %d\npid = %d\n", ppid, pid);
	} else {			//parent
		ppid = getppid();
		pid = getpid();
	
		printf("I'm parent\nppid = %d\npid = %d\nid of my child: %d\n", ppid, pid, f);
	}
	
	
	
	return 0;
}