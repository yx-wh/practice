#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 检查str中是否有超过基数的数字，例如二进制的数字中只能有0和1，有2、3……就是错的。
 */
int check_integrity(const char* str, long long int radix)
{
	const char* p;
	long long int max = 0, t;
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

long long int convert_string_to_number(const char* str, long long int radix)
{
	int i, j;
	long long int m = 0, n = 1;
	if(!check_integrity(str, radix))
		return -1;
	for(i = strlen(str) - 1; i >= 0; i--)
	{
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
		n = n * radix;
	}
	return m;
}

int compare_string(const char* str, long long int number, long long int radix)
{
	//这个其实和上面那个convert_string_to_number有相似之处，但不好复用。
	int i, j;
	long long int m = 0, n = 1;
	if(!check_integrity(str, radix))
		return -1;
	for(i = strlen(str) - 1; i >= 0; i--)
	{
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
		n = n * radix;
		if(m > number)
			return 1; //不用全算完就已经超过number了，返回1
	}
	if(m > number)
		return 1; 
	else
		if(m < number)
			return -1;
		else
			return 0;
}

long long int binary_search(const char* p, long long int target)
{
	long long int tmp;
	long long int high = target + 1;
	long long int low = 2;
	long long int mid = low;

	while(low <= high)
	{
		tmp = compare_string(p, target, mid);
		if(tmp > 0)
			high = mid - 1;
		else
			if(tmp < 0)
				low = mid + 1;
			else
				return mid;
		mid = (low + high) / 2;
	}
	return -1;
}

int main(void)
{
	//printf("%d", check_integrity("123abc", 12));
	//printf("%lld", convert_string_to_number("123ABC", 16));
	int tag;
	long long int radix, target, result;
	char A[11], B[11];
	scanf("%s %s %d %lld", A, B, &tag, &radix);
	//printf("%s %s", A, B);
	if(1 == tag)
	{
		target = convert_string_to_number(A, radix);
		result = binary_search(B, target);
	}
	if(2 == tag)
	{
		target = convert_string_to_number(B, radix);
		result = binary_search(A, target);
	}
	if(result == -1)
		printf("Impossible");
	else
		printf("%lld", result);
	return 0;
}
