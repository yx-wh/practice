#include <stdio.h>

int count_change(int n)
{
	int A[n+1];
	int kind[5] = {1, 5, 10, 25, 50};
	A[0] = 1;
	for (int j = 1; j <= n; j++)
		A[j] = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = kind[i]; j <= n; j++)
		{
			A[j] += A[j - kind[i]];
		}
	}
	return A[n];
}

int main(void)
{
	printf("%d", count_change(100));
	return 0;
}

//https://www.zhihu.com/question/22219036
//SICP换零钱迭代方法实现，是如何写的？
