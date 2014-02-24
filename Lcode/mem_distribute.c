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
    char vulnbuff[64];
    
    int a=5,b,c=6;

//    strcpy (vulnbuff, argv[0]);
    printf ("\n%s : To show the mem map(Coded by Fanping Zeng).\n\n", vulnbuff);
//    a = fun1(10,5);
//    b = fun2(10,5);
/*    printf("10+5=%d  10*5=%d\n\n", a, b); */
    printf("(.text)address of fun1=%p  fun2=%p  main=%p\n", fun1, fun2, main);
    printf("(.data inited Global variable)address of x(inited)=%p  z(inited)=%p\n", &x, &z);
    printf("(.bss uninited Global variable)address of y=%p\n\n", &y);

    printf("(stack)address of argc=%p  argv=%p  argv[0]=%p\n", &argc, &argv, argv[0]);
	printf("(Local  variable)address of  address of vulnbuff[64]=%p\n", &vulnbuff);
    printf("(Local  variable)address of a(inited)=%p  b=%p  c(inited)=%p\n\n", &a, &b, &c);



    return 0;
}
