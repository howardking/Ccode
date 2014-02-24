#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int r = 0;
	int h = 4;
	int l = 1;

	r = h << 4 + l;	
	printf("r = h << 4 + l  %d\n",r);
	r = (h << 4) + l;
	printf("r = (h << 4) + l  %d\n",r);
	r = h << 4 | l;	
	printf("r = h << 4 | l  %d\n",r);

	return 0;
}
