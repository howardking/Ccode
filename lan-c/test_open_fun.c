#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	char arr[10];
	int des;
	des = open("main.c",O_RDONLY);
	printf("when the length is -1,the result is %d\n",read(des,arr,-10));
	return 0;
}
