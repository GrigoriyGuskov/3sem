#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "mes.h"


int main(int argc, char ** argv) {
	
	if(argc < 2)
		abort();
	
	key_t key = ftok(PATH, ID);
	
	int d = msgget(key, 0777 | IPC_CREAT);
	
	struct msgbuf mes;
	
	switch(*(argv[1])) {
		case'r':												//receiver
			mes.mtype = 0;
			for (;mes.mtype != EXIT;) {
				for(int i  = 0; i < 21; ++i)
					mes.data[i] = '\0';
				int size = msgrcv(d, &mes, 20 * sizeof(char), 0, 0);
				if (size > 0)
					printf("%s", mes.data);
			}
			
			msgctl(d, IPC_RMID, NULL);
			break;
			
		case 's':													//sender
			mes.mtype = TEXT;
			struct empty_msg endmes = {EXIT};
			int size = 100;
			for (;size > 0;) {
				size = read(STDIN, mes.data, 20);
				msgsnd(d, &mes, size * sizeof(char), 0);
			}
			msgsnd(d, &endmes, 0, 0);
			break;
			
		case 'w':												//wait
			printf("I'm doing some code...\n");
			
			for(msgrcv(d, &mes, 0, 0, 0); mes.mtype != SINCHR && mes.mtype != EXIT; )
				msgrcv(d, &mes, 0, 0, 0);
			msgctl(d, IPC_RMID, NULL);
			break;
		
		case 'e':												// send empty messages
			struct empty_msg em;
			int m;
			for(int sc = scanf("%d", &m); sc > 0; ) {
				em.mtype = m;
				msgsnd(d, &em, 0, 0);
				if(m == EXIT)
					break;
				sc = scanf("%d", &m);
				
			}
		break;
		
		default:									
			printf("It is nor sender or receiver\n");
			msgctl(d, IPC_RMID, NULL);
			break;
		
	}
	return 0;
}