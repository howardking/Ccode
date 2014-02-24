#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int fd;
	fd = open("no_such_file",O_RDONLY);
	if(-1 == fd){
		perror("Fail to open");
	}else{
		close(fd);
	}

	fd = open("denied",O_WRONLY);
	if (-1 == fd){
		perror("Fail to open");
	}else{
		close(fd);
	}
	return 0;
}
