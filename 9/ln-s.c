#include <unistd.h>
#include<stdlib.h>


int main(int argc, char ** argv) {
	if(argc < 3) 
		abort();
	
	symlink(argv[1], argv[2]);
	
	return 0;
}