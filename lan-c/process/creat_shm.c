#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

#define BUFES 4096

int main(void)
{
	int shm_id;
	
	shm_id = shmget(IPC_PRIVATE, BUFES, 0666);
	if (shm_id<0){
		perror("shmget");
		exit(1);
	}

	printf("Successfully created segment: %d\n",shm_id);
	system("ipcs -m");

	return 0;
}
