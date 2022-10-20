#include <stdio.h>
#include <stdlib.h>

#include"sem.h"

int main() {
	
	int sem = sem_init(SEM_ID);
	
	printf("I'm waiting...\n");
	
	sem_p(sem);
	
	printf("Second process is finished\n");
		
		
	
	
	return 0;
}