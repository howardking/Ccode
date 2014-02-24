#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE 80

ssize_t my_read(int fd, void * buffer, size_t length)
{
	ssize_t done = length;

	while (done>0){
		done = read(fd, buffer, length);
		
		if (done != length){
			if (errno==EINTR){
				done = length;
			}else{
				perror("Fail to read");
				return -1;
			}
		}else{
			break;
		}
	}
	
	return done;
}

ssize_t my_write(int fd, void * buffer, size_t length)
{
	ssize_t done = length;

	while (done>0){
		done = write(fd, buffer, length);
		
		if (done != length){
			if (errno == EINTR){
				done = length;
			}else{
				perror("Fail to write");
				return -1;
			}
		}else{
			break;
		}
	}	
	
	return done;
}

int main (int argc, char * argv[])
{
	struct sockaddr_in sin;
	struct sockaddr_in cin;
	char buf[MAX_LINE];
	int s_fd;
	int port = 8000;
	char * str = "test sting";
	int n;
	socklen_t addr_len;
	char add_p[INET_ADDRSTRLEN];

//	if (argc>1){
		//strcpy(str, argv[1]);
	if (argc != 2){
		printf("Wrong Command");
		exit(1);
	}
	str = argv[1];

	bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &sin.sin_addr);
	sin.sin_port = htons(port);

	if((s_fd = socket(AF_INET, SOCK_STREAM, 0))==-1){
		perror("Fail to create socket");
		exit(1);
	}

	if((connect (s_fd, (struct sockaddr *)&sin, sizeof(sin)))==-1){
		perror("Fail to connect");
		exit(1);
	}

	//n = my_write(s_fd, str, strlen(str)+1);
	n = write(s_fd, str, strlen(str)+1);

	if (-1 == n){
		exit(1);
	}

	//n = my_read(s_fd, buf, MAX_LINE);
	n = read(s_fd, buf, MAX_LINE);

	if (-1 == n){
		exit(1);
	}

	printf("recive from server: %s\n",buf);
	
	if(close(s_fd)==-1){
		perror("Fail to close");
		exit(1);
	}
	
	return 0;
}
