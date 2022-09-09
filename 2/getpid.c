#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main() {
	
	int ppid = 0, pid = 0;
	
	ppid = getppid();
	pid = getpid();
	
	printf("ppid = %d\npid = %d\n", ppid, pid);
	
	return 0;
}