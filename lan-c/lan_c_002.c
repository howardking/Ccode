#include <stdio.h>

int main (void)
{
	int i = 0;
	int array[5] = {1,2,3,4,5};
//	printf("%g\n",array);
	for (i=1; i<=5; i++){
		printf("%d ",*(*((&array)-i)));
	}
	return 0;
}
