#include <stdio.h>
#include <inttypes.h>
#define N 10000
#define C 20
#define R 19
uint64_t a = 1000000, b = 0, c = N * R, d, e, f[N * R + 1], g;

int main(void)
{


	for (; b - c;)
		f[b++] = C * N;
	//for (; d = 0, g = c * 2; c -= R, printf("%.6d", e + d / a), e = d % a)
	//	for (b = c; d += f[b] * a, f[b] = d % --g, d /= g--, --b;
	//	     d *= b) ;
	while (c != 0)
	{
		d = 0;
		g = c * 2;
		b = c;
		while (1)
		{
			d = d + f[b] * a;
			g--;
			f[b] = d % g;
			d = d / g;
			g--;
			b--;
			if (b == 0)
				break;
			d = d * b;
		}
		c = c - R;
		printf("%.6d", e + d / a);
		e = d % a;
	}
	return 0;
}
