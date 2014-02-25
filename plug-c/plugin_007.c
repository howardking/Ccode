#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define MAX 64

char * itoa(int i, char *p)
{
	/*将一个无符号数转换成字符串（字符数组）*/
	char * q;
	
	if (p == NULL){
		return NULL;
	}

	p[0] = i/10000 + '0';
	i = i%10000;
	p[1] = i/1000 + '0';
	i = i%1000;
	p[2] = i/100 + '0';
	i = i%100;
	p[3] = i/10 + '0';
	i = i%10;
	p[4] = i + '0';
	p[5] = '\0';
	
	/*去掉开始中多余的0*/
	q = p;
	while (*q != '\0' && *q != '0'){
		q ++;
	}
	
	if (*q == '\0'){
		return NULL;
	}

	strcpy(p,q);

	return p;
}

int my_Print(const char * format, ...)
{
	/*自定义输出函数，这是一个可变参数的函数，属于自己写的函数*/

	va_list ap;
	char c;
	char ch;
	int i;
	char * p;
	char buf[MAX];
	int n = 0;

	va_start(ap, format);
	
	c = *format;
	while (c != '\0'){
		if (c == '%'){
			format++;

			c = *format;

			switch (c){
				case 'c':
					ch = va_arg(ap, int );
					putchar(ch);
					n ++;
					break;

				case 'd':
					i = va_arg(ap, int );
					itoa(i, buf);
					fputs(buf, stdout);
					break;
		
				case 's':
					p = va_arg(ap, char *);
					n += strlen(p);
					fputs(buf, stdout);
					break;
			}

		}
		else{
			putchar(c);
			c = *format;
		}
	}
	va_end(ap);

	return n;
}

int main(void)
{

	my_Print("the char is :%c\n, the number is :%d, the string is :%s\n",\
			'a',100,"hello world \n");
	return 0;
}






























