#ifndef DE
#define DE
#include <stdio.h>
#include <stdlib.h>
#endif

void f1 (void)
{
	printf("The first exit handler\n");
}
void f2 (void)
{
	printf("The second exit handler\n");
}

int main (void)
{
	if (atexit(f1) == -1){
		perror("fail to set exit handler\n");
		exit(1);
	}
	if (atexit(f1) == -1){
		perror("fail to set exit handler\n");
		exit(1);
	}
	if (atexit(f2) == -1){
		perror("fail to set exit handler\n");
		exit(1);
	}	
	return 0;
}
