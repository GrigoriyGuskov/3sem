#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


struct empty_msg {
	long mtype;
};

int main(int argc, char ** argv) {
	
	if(argc < 2) {
		printf("Too few arguments\n");
		abort();
	}
	
	int n = atoi(argv[1]);
	
	int pid = 0;
	int id = 0;
	
	key_t key = ftok("ftok", 1000);
	
	int d = 0;
	struct empty_msg mes = {0};
	
	for(int i = 0; i <n; ++i) {
		if(pid == 0)
			pid = fork();
	
		if(pid == 0)
			++id;
		else if(pid == -1)
			abort();
	}
	
		if(id == 0) {					// main process
			d = msgget(key, 0777 | IPC_CREAT);
			
			for(int i = 1; i <= n; ++i) {
				mes.mtype = i;
				msgsnd(d, &mes, 0, 0);
			}
			
			sleep(1);
			
			msgctl(d, IPC_RMID, NULL);
			
		} else {
			d = msgget(key, 0777);
			msgrcv(d, &mes, 0, id, 0);
			printf("I got message\n");
		}
		
	return 0;
}