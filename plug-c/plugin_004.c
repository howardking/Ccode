#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

int main(void)
{
	FILE * fp;
        char buf[MAX];
	int n;
	int letter = 0;
	int blank = 0;
	int number = 0;

	fp = fopen ("article.txt","r");//打开文件
	if (fp == NULL){
		perror("fail to open\n");//出错处理
		exit (0);
	}	

	while ((n = fread(buf,sizeof(char),MAX,fp))>0){//读取文件内容
		int i;
		for (i=0; i<n; i++){
			if ((buf[i]>='a' && buf[i]<='z') || \
			     (buf[i]>='A' && buf[i]<='Z')){
				letter++;
			}
			else if (buf[i]>='0' && buf[i]<='9'){
				number++;
			}
			else if (buf[i] == ' '){
				blank ++;
			}
		}
	}

	printf("字母：%d个\n数字：%d个\n空格：%d个\n",letter,number,blank);
	fclose(fp);  //关闭文件

	return 0;
}
