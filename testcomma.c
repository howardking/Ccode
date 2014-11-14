#include <stdio.h>

int main(void)
{
	int a = 10;
	int b = 3;
	b = b+3, a += 4;
	printf("b = %d \na = %d\n", b, a);

	return 0;
}
