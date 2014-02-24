#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define BUFSZ 4096

struct msg{
	long msg_types;
	char msg_buf[511];
};

int main(int argc, char * argv[])
{	
	int qid;
	int len;
	struct msg pmsg;
	
	if (2 != argc){
		perror("USAGE:read_msg <queue ID>");
		exit(1);
	}

	qid = atoi(argv[1]);

	len = msgrcv (qid, &pmsg, BUFSZ, 0, 0);
	if (len>0){
		pmsg.msg_buf[len] = '\0';
		printf("Reading queue ID :%05ld\n",qid);
		printf("Message type is :%05ld\n",pmsg.msg_types);
		printf("Message length is :%05ld\n",len);
		printf("Message text :%s\n",pmsg.msg_buf);
	}else if(0 == len){
		printf("have no message from queue\n");
	}else{
		perror("msgrcv");
		exit(1);
	}

	system("ipcs -q");
	return 0;
}

