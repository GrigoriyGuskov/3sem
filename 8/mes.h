#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define PATH "ftok"

#define ID	1000

enum STREAMS {
	STDIN = 0,
	STDOUT,
	STDERR,
};

enum TYPES {
	EXIT = 1,
	EMPTY,
	TEXT,
	SINCHR,
};

struct msgbuf {
	long mtype;
	char data[21];
};

struct empty_msg {
	long mtype;
};
