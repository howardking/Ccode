#include <stdio.h>

int Add (int a, int b)
{
	return a+b;
}

int main(void)
{
	int array[5];
	int i = 0;
	int res;

	while (i<5){
		res = Add(i,1);
		array[i] = res;
		i++; 		
	}	

	for (i=0; i<5; i++){
		printf("array[%d]:%d\n",i+1,array[i]);
	}

	return 0;
}
