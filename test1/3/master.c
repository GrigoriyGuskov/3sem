#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "mes.h"


int main(int argc, char **argv) {

	
	key_t key = ftok(PATH, ID);
	
	int d = msgget(key, 0777 | IPC_CREAT);

	struct msgbuf mes;
	
	struct msginf info;
	info.mtype = INFO;
	info.n = argc - 1;
	msgsnd(d, &info, sizeof(int), 0);

	struct empty_msg endmes = {EXIT};

	for(int i = 1; i < argc; ++i){
		mes.mtype = TEXT;
		for(int i  = 0; i < 21; ++i)
			mes.data[i] = '\0';
		strcpy(mes.data, argv[i]);
		msgsnd(d, &mes, sizeof(argv[i]), 0);
	}
	msgsnd(d, &endmes, 0, 0);

	return 0;

}