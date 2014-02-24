/* mem_distribute.c
*
*  Coded by Fanping Zeng.
*  To show the mem map on Linux system on the IA32 architecture
*
*/

#include <stdio.h>
#include <string.h>

int fun1(int a, int b)
{
	return a+b;
}

int fun2(int a, int b)
{
	return a*b;
}

int x=10, y, z=20;

int main (int argc, char *argv[])
{
    char vulnbuff[16];
    int a=5,b,c=6;

    strcpy (vulnbuff, argv[0]);
    printf ("\n%s\n", vulnbuff);
    a = fun1(10,5);
    b = fun2(10,5);
    printf("10+5=%d  10*5=%d\n\n", a, b);

    printf("address of x=%p address of y=%p address of z=%p\n\n", &x, &y, &z);
    printf("address of a=%p address of b=%p address of c=%p\n\n", &a, &b, &c);

    printf("address of argc=%p  address of argv=%p\n\n", &argc, &argv);
    printf("address of main=%p  address of vulnbuff=%p\n\n", main, &vulnbuff);
    printf("address of fun1=%p  address of fun2=%p\n\n", fun1, fun2);

    return 0;
}

