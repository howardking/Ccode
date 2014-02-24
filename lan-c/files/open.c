#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	fd = open("test.txt", O_RDWR|O_CREAT, 0700);
	if (-1 == fd){
		perror("Fail to open");
		exit(1);
	}else{
		printf("Open OK\n");
	}

	close(fd);

	return 0;
}
