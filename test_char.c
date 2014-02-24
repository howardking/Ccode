#include <string.h>

int main(void)
{
	char a [300];
	int i;
	int j;

	for (i=0; i<300; i++){
		a[i] = -1 -i;
	}
	
	j = strlen(a);
	printf("%d\n", j);

	for (i=0; i<j; i++){
		printf("%10x", a[i]);
		if (0==(i+1)%5){
			printf("\n");
		}
	}

	return 0;
}
