#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

int out_put (char * file_name)
{
	FILE * fp;
	char buf[MAX];
	int n;
	static int count = 0;

	fp = fopen (file_name, "r");
	
	if (NULL == fp){
		perror ("Fail to open !\n");
		return -1;
	}

	while (NULL != fgets(fp,buf,MAX)){
		n = strlen(buf)-1;
		buf[n] = '\0';
		printf("%s\n",buf);
		if (++count%5 == 0){
			printf("\n");	
		}
	}

	fclose (fp);
	
	return 0;
}


int main (void)
{
	
	int i;
	//char file_name[3][20] = {"file_one.txt","file_two.txt","file_three.txt"};
	//for (i=0; i<3; i++){
	//	out_put(file_name[i]);		
	//}
	
	out_put("file_one.txt");
	out_put("file_two.txt");
	out_put("file_three.txt");
	
	return 0;
}
