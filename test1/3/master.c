#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "mes.h"


int main() {

	
	key_t key = ftok(PATH, ID);
	
	int d = msgget(key, 0777 | IPC_CREAT);

	struct msgbuf mes;
	
	struct empty_msg endmes = {EXIT};
	int size = 20;
	for(; size > 0; ) {
		mes.mtype = TEXT;
		for(int i  = 0; i < 21; ++i)
			mes.data[i] = '\0';
		
		size = read(STDIN, mes.data, 20);
		msgsnd(d, &mes, size * sizeof(char), 0);
		
	}
	msgsnd(d, &endmes, 0, 0);

	return 0;

}