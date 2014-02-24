#include <stdio.h>

int main(void)
{
	int a = 10;
lable:a = 100;
	printf("%d\n", a);
	if (10 == a)
		goto lable;
	putchar(48);
//	putchar('\0x0');
	return 0;
}
