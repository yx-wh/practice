#include <stdio.h>

int main(void)
{
	int n,sum = 0;
	scanf("%d", &n);
	int t,s,p;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &t);
		scanf("%d", &s);
		scanf("%d", &p);
		tmp = t - s;
		if (tmp > 0)
		{
			sum += tmp * p;
		}
	}
	printf("%d", sum);
	return 0;
}
