#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>


#define SHM_ID	1234
#define SEM_ID	1000
#define SHM_SIZE 24


int * sem_init(int id) {
	
	int shmid = shmget (id, sizeof(int), 0666 | IPC_CREAT);
	assert(shmid > 0);
	
	int *sem = shmat(shmid, 0, 0);
	
	//printf("%p\n", sem);
	
	return sem;
}

void sem_p(int *sem) {
	
	for(;*sem < 1;) {}

	*sem = *sem - 1;
}

void sem_v(int *sem) {
	*sem = *sem + 1;
}

void sem_free(int *sem) {
	*sem = 0;
	shmdt(sem);
}

void * func (void * a) {
	int * p = (int*)a;
	(*p)++;
	return a;
}