#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	int shm_id;
	char * shm_buf;

	if (2 != argc){
		printf("USAFE:atshm <identifier>\n");
		exit(1);
	}

	shm_id = atoi(argv[1]);

	if ((shm_buf=shmat(shm_id,0,0))<(void *)0){
		perror("shmat");
		exit(1);
	}

	printf("segment attached at %p\n",shm_buf);
	system("ipcs -m");

	sleep(3);
	
	if ((shmdt(shm_buf))<0){
		perror("shndt");
		exit(1);
	}

	printf("segment detached\n");
	system("ipcs -m");

	return 0;
}
