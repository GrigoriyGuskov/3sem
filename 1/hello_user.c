#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int find_user(FILE* fd, unsigned int userid, char* name);
void get_username(FILE* fd, unsigned int userid);



int main() {

	FILE* fd = fopen("log", "a+");
	
	unsigned int userid = 0;

	userid = getuid();
	
	char name[20];
	
	if(find_user(fd, userid, name))
		printf("Hello, %s\n", name);
	else
		get_username(fd, userid);
	
	fclose(fd);
	
	return 0;
}

int find_user(FILE* fd, unsigned int userid, char* name) {
	unsigned uid = 0;
	int f = 0;
	for(f = fscanf( fd, "%u%s", &uid, name);f != EOF && f != 0;f = fscanf( fd, "%u%s", &uid, name)) {
		if(uid == userid) 
			return 1;
	}
	return 0;
}

void get_username(FILE* fd, unsigned int userid) {
	char name[20];
	printf("What is your name?\n");
	scanf("%s", name);
	printf("Hello, %s\n", name);
	fprintf(fd, "%u %s\n", userid, name);	
}
