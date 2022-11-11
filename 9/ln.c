#include <unistd.h>
#include<stdlib.h>


int main(int argc, char ** argv) {
	if(argc < 3) 
		abort();
	
	link(argv[1], argv[2]);
	
	return 0;
}