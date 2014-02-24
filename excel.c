#include <unistd.h>

int main(void)
{
//	execl("/bin/ls","ls",NULL);
	execl("/bin","ls",NULL);
	return 0;
}
