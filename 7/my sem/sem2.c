#include <stdio.h>
#include <stdlib.h>

#include"sem.h"

int main() {
	
	int sem = sem_init(SEM_ID);
	
	
	printf("I am finished\n");
		
	sem_v(sem);
	
	
	return 0;
}