#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	int fd;
	char * buf;
	char * p;
	int i;
	struct stat statbuf;

	if (stat("test.txt", &statbuf)==-1){
		perror("Fail to stat");
		exit(1);
	}

	fd = open("test.txt", O_WRONLY);
	if (-1 == fd){
		perror("Fail to open");
		exit(1);
	}

	buf = (char *)mmap(NULL, statbuf.st_size, PROT_WRITE, MAP_SHARED, fd, 0);
	if (MAP_FAILED == buf){
		perror("failed to mmap");
		exit(1);
	}

	i = 0;
	p = buf;
	while(i<3){
		sleep(10);
		printf("Hello World\n");
		memcpy(buf, "Hello World\n", 12);
		i++;
		p += 12;
		if (msync(buf, strlen(p), MS_SYNC) == -1){
			perror("Fail to msync");
			exit(1);
		}
	}
	if (munmap(buf, statbuf.st_size) == -1){
		perror("Fail to munmap");
		exit(1);
	}

	close(fd);

	return 0;
}
