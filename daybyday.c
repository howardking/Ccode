#include <stdio.h>

void calc(float base)
{
	
	int i = 365;
	float sum = 1;
	while (i--){
		sum *= base;
	}
	printf("%f^%d = %f\n",base , 365, sum);
}

int main(void)
{
	
	printf("  / ");calc(0.99);
	printf("  |\n");
	printf("  |\n");
	printf(" /\n");
	printf("*\n");
	printf("  \\\n");
	printf("  |\n");
	printf("  |\n");
	printf("  \\");calc(1.01);
	printf("\n");
	printf("  /");calc(0.98);
	printf("  |\n");
	printf("  |\n");
	printf(" /\n");
	printf("*\n");
	printf(" \\\n");
	printf(" |\n");
	printf(" |\n");
	printf(" \\");calc(1.02);

	return 0;	
}
