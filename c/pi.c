#include <stdio.h>
#include <inttypes.h>
#define N 10000
#define C 20
#define R 19

int main(void)
{
	uint64_t a = 1000000, b = 0, c = N * R, d, e, f[N * R + 1], g;


	for (; b - c;)
		f[b++] = C * N;
	for (; d = 0, g = c * 2; c -= R, printf("%.6d", e + d / a), e = d % a)
		for (b = c; d += f[b] * a, f[b] = d % --g, d /= g--, --b;
		     d *= b) ;
	return 0;
}
