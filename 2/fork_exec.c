#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char **argv) {
	
	
	int f = -1;
	
	f = fork();
	
	
	if(f == -1)
		abort();
	
	if(f == 0)	{	//child
		f = -1;
	
		f = execvp(argv[1],  argv + 1);
	
		if(f == -1)
			abort();
	}
	
	if(f) {			//parent
		for(int i = 0; i < 1000; i++)
			printf("%d\n", i);
	}
	
	return 0;
}