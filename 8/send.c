#include <stdio.h>

#include "mes.h"


int main() {
	
	key_t key = ftok(PATH, ID);
	
	int d = msgget(key, 0777 | IPC_CREAT);
	
	int n = 0;
	scanf("%d", &n);
	
	struct empty_msg endmes = {EXIT};
	struct empty_msg mes = {EMPTY};
	
	for (int i = 0; i < n; ++i) {
		msgsnd(d, &mes, 0, 0);
	}
	msgsnd(d, &endmes, 0, 0);
	
	return 0;
}