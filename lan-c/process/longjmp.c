#include <stdio.h>
#include <setjmp.h>

jmp_buf env;

void f (void)
{
	longjmp(env, 10);
}

int main(void)
{
	int val;

	val = setjmp(env);
	if (0 != val){
		printf("after longjmp, the value is %d\n",val);
	}
	else {
		printf("ready to jmp\n");
	}

	f();
	return 0;
}
