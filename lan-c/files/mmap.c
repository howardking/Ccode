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
	int i;
	struct stat statbuf;

	if (stat("test.txt", &statbuf)== -1){
		perror("Fail to get stat");
		exit(1);
	}

	fd = open("test.txt",O_RDONLY);
	if (-1 == fd){
		perror("Fail to open");
		exit(1);
	}

	buf = (char *)mmap(NULL, statbuf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (MAP_FAILED == buf){
		perror("Fail to mmap");
		exit(1);
	}

	i=0;
	while(i<statbuf.st_size){
		printf("%c",buf[i]);
		i++;
	}
	printf("\n");

	if (-1==(munmap(buf, statbuf.st_size))){
		perror("Fail to munmap");
		exit(1);
	}
	
	close(fd);

	return 0;
}
