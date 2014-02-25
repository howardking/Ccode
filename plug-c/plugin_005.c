#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

void Lower(char * p)
{
	int i;
	int n = strlen(p);
	for (i=0; i<n; i++){
		if (p[i]<='Z' && p[i]>='A'){
			p[i] += 32;
		}
		printf("%c",p[i]);
	}
}

int  main(void)
{
	FILE * fp;
	int n;
	char buf[MAX];

	fp = fopen ("article.txt","r");

	if (NULL == fp){
		perror ("Fail to open\n");
	}

	while ((n=fread(buf,sizeof(char),MAX,fp))>0){
		buf[n] = '\0';
		Lower(buf);
	}

	if (n<0){
		perror("fail to read the file or the file has been trivesed\n");
		exit (1);
	}

	fclose(fp);
	
	return 0;
}
