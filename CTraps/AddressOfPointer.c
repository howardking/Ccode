/*这个程序用来验证C陷阱与缺陷中的指针分配是否是对未初始化的自动分配NULL
经过验证可知在GNU Gcc下只有未初始化的全局指针可以分配为NULL，局部的不可
以*/

#ifndef DE
#define DE
#include <stdio.h>
#include <stdlib.h>
#endif

int * g_pPointer_int;
char * g_pPointer_char;

int main(void)
{
	int * p_pointer_int;
	char * p_pointer_char;

	printf("The address of uninitialiation pointer is(int) %x\n",\
	p_pointer_int);
	printf("The address of uninitialiation pointer is(char) %x\n",\
	p_pointer_char);
	printf("The address of uninitialiation pointer is(int) %x\n",\
	g_pPointer_int);
	printf("The address of uninitialiation pointer is(int) %x\n",\
	g_pPointer_char);

	return 0;
}
