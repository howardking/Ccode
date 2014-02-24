#include <stdio.h>

int main(int argc, char *＊ argv[])
{
	if(3 != argc){
		printf("Usage:hello word1 word2 \n");
	}
	
	printf("word1 is %s, word2 is %s\n",argv[0],argv[1]);
	printstar();
	
	return 0;
}
