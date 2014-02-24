#include <stdio.h>
#include <arpa/inet.h>

int main(void)
{
	short a = htons(0x0102);
	short * p = &a;

	if (*((char *)p)==0x01){
		printf("Big-endian\n");
	}else{
		printf("Little-endian\n");
	}

	return 0;
}
