#include <stdio.h>
#include <string.h>


void AlphaSort(char * array[], int size)
{
	char * temp;
	for (int j=0; j<size; j++){
		for (int i=0; i<j; i++){
			if (strcmp(array[i], array[i+1])>0){
				strcpy(temp, array[i]);
				strcpy(array[i],array[i+1]);
				strcpy(array[i+1],temp);
			}
		}
	}
}

void Print(char * array[], int size)
{
	for (int i=0; i<size; i++){
		printf("%s\n",array[i]);
	}
}

int main(void)
{
	char * name[] = {"Zamel","Fakir","Amal","Kalam"};
	char * codes[] = {"1234","24312","98123","123244"};
	printf("排序前的顺序是：\n");
	Print(name,4);
	AlphaSort(name,4);
	printf("排序后输出结果是：\n");
	Print(name,4);
	printf ("数字排序前的输出是：\n");
	Print(codes,4);
	AlphaSort(codes,4);
	printf("数字排序后的输出是：\n");
	Print(codes,4);
	return 0;
}
