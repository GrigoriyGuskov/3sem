#include <stdio.h>
#include <stdlib.h>

#include"bridge.h"


int main() {
	
	int sem = semget (SEM_ID, 4, 0666 | IPC_CREAT);
	
	struct sembuf sops[2] = {
		{bc, OPEN, 0},
		{bs, CLOSE, 0},
		};
	semop(sem, sops, 2);
	
	for(struct sembuf sop;;) {
		set_struct(&sop, c, 0, 0);
		semop(sem, &sop, 1);
		
		sops[0].sem_op = (sops[0].sem_op + 1) % 2;
		sops[1].sem_op = (sops[1].sem_op + 1) % 2;
		sleep(5);
		
		set_struct(&sop, s, 0, 0);
		semop(sem, &sop, 1);
		
		sops[0].sem_op = (sops[0].sem_op + 1) % 2;
		sops[1].sem_op = (sops[1].sem_op + 1) % 2;
		sleep(5);
	}
	
	return 0;
}