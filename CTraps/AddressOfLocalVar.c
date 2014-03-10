#include <stdio.h>

int main(void)
{
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	int arr[10];

	printf("Address of a: %p\n", &a);
	printf("Address of b: %p\n", &b);
	printf("Address of c: %p\n", &c);
	printf("Address of d: %p\n", &d);
	printf("Address of e: %p\n", &e);
	printf("Address of f: %p\n", &f);
	printf("Address of arr[0]: %p\n", &arr[0]);
	printf("Address of arr[9]: %p\n", &arr[9]);
	printf("Address of arr[10]: %p\n", &arr[10]);
	
	return 0;
}
