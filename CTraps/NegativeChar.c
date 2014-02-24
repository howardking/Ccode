/*这段代码用来检测getc（）函数能否在遇到－1时成功结束，
事实证明是不行的。*/
#ifndef DE
#define DE
#include <stdio.h>
#include <stdlib.h>
#endif

int main(void)
{
	char Char = -1;

	printf("-1 = %c0\n",Char);	

	return 0;
}
