#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "mes.h"

int main() {
	
	key_t key = ftok(PATH, ID);
	
	int d = msgget(key, 0777 | IPC_CREAT);
	
	struct msgbuf mes;
	mes.mtype = 0;
	
	struct msginf info;

	msgrcv(d, &info, sizeof(int), INFO, 0);
	
	int n = info.n;
	
	char ** argv = calloc(n, sizeof(char*));


	for (int j = 0; mes.mtype != EXIT; ++j) {
		for(int i  = 0; i < 21; ++i)
			mes.data[i] = '\0';
		int size = msgrcv(d, &mes, 20 * sizeof(char), 0, 0);
		if (size > 0) {
			argv[j] = calloc(size + 1, sizeof(char));
			strncpy(argv[j], mes.data, size);
		}
	}
	if(n > 0)
		execvp(argv[0],  argv);
	
	msgctl(d, IPC_RMID, NULL);
	
	return 0;
}