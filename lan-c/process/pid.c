#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid,ppid,uid,euid,gid,egid;
	
	pid = getpid();
	ppid = getppid();
	uid = getuid();
	euid = geteuid();
	gid = getgid();
	egid = getegid();

	printf("id of current process:%u\n",pid);
	printf("ppid of current process:%u\n",ppid);
	printf("uid of current process:%u\n",uid);
	printf("euid of current process:%u\n",euid);
	printf("gid of current process:%u\n",gid);
	printf("egid of current process:%u\n",egid);
	
	return 0;
}
