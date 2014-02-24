#ifndef DE
#define DE
#include <stdio.h>
#include <stdlib.h>
#endif

struct {
	unsigned int is_keyword:1;
	unsigned int is_extern:1;
	unsigned int is_static:1;
	unsigned int is_static1:1;
	unsigned int is_static2:1;
	unsigned int is_static3:1;
	unsigned int is_static4:1;
	unsigned int is_static5:1;
	unsigned int is_static6:1;
	unsigned int is_static7:1;
	unsigned int is_static8:1;
	unsigned int is_static9:1;
	unsigned int is_static10:1;
	unsigned int is_static11:1;
	unsigned int is_static12:1;
	unsigned int is_static13:1;
	unsigned int is_static14:1;
	unsigned int is_static15:1;
	unsigned int is_static16:1;
	unsigned int is_static17:1;
	unsigned int is_static18:1;
	unsigned int is_static19:1;
	unsigned int is_static20:1;
	unsigned int is_static21:1;
	unsigned int is_static22:1;
	unsigned int is_static23:1;
	unsigned int is_static24:1;
	unsigned int is_static25:1;
	unsigned int is_static26:1;
	unsigned int is_static27:1;
	unsigned int is_static28:1;
	unsigned int is_static29:1;
}flag;

int main(void)
{
	flag.is_keyword = 1;
	flag.is_extern = 1;
	flag.is_static = 0;

	printf("flag.is_keyword = %d\n",flag.is_keyword);
	printf("flag.is_extern = %d\n",flag.is_extern);
	printf("flag.is_static = %d\n",flag.is_static);
	printf("sizeof flag is  = %d\n",sizeof flag);

	return 0;
}
