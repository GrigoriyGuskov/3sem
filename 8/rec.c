#include <stdio.h>

#include "mes.h"


int main() {
	
	key_t key = ftok(PATH, ID);
	
	int d = msgget(key, 0777 | IPC_CREAT);
	
	int counter = 0;

	struct empty_msg mes = {0};
	
	for (;mes.mtype != 1;counter++) {
		msgrcv(d, &mes, 0, 0, 0);
	}
	
	printf("Received %d messages\n", counter);
	
	msgctl(d, IPC_RMID, NULL);
	
	return 0;
}