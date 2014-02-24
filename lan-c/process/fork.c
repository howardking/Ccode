#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	
	pid = fork();

	if (pid<0){
		printf("fail to fork\n");
		exit(1);
	}
	else if (0 == pid){
		printf("this is child ,pid is:%u\n",getpid());
	}
	else {
		sleep(1);
		printf("This is a parent,pid is:%u,child-pid is %u\n",getpid(),pid);
	}
	return 0;
}
