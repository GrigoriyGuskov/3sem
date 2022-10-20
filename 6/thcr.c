#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arg = 0;

void * func (void * a) {
	printf("my pthread: %ld\n", pthread_self());
	arg++;
	printf("var: %d\n", arg);
	return a;
}

int main() {

	long int * pth;
	
	int n = 0;
	scanf("%d", &n);
	
	pth = calloc(n, sizeof(long int));
	
	for(int i = 0; i < n; i++)
		pthread_create(&(pth[i]), NULL, func, NULL);
		
	for(int i = 0; i < n; i++)
		pthread_join(pth[i], NULL);
	
	arg++;
	
	printf("my own pthread: %ld\n", pthread_self());

	printf("var: %d\n", arg);
	
	return 0;
}