/* filename: 	test_ulimit.c
 * description: this program used to show the core dump
 * author:	Howard
 * version:	v1.0
 * time:	2013-11-22
 */

#include <stdio.h>

int main(void)
{
	int *a = NULL;
	*a = 1;
	return 0;
}
