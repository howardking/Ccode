#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(void)
{
	int fd;
	
	if ((fd=open("no_sucn_a_file",O_RDWR))==-1){
		printf("fail to open file\n");
		printf("%s\n",strerror(errno));
		perror("Error:");
		exit(errno);
	}
	
	return 0;
} 
