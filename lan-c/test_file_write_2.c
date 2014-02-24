#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
//#include <>

int main(void)
{
	char * arr = "second hello world!";
	int fd = open("test_file_write.txt",O_RDWR|O_APPEND);
	sleep(10);
	write(fd,arr,19);
	sleep(20);
	return 0;
}
