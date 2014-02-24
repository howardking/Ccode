#include <stdio.h>

int main(void)
{

	int array[5] = {1,2,3,4,5};
	int (*p)[5];
	int *ptr;

	p = &array;
	ptr = (int *)(p+1);

	printf("The result is :%d",*(ptr-1));	

	return 0;
}
