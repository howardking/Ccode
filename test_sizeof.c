#include <stdio.h>

void test_arr_int(void)
{
	int a[100];
	int *p = a;
	
	printf("int a[100];\n");
	printf("int *p = a;\n");
	printf("sizeof(a) = :%d\n", sizeof(a));
	printf("sizeof(a[100]) = :%d\n", sizeof(a[100]));
	printf("sizeof(&a) = :%d\n", sizeof(&a));
	printf("sizeof(&a[0]) = :%d\n", sizeof(&a[0]));
//	printf("sizeof(int) *p = :%d\n", sizeof (int)*p);
	
}

void test_arr_char(void)
{
	char *a = "hello, world";
	
	printf("char *a = \"hello, world\"\n");
	printf("sizeof a = :%d\n", sizeof a);
	printf("sizeof *a = :%d\n", sizeof *a);
	printf("sizeof &a = :%d\n", sizeof &a);
}
int main(void)
{
	test_arr_int();
	test_arr_char();	
	return 0; 
}
