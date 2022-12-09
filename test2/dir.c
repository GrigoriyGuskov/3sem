#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>

struct count {
	unsigned fcounter;
	unsigned hl2counter;
};

struct count file_counter(const char * Path);


int main(int argc, char ** argv){
	
	if(argc < 2){
		printf("I need directory name\n");
		abort();
	}
	
	struct count fn = file_counter(argv[1]);
	
	printf("Number of files: %u\n", fn.fcounter);
	printf("Number of files with 2 or more hard links: %u\n", fn.hl2counter);
	
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir (argv[1])) != NULL) {
		rewinddir(dir);
	
		while ((ent = readdir (dir)) != NULL) {
			if(ent->d_type == DT_DIR) 
				printf ("%s\n", ent->d_name);
		}
		closedir (dir);
	} else {
	printf("Can't open: %s\n", argv[1]);
	perror(NULL);
	}

	return 0;
}


struct count file_counter(const char * Path) {
	
	char * buf = calloc(100, sizeof(char));
	
	strcpy(buf, Path);
	
	struct count ret;
	ret.fcounter = 0;
	ret.hl2counter = 0;
	
	DIR *dir;
	
	struct dirent *ent;
	struct stat inf;
	
	if ((dir = opendir (Path)) != NULL) {
		rewinddir(dir);
	
		for (; (ent = readdir(dir)) != NULL; ) {
			if(strcmp(ent->d_name, "..") && strcmp(ent->d_name, ".")) {
				ret.fcounter++;
				
				if(ent->d_type == DT_DIR) {
					strcat(buf, "/");
					strcat(buf, ent->d_name);
					struct count tmp = file_counter(buf);
					ret.fcounter += tmp.fcounter;
					ret.hl2counter += tmp.hl2counter;
					
					buf[0] = '\0';
					strcat(buf, Path);
					
				} else {
					stat(ent->d_name, &inf);
					
					if(inf.st_nlink > 1)
						ret.hl2counter++;
				}
			}
		}
		closedir (dir);
	} else {
		
		printf("Can't open: %s\n", Path);
		
		perror(NULL);
			
	}
	
	
	return ret;
	
}