#include <stdio.h>

int main(void)
{
	int i = 2;
	
	switch (i){
		case 1: printf("%d\n", 1);
			continue;
		case 2: printf("%d\n", 2);
			continue;
		case 3: printf("%d\n", 3);
			continue;
		default:
			break;

	}
	
	return 0;
}
