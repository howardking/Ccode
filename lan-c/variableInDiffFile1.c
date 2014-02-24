/*这个文件用来定义变量，用来测试不同文件中的变量是否会有影响*/
/*经过验证外边的文件不可以直接调用本文件中的变量，除非用extern关键字说明*/
#ifndef DE
#define DE
#include <stdio.h>
#include <stdlib.h>
#endif

int a = 10;
int b = 20;
