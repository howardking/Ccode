#include <locale.h>
#include <stdio.h>

#define XXX 1u

int main(void)
{
	setlocale(LC_ALL,"");
	float i = 100.123456;
//	printf("%20,*f\n",'*',i);
	printf("%'d\n",2000000);
	printf("%5,#d\n",100);
	return 0;
}
