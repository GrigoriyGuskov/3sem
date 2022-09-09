#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main() {
	
	int f = -1;
	
	f = fork();
	
	
	if(f == -1)
		abort();
	
	if(f == 0)	{	//child
		
	}
	
	if(f) {			//parent
		
	}
	
	return 0;
}