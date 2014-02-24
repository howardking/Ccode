#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	int qid;
	
	if (2 != argc){
		puts("USAGE:del_msqg.c <queue ID>");
		exit(1);
	}
	qid = atoi(argv[1]);
	system("ipcs -q");
	if((msgctl(qid, IPC_RMID, NULL))<0){
		perror("msgct1");
		exit(1);
	} 

	system("ipcs -q");
	printf("Successfully removed %d queue\n",qid);

	return 0;
}
