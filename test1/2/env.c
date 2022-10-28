#include<stdio.h>
#include<string.h>


int main(int argc, char **argv, char **envp) {
	
	FILE* file;
	if(argc < 2)
		file = fopen("ENV.txt", "w");
	else
		file = fopen(argv[1], "w");
		
	
	for(int i = 0; envp[i]; i++) {
		fprintf(file, "%s", envp[i]);
		fprintf(file, "\n");
	}
	
	return 0;
}