#include <stdio.h>

int main (void)
{
	const int a = 10;
	int const b = 20;
	int *p = &a;
	int *q = &b;
	*p = 1000;
	*q = 2000;
	printf("%d\n",*p);
	printf("%d\n",*q);
	return 0;
}
