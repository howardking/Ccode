#ifndef DE
#define DE
#include <stdio.h>
#include <stdlib.h>
#endif

int main(void)
{
	char arr[100] = "hello";
	
	printf("sizeof(char) = %d\n",sizeof(char));
	printf("sizeof(short) = %d\n",sizeof(short));
	printf("sizeof(int) = %d\n",sizeof(int));
	printf("sizeof(long) = %d\n",sizeof(long));
	printf("sizeof(long long) = %d\n",sizeof(long long));
	printf("sizeof(float) = %d\n",sizeof(float));
	printf("sizeof(double) = %d\n",sizeof(double));
	printf("sizeof(arr) = %d\n",sizeof(arr));
	printf("sizeof(&arr) = %d\n",sizeof(&arr));
	
	return 0;
}
