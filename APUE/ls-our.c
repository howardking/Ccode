#include "apue.h"
#include <dirent.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	DIR  *dp;
	struct dirent *dirp;
	
	if (2 != argc){
		//printf("usage: ls directory_name\n");
		perror("usage: ls directory_name\n");
		exit(1);
	}

	if (NULL == (dp = opendir(argv[1]))){
		printf("can't open %s\n", argv[1]);
		perror("Can't");
		exit(2);
	}

	while (NULL != (dirp = readdir(dp))){
		printf("%s\n", dirp->d_name);
	}

	closedir(dp);
	exit(0);
}
