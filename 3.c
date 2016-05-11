#include <stdio.h>

int main(void)
{
	int n,sum = 0, max = 0;
	int t;
	scanf("%d", &t);
	scanf("%d", &n);
	int m[n];
	char mm[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m[i]);
	}
	for (int i = 0; i < t; i++)
	{
		for (int j = i; j < n - t; j = j + t)
		{
			if (m[j] < m[j + t])
				mm[j] = 0;
			else
				mm[j] = 1;
		}
	}
	/*
	for (int i = 0; i < n - t; i++)
	{
		printf("%d\n", mm[i]);
	}
	*/
	sum = 0;
	for (int j = 0; j < t; j++)
		sum += m[j];
	max = sum;
	sum = 0;
	for (int j = n - t; j < n; j++)
		sum += m[j];
	if (max < sum)
		max = sum;
	for (int i = 0; i < n - t; i++)
	{
		sum = 0;
		if ((mm[i] == 0) && (mm[i + 1] == 1))
		{
			for (int j = i + 1; j <= i + t; j++)
				sum += m[j];
			if (max < sum)
				max = sum;
		}
	}
	printf("%d\n", max);
	return 0;
}
