#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include "shmem.h"


int main (int argc, char ** argv) {
	
	int * sem = sem_init(SEM_ID);
	
	
	if(argc < 2) {
		printf("Too few arguments\n");
		abort();
	}
	
	
	int shmid = 0; 
	
	int *pointer = NULL;
	
	shmid = shmget (SHM_ID, SHM_SIZE, 0666 | IPC_CREAT);
	assert(shmid > 0);
	
	pointer = shmat(shmid, 0, 0);
	assert(pointer);
	
	sem_v(sem);
	
	pointer[1]++;
	pointer[2]++;
	pointer[4]++;
	pointer[5]++;
	
	long int * pth;
	
	int n = 0;
	
	n = atoi(argv[1]);
	
	pth = calloc(n, sizeof(long int));
	
	for(int i = 0; i < n; i++) {
		pthread_create(&(pth[i]), NULL, func, &(pointer[4]));
		pointer[5]++;
	}
	
	for(int i = 0; i < n; i++)
		pthread_join(pth[i], NULL);
	

	return 0;
}