#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>


#define MAX 1024

int main(void)
{
	int fd;
	off_t off;
	char buf[MAX];

	fd = open("test.txt",O_RDWR);
	if (-1 == fd){
		perror("Fail to open");
		exit(1);
	}

	printf("Before Reading\n");
	
	off = lseek(fd, 0, SEEK_CUR);
	if (-1 == off){
		perror("Fail to seek");
		exit(1);
	}	

	printf("The offset is :%d\n",off);
	
	if (read(fd, buf, 5)==-1){
		perror("Fail to read");
		exit(1);
	}

	printf("After Reading\n");
	
	off = lseek(fd, 0, SEEK_CUR);	
	if(-1==off){
		perror("Fail to lseek");
		exit(errno);
	}

	printf("The offset is :%d\n",off);
	
	close(fd);

	return 0;
}
