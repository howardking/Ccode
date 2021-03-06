#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	int fd;
	int flag;
	char *p = "1st linux";
	char *q = "2nd linux";

	fd = open("test.txt", O_WRONLY);
	if (-1 == fd){
		perror("Fail to open");
		exit(1);
	}

	if (write(fd, p, strlen(p))==-1){
		perror("Fail to write");
		exit(1);
	}

	flag = fcntl(fd, F_GETFL, 0);
	if (-1 == flag){
		perror("Fail to fcntl");
		exit(1);
	}
	
	flag |=O_APPEND;
	if (fcntl(fd, F_SETFL, flag)==-1){
		perror("Fail to fcntl");
		exit(1);
	}

	if (write(fd, q, strlen(q))==-1){
		perror("Fail to write");
		exit(1);
	}

	close(fd);

	return 0;
}
