#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void * thfn(void * arg)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();

	printf("The new thread: pid is %u, tid is :%u\n",(unsigned int) pid,(unsigned int) tid);

	return NULL;
}

int main(void)
{
	pid_t pid;
	int err;
	pthread_t tid, mtid;
	
	pid = getpid();
	mtid = pthread_self();
	err = pthread_create(&mtid, NULL, thfn, NULL);

	if (err != 0){
		printf("Can't create thread %s\n",strerror(err));
		exit(1);
	}

	sleep(1);

	printf("The main thread: pid is %u, tid is :%u\n",(unsigned int)pid, (unsigned int)mtid);
	return 0;
}
