/*这个程序的目的在于看程序的结果输入的是0 1 2 3 4*/
#ifndef DE
#define DE
#include <stdio.h>
#include <stdlib.h>
#endif

int main(void)
{
	int i;
	char c;
	
	for (i=0; i<5; i++)
	{
		scanf("%d",&c);
		printf("%d ",c);
	}
	printf("\n");

	return 0;
}
