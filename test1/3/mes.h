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
	INFO,
};

struct msgbuf {
	long mtype;
	char data[21];
};

struct msginf {
	long mtype;
	int n;
};

struct empty_msg {
	long mtype;
};
