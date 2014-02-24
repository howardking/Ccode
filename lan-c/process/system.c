#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 1024

int main()
{
	int fd;
	int n;
	char buf[MAX];

	if (-1==system("ls -l > temp.txt")){
		perror("Fail to exec command");
		exit(1);
	}

	if (-1 == (fd=open("temp.txt",O_RDWR))){
		perror("Fail to open");
		exit(1);
	}

	if (-1 == (n=read(fd,buf,MAX))){
		perror("Fail to read");
		exit(1);
	}

	buf[n] = '\0';
	printf("%s\n",buf);

	return 0;
}
