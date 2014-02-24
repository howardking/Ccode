/*本程序用来查看strlen（）函数在计算字符串长度的时候是不是将最后的\0
算在内，结果是strlen函数不会将\0考虑在内，所以再用malloc函数动态分配
内存时需要注意*/
#ifndef DE
#define DE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

int main(void)
{
	char * p_pointer = "hello world";
	
	printf("%d\n",strlen(p_pointer));
	return 0;
}
