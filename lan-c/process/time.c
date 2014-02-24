#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void timer_hander(int signo)
{
	if (SIGALRM == signo){
		printf("The timer is on\n");
		exit(0);
	}else{
		printf("Unexcepted signal\n");
	}
}

int main(void)
{
	if (signal(SIGALRM, timer_hander)==SIG_ERR){
		perror("Can't set hander for SIGALRM");
		exit(0);
	}
	alarm(1);
	while(1){
		printf("Too early\n");
	}

	printf("Should not be here, never\n");
	return 0;
}
