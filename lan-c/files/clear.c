#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
	int fd;
	char * p = "Linux OK\n";
	
	fd = open("test.txt", O_WRONLY|O_TRUNC);

	if (-1 == fd){
		perror("Fail to open");
		exit(1);
	}

	if (write(fd, p, strlen(p)) == -1){
		perror("Fail to write");
		exit(1);
	}

	close(fd);

	return 0;
}
