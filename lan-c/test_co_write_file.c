#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
	char * arr = "hello world first process!";
	int fd = open("test_file_write.txt",O_RDWR|O_APPEND);
	sleep(10);
	write(fd,arr,strlen(arr));
	sleep(20);
	write(fd,"first process end",17);
	return 0;
}
