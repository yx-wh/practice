#include <stdio.h>
#include <string.h>
void *memcpy1(void *dest, const void *src, size_t n)
{
	char *d = dest;
	const char *s = src;
	int *di;
	const int *si;
	int r = n % 4;
	while (r--)
		*d++ = *s++;
	di = (int *)d;
	printf("d:%x\n", d);
	printf("di:%x\n", di);
	si = (const int *)s;
	printf("s:%x\n", s);
	printf("si:%x\n", si);
	n /= 4;
	while (n--)
		*di++ = *si++;

	return dest;
}


int main(void)
{
	char buf[20] = "hello world\n";
	char buf1[20] = " ";
	memcpy1(buf1 + 1, buf, 13);
	printf("%s", buf);
	printf("%s", buf1);
	memcpy1(buf1 + 2, buf, 13);
	printf("%s", buf);
	printf("%s", buf1);
	memcpy1(buf1 + 3, buf, 13);
	printf("%s", buf);
	printf("%s", buf1);
	memcpy1(buf1 + 4, buf, 13);
	printf("%s", buf);
	printf("%s", buf1);
	//memcpy(buf1 + 1, buf, 13);
	//printf("%s", buf);
	//printf("%s", buf1);
	return 0;
}
