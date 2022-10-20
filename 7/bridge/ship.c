#include <stdio.h>
#include <stdlib.h>

#include"bridge.h"


int main() {
	
	int sem = semget (SEM_ID, 3, 0666 | IPC_CREAT);
	struct sembuf sops[2] = {
		{bc, CLOSE, 0},
		{bs, CLOSE, 0},
		};
	semop(sem, sops, 2);
	
	struct sembuf sop = {s, 1, 0};
	semop(sem, &sop, 1);
	
	set_struct(&sop, bs, OPEN, 0);
	semop(sem, &sop, 1);
	
	sleep(1);
	
	set_struct(&sop, s, -1, 0);
	semop(sem, &sop, 1);
	
	return 0;
}