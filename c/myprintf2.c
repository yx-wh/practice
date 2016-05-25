#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

void myprintf(const char *format, ...)
{
	va_list ap;
	char c;
	int mark = 0;

	va_start(ap, format);
	while (c = *format++)
	{
		if (mark)
		{
			mark = !mark;
			switch(c)
			{
				case '%':
				{
					putchar('%');
					break;
				}
				case 'c':
				{
					/*char is promoted to int when passed through ...*/
					char ch = va_arg(ap, int);
					putchar(ch);
					break;
				}
				case 's':
				{
					char *p = va_arg(ap, char *);
					fputs(p, stdout);
					break;
				}
				case 'd':
				{
					int num = va_arg(ap, int);
					int i, zeromark = 0;
					char digi;
					if (num == -2147483647-1)
					{
						putchar('-');
						putchar('2');
						putchar('1');
						putchar('4');
						putchar('7');
						putchar('4');
						putchar('8');
						putchar('3');
						putchar('6');
						putchar('4');
						putchar('8');	
						break;
					}
					if (num < 0)
					{
						num = -num;
						putchar('-');
					}
					i=1000000000;
					while(i >= 1)
					{
						digi = num / i;
						if (digi)
							zeromark = 1;
						if (zeromark)
							putchar(digi + 48);
						num = num - digi * i;
						i = i / 10;
					}
					break;
				}
				case 'o':
				{
					unsigned int num = va_arg(ap, unsigned int);
					unsigned int i, zeromark = 0;
					char digi;
					i=010000000000;
					while(i >= 01)
					{
						digi = num / i;
						if (digi)
							zeromark = 1;
						if (zeromark)
							putchar(digi + 48);
						num = num - digi * i;
						i = i / 010;
					}
					break;
				}
				case 'x':
				{
					unsigned int num = va_arg(ap, unsigned int);
					unsigned int i, zeromark = 0;
					char digi;
					i=0x10000000;
					while(i >= 0x1)
					{
						digi = num / i;
						if (digi)
							zeromark = 1;
						if (zeromark)
						{
							if (digi < 10)
								//0~9
								putchar(digi + 48);
							else
								//A~F
								putchar(digi + 55);
						}
						num = num - digi * i;
						i = i / 0x10;
					}
					break;
				}
				case 'f':
				{
					double num = va_arg(ap, double);
					double i = 1e308;
					int zeromark = 0;
					char digi;
					if (num < 0)
					{
						num = -num;
						putchar('-');
					}
					while(i >= 1.0)
					{
						digi = num / i;
						if (digi)
							zeromark = 1;
						if (zeromark)
							putchar(digi + 48);
						num = num - digi * i;
						i = i / 10.0;
					}
					putchar('.');
					for (int j = 0; j < 6; j++)
					{
						num = num * 10.0;
						digi = num;
						putchar(digi + 48);
						num = num - digi;
					}
					break;
				}
				default:
					putchar('%');
					putchar(c);
			}
		}
		else
		{
			if (c == '%')
				mark = ! mark;
			else
				putchar(c);
		}
	}
	va_end(ap);
}

int main(void)
{
	char c = '1';
	myprintf("%c\t%s  %%  %d  %o  %x %f\n", c, "hello", 12345, 12345, 0x12345ab, 12345.67891234567);
	myprintf("The value of INT_MAX is %d\n", INT_MAX);
	myprintf("The value of INT_MIN is %d\n", INT_MIN);
	myprintf("An int takes %d bytes\n", sizeof(int));
	return 0;
}
