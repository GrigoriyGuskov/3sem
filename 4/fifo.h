#define FIFO_PATH "some_fifo"
#define BUF_SIZE 1000

enum STREAMS {
	STDIN = 0,
	STDOUT,
	STDERR,
};


void my_write(char * path);

void my_read(char * path);