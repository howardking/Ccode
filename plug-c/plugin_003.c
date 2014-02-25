#include <stdio.h>

int main(void)
{
	/*练习if……else……语法*/
	int a , b;
	scanf ("%d%d",&a,&b);
	
	if (a>b){
		printf("%d大于%d\n",a,b);
	}
	else if (a<b){
		printf("%d小于%d\n",a,b);
	}
	else{
		printf("%d等于%d\n",a,b);
	}
	return 0;

}
