#include <stdio.h>
#include <inttypes.h>
#define N 10000
#define C 20
#define R 19

int main(void)
{
	uint64_t a = 1000000, b = 0, c = N * R, d, e = 0, f[N * R + 1], g;
	//printf("%d\n", e);

	f[0] = C * N;
	while (b != c)
		f[++b] = C * N;
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
		printf("%.6d", (int)(e + d / a));
		e = d % a;
	}
	return 0;
}
