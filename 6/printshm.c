#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "shmem.h"


int main () {
	
	int shmid = 0; 
	
	int *pointer = NULL;
	
	shmid = shmget (SHM_ID, SHM_SIZE, 0666 | IPC_CREAT);
	assert(shmid > 0);
	
	pointer = shmat(shmid, 0, 0);
	assert(pointer);
	
	for(int i = 0; i < 6; i++)
		printf("p[%d] = %d\n", i, pointer[i]);
	
	shmdt(pointer);
	return 0;
}