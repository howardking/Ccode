/*此程序用来观察当形参与实参类型不同时编译器是否会报错，
结果是编译器只给出了警告，而且输出的结果也会意料之外*/
#ifndef DE
#define DE
#include <stdio.h>
#include <stdlib.h>
#endif

void test(int,char);

int main(void)
{
	test(10,65);
	test("a","c");
	test('A','b');
	return 0;
}

void test(int iFirst, char cSecond )
{
	printf("iFfirst is %d\ncSecond is %c\n",iFirst,cSecond);
}
