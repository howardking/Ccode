#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE 80
int port = 8000;
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

void my_fun(char * p)
{
	if (NULL==p){
		return;
	}
	
	for (; *p!='\0'; p++){
		if (*p>='A' && *p<='Z'){
			*p = *p-'A'+'a';
		}
	}
}

int main(void)
{
	struct sockaddr_in sin;
	struct sockaddr_in cin;
	int l_fd;
	int c_fd;
	int s_fd;
	int r_dy;
	int client[FD_SETSIZE];
	int maxi;
	int maxfd;
	fd_set rset;
	fd_set allset;
	socklen_t addr_len;
	char buf[MAX_LINE];
	char str[INET_ADDRSTRLEN];
	int i;
	int n;
	int len;
	int opt = 1;

	bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(port);
	len = sizeof(struct sockaddr);

//	if((l_fd = socket(AF_INET, SOCK_STREAM, 0))==-1){
//		perror("Fail to create socket");
//		exit(1);
//	}

	if((l_fd = socket(AF_INET, SOCK_STREAM, 0))==-1){
		perror("Fail to create socket");
		exit(1);
	}

	setsockopt(l_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	if ((bind(l_fd, (struct sockaddr *)&sin, sizeof (sin)))==-1){
		perror("Fail to bind");
		exit(1);
	}

	if((listen(l_fd, 20))==-1){
		perror("Fail to listen");
		exit(1);
	}
	printf("Accepting connections ...\n");

	maxfd = l_fd;
	maxi = -1;
	
	for (i=0; i<FD_SETSIZE; i++){
		client[i] = -1;
	}

	FD_ZERO(&allset);
	FD_SET(l_fd,&allset);

	while(1){
		rset = allset;
		
		r_dy = select(maxfd+1, &rset, NULL, NULL, NULL);

		if (FD_ISSET(l_fd, &rset)){
			addr_len = sizeof(cin);
		}
		
		if((c_fd = accept(l_fd, (struct sockaddr *)&cin, &addr_len))==-1){
			perror("Fail to accept");
			exit(1);
		}

		for (i=0; i<FD_SETSIZE; i++){
			if (client[i]<0){
				client[i] = c_fd;
				break;
			}
		}

		if (FD_SETSIZE == n){
			printf("Too many clients\n");
			exit(1);
		}

		FD_SET(c_fd, &allset);
		
		if (c_fd>maxfd){
			maxfd = c_fd;
		}

		if (i>maxi){
			maxi = i;
		}
		
		if (--r_dy<=0){
			continue;
		}
		for (i=0; i<=maxi; i++){
			if ((s_fd=client[i])<0){
				continue;
			}
			if(FD_ISSET(s_fd, &rset)){
			//	n = my_read(s_fd, buf, MAX_LINE);
				n = read(s_fd, buf, MAX_LINE);
				if (0==n){
					printf("The other side had been closed\n");
					fflush(stdout);
					close(s_fd);

					FD_CLR(s_fd, &allset);
					client[i] = -1;
				}else{
					
					inet_ntop(AF_INET, &cin.sin_addr, str, sizeof (str));
					printf("Client's IP is %s, port is %d\n",str, ntohs(cin.sin_port));
					printf("Content is : %s\n",buf);
					my_fun(buf);
					//n = my_write(s_fd, buf, len+1);
					n = write(s_fd, buf, len+1);
					if (-1 == n){
						exit(1);
					}
				}
				if (--r_dy<=-1){
					break;
				}
			}
		}
	}

	if (close(l_fd) == -1){
		perror("Fail to close");
		exit(1);
	}
	
	return 0;
}
