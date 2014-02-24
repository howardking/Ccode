/* Filename:   contains3.c
 * Description:用来计算从1～1000的数中有多少个含有3的数。
 * Author:     Howard
 * Date  :     2013-12-05
 * Version:    v1.1
 */

#include <stdio.h>

void solve()
{
	int i = 0;             /*1=<i<=1000*/
	int j = 0;             /*控制输出个数为10时换行*/
	int count = 0;         /*计数符合要求的数的个数*/
	int one, two, three;   /*one(百位) two(十位) three(个位)*/

	for (i=1; i<=1000; i++){
		one   = i/100;
		two   = i%100/10;
		three = i%10;
		if (3==one || 3==two || 3==three){
			j ++;
			count ++;
			printf("%4d", i);	
		}
		if (10==j){
			j = 0;
			printf("\n");
		}
	}
	printf("\n总数为：%4d\n", count);	
}

int main(int argc, char *argv[])
{
	solve();
	return 0;
}
