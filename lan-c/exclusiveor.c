#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int first;
	int second;
	int third;
	int result;
	
	second = third = 0xff;
	first = 0x01;
	result = first & second ^ third;
	printf("result = %x\n",result);	
	result = first | second ^ third;
	printf("result = %x\n",result);	

	return 0;
}
