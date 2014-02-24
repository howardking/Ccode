#ifndef DE
#define DE
#include <stdio.h>
#include <stdlib.h>
#endif

int main(void)
{
	int i = 0;
	int n = 5;
	int arrA[20];
	int arrB[20];

	for (i=0; i<20; i++)
	{
		arrA[i] = i;
	}
	i = 0;
	while ( i<n)
	{
		arrB[i] = arrA[i++];
	}

	i = 0;
	while (i<n)
	{
		printf("%d\n",arrB[i++]);
	}

	return 0;
}
