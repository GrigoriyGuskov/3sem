#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEM_ID	1000

enum objects {
	bc = 0,
	bs = 1,
	c = 2,
	s = 3,
};

enum condition {
	OPEN = 0,
	CLOSE = 1,
};

void set_struct(struct sembuf * sop, short num, short op, short flg) {
	sop->sem_num = num;
	sop->sem_op = op;
	sop->sem_flg = flg;
}