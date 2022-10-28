#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "mes.h"

int main() {
	
	key_t key = ftok(PATH, ID);
	
	int d = msgget(key, 0777 | IPC_CREAT);
	
	int pid;
	
	struct msgbuf mes;
	mes.mtype = 0;
	
	char ** argv = calloc(5, sizeof(char*));
	char * res = NULL;
	
	for (; mes.mtype != EXIT; ) {
		
		for(int i  = 0; i < 21; ++i)
			mes.data[i] = '\0';
		
		int size = msgrcv(d, &mes, 20 * sizeof(char), 0, 0);
		
		if (size > 0) {
			res = strtok(mes.data, " 	\n");
			
			for(int j = 0; res; ++j) {
				argv[j] = calloc(strlen(res) + 1, sizeof(char));
				strcpy(argv[j], res);
				res = strtok(NULL, " 	\n");
			}
			
			pid = fork();
			if(pid == 0)
				execvp(argv[0], argv);
			for(int i = 0; i < 5; ++i) {
				free(argv[i]);
				argv[i] = NULL;
			}
		}
		
	}
	
	
	msgctl(d, IPC_RMID, NULL);
	
	free(argv);
	
	return 0;
}