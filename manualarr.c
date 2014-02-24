#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int * tmp = (int *)malloc(sizeof(int)*25);
	tmp[3] = 10;
	return 0;
}
