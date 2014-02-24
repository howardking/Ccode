#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>

int convert(void)
{
	FILE *fp;
	struct stat statbuf;   //文件状态的存储结构
	char * p, * q;
	int n;
	int res = -1;           //函数的返回值

	
	if (stat("test.txt", &statbuf) == -1){/*得到文件的状态，得到文件的大小*/
		perror("fail to get stat\n");
		return res;
	}

	fp = fopen ("test.txt","rb");	
	if (fp == NULL){
		perror ("fail to open\n");
		return res;
	}
	/*动态分配保存文件的缓冲区，如果失败需要关闭上一个fopen打来的文件，跳转到err1*/

	p = (char *)malloc(sizeof(char)*(statbuf.st_size + 1));
	if (p == NULL){
		perror("fail to malloc\n");
		goto err1;
	}

	/*读取文件内容，如果失败，则需要释放动态分配的缓冲区，并且关闭打开的文件并跳转到err2*/

	n = fread (p, sizeof(char), statbuf.st_size, fp);
	if (n == -1){
		perror("fail to read\n");
		goto err2;
	}

	*(p + n) = '\0';      //设置结束标志
	
	q = p;
	while (*q != '\0'){

		if ('a'<*q && 'z'>*q){
			*q += 32;
			printf("%c\n",*q);
			q++;
		}
	}

	res = 0;//执行到此一切正常
err2:
	free(p);
err1:
	fclose(fp);
	
}



int main(void)
{
	if (convert() == -1){
		printf ("fail to convert\n");
	}	
	return 0;
}	
