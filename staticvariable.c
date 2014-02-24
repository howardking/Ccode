/* FileName:    staticvariable.c
 * Description: 用来测试静态变量的输出结果。
 * Author:      Howard
 * Date:        2013-12-05
 * Version:     v1.0
 */

#include <stdio.h>

static int j = 0;

int func1(void)
{
	static int i = 0;
	i ++;
	return i;
}

void func2(void)
{
	j = 0;
	j ++;
} 

int main(void)
{
	int k;
	int i;
	
	for (k=0; k<10; k++){
		i = func1();
		func2();
	}
	k = 100;
	printf("i = :%d\n", i);
	printf("j = :%d\n", j);
	
	return 0;
}
