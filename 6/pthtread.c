#include <stdio.h>
#include <pthread.h>


int main() {
	
	printf("pthread: %ld\n", pthread_self());
	return 0;
}