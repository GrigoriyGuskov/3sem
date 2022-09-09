#include<stdio.h>
#include<string.h>


int main(int argc, char **argv, char **envp) {
	
	for(int i = 0; envp[i]; i++) {
		printf("%s", envp[i]);
		printf("\n");
	}
	
	return 0;
}