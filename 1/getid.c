#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

	unsigned int uid = 0, gid = 0;

	uid = getuid();
	gid = getgid();
	
	printf("user ID: %u\ngroup ID: %u\n", uid, gid);

	return 0;
}

