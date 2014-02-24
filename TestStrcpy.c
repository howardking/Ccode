/* filename:    TestStrcpy.c
 * description: Used to test the function "Strcpy"
 * author:      Howard
 * date:        2013-11-22
 * version:     v1.0
 */

#ifndef DE
#define DE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

int main(void)
{
	char * p;
	char arr[6] = "hello";
	
	p = arr;
	strcpy(p,arr);
	
	printf("%s\n",arr);
	printf("%s\n",p);
	

	return 0;
}
