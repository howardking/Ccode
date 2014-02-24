#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define TIMEOUT 5     /*select的等待时间，以秒为单位*/
#define BUF_LEN 1024  /*读取缓冲区，以字节为单位*/

int main(void)
{
	struct timeval tv;
	fd_set readfds;
	int ret;

	/*等候stdin的输入数据。*/
	FD_ZERO(&readfds);
	FD_SET(STDIN_FILENO, &readfds);

	/*等候五秒钟*/
	tv.tv_sec = TIMEOUT;
	tv.tv_usec = 0;

	/*开始提供服务*/
	ret = select( STDIN_FILENO+1, &readfds, NULL, NULL, &tv);
	if (-1==ret){
		perror("select");
		return 1;
	}else if(!ret){
		printf("%d seconds elapsed.\n", TIMEOUT);
		return 0;
	}		

	/*我们的文件描述符应该可以读取了*/
	if(FD_ISSET(STDIN_FILENO, &readfds)){
		char buf[BUF_LEN+1];
		int len;
		len = read(STDIN_FILENO, buf, BUF_LEN);
		if (-1==len){
			perror("read");
			return 1;
		}

		if (len){
			buf[len] = '\0';
			printf("read: %s\n",buf);
		}
		
		return 0;
	}

	fprintf (stderr,  "This should not happen!!!\n");
	return 1;
}
