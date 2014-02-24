#include <stdio.h>
#include <stdlib.h>

void func(void)
{
	int *pp = malloc(sizeof(int)*10);
	pp[10] = 100;
}

int main(void)
{	
	func();
	return 0;
}
