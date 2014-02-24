#include <stdio.h>
#include <unistd.h>
#include <sys/poll.h>

#define TIMEOUT 5

int main(void)
{
	struct pollfd fds[2];
	int ret;

	/*查看stdin的输入*/
	fds[0].fd = STDIN_FILENO;
	fds[0].events = POLLIN;

	/*查看stdout是否可供写入*/
	fds[1].fd = STDOUT_FILENO;
	fds[1].events = POLLOUT;

	/*开始提供服务*/
	ret = poll(fds, 2, TIMEOUT*1000);
	if (-1==ret){
		perror("poll");
		return 1;
	}	

	if (!ret){
		printf("%d seconds elapsed.\n", TIMEOUT);
		return 0;
	}

	if (fds[0].revents & POLLIN){
		printf("stdin is readable\n");
	}

	if (fds[1].revents & POLLOUT){
		printf("stdout is writable\n");
	}

	return 0;
}
