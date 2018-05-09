#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 检查str中是否有超过基数的数字，例如二进制的数字中只能有0和1，有2、3……就是错的。
 */
int check_integrity(const char* str, int radix)
{
	const char* p;
	int max = 0, t;
	for(p = str; (*p) != '\0'; p++)
	{
		switch(*p)
		{
			case '0' ... '9':
				t = *p - 48;
				break;
			case 'a' ... 'z':
				t = *p - 87;
				break;
			case 'A' ... 'Z':
				t = *p - 55;
				break;
			default:
				return 0;
				break;
		}
		if(t > max)
			max = t;
	}
	if(max < radix)
		return 1;
	else
		return 0;
}

/*
long long int power(int x, int y)
{
	long long int m = 1;
	for (int i = 0; i < y; i++)
	{
		m *= x;
	}
	return m;
}
*/

long long int convert_string_to_number(const char* str, int radix)
{
	int i, j;
	//const char* p = str;
	long long int m = 0, n = 1;
	if(!check_integrity(str, radix))
		return -1;
	for(i = strlen(str) - 1; i >= 0; i--)
	{
		n = n * radix;
		switch(str[i])
		{
			case '0' ... '9':
				j = str[i] - 48;
				break;
			case 'a' ... 'z':
				j = str[i] - 87;
				break;
			case 'A' ... 'Z':
				j = str[i] - 55;
				break;
			default:
				return -1;
				break;
		}
		m = m + n * j;
	}
	return m;
}
int main(void)
{
	//printf("%d", check_integrity("123abc", 12));
	printf("%lld", convert_string_to_number("123", 16));
	return 0;
}
