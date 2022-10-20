#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEM_ID	1000

int sem_init(int id) {
	
	int semid = semget (id, 1, 0666 | IPC_CREAT);
	
	return semid;
}

void sem_p(int sem) {
	struct sembuf sop = {0, -1, 0};
	semop(sem, &sop, 1);
}

void sem_v(int sem) {
	
	struct sembuf sop = {0, 1, 0};
	semop(sem, &sop, 1);
	
}
