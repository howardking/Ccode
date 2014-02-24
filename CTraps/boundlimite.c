/*这个程序用来观察当数组复制越界的时候会有什么样的结果*/
#ifndef DE
#define DE
#include <stdio.h>
#include <stdlib.h>
#endif

int main(void)
{
	int i = 0;
	int arr[10];

	for (i=1; i<=10; i++)
	{
		arr[i] = 0;
	}
/*	for (i=0; i<=10; i++)
	{
		printf("%d\n",arr[i]);
	}

	return 0;
*/
}
