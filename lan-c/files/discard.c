#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main(void)
{
	int fd;
	char * buf;
	struct stat statbuf;

	if (stat("test.txt", &statbuf)== -1){
		perror("Fail to get stat");
		exit(1);
	}

	fd = open("test.txt",O_RDWR);
	if (-1 == fd){
		perror("Fail to open");
		exit(1);
	}

	buf = (char *)mmap(NULL, statbuf.st_size, PROT_WRITE, MAP_SHARED, fd, 0);
	if (MAP_FAILED == buf){
		perror("Fail to mmap");
		exit(1);
	}

	strcpy(buf, "hello world\n");

	if (-1==(munmap(buf, statbuf.st_size))){
		perror("Fail to munmap");
		exit(1);
	}
	
	close(fd);

	return 0;
}
