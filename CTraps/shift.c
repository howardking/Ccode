/*这个程序用来观察负数移位的结果*/

#ifndef DE
#define DE
#include <stdio.h>
#include <stdlib.h>
#endif

int main(void)
{
	int i = -1;
	int j = 8;
	int resultLeft = i>>8;
	int resultRight = i<<8;
	int resultReverse = j<<-65534;

	printf("resultLeft = %d\n",resultLeft);
	printf("resultRight = %d\n",resultRight);
	printf("resultReverse = %d\n",resultReverse);
	
	return 0;
}

