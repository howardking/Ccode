#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MASK S_IRUSR|S_IRGRP|S_IROTH
	
int main(void)
{

	int fd;
	mode_t mask;

	mask = umask(MASK);
	printf("The original mask is %x\n",(unsigned int)mask);

	if ((fd=open("test.txt1", O_CREAT, 0777))==NULL){
		perror("Fail to create");
		exit(1);
	}

	close(fd);

	return 0;
}
