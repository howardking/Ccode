#include <stdio.h>

int main(void)
{
	int sum = 0;
	int x = 5;
	
	do {
		sum += x;
	}while(!--x);

	printf("%d/n", sum);

	return 0;
}
