/*此程序片段用来观察一般格式输出的float数据
的小数点和小数点之后的零是否输出*/
#ifndef DE
#define DE
#include <stdio.h>
#include <stdlib.h>
#endif

int main(void)
{
	float a = 10.0f;

	printf("%f\n",a);
	printf("%.0f\n",a);
	
	return 0;
}
