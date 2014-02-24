#include <stdio.h>
#include <stdlib.h>
#include "static_lib.a"

int main(void)
{
	int a, b;
	printf("Please input a and b\n");
	scanf ("%d%d",&a,&b);
	printf("the add: %d\n",add(a,b));
	printf("the sub: %d\n",sub(a,b));
	printf("the mul: %d\n",mul(a,b));
//	printf("the div: %d\n",div(a,b));

	return 0;
} 
