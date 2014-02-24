#ifndef DE
#define DE
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#endif

int main(void)
{
	int fd;
	errno = 0;

	fd = open("/home/shuihua/nothing.txt",O_RDWR);

	if (errno ==0){
		printf("Successful\n");
	}
	else{
		int err = errno;
		perror("Fail to open");
		printf("Fail to open, the reason is:%s\n",strerror(err));
		exit(1);
	}

	close(fd);
	return 0;
}
