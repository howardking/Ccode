#ifndef DD
#define DD
#include <stdio.h>
#endif

void counter (void)
{
	static int i = 0;
	i++;
	printf("%d\n",i);
}
