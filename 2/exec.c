#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc, char **argv) {
	
	int f = -1;
	
	f = execvp(argv[1],  argv + 1);
	
	if(f == -1)
		abort();
	return 0;
}