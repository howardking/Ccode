/**
 * filename:    xorandop.c
 * description: to test the result of X ^ 0 == X & -1
 * date:        2015-4-10
 * author:      HowardKing
 * version:     v0.1
 */

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	unsigned int x = 12345678;
	printf("%x\n", x^0);
	printf("%x\n", x&(-1));
	if((x^0) == (x&-1)){
		printf("equals\n");
	}else{
		printf("not equal\n");
	}
	return 0;
}
