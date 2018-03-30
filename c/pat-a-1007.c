//我的做法是错误的，这个题应该用穷举或者动态规划
//https://www.patest.cn/contests/pat-a-practise/1007
//10
//-10 1 2 3 4 -5 -23 3 7 -21
//出来的结果就有问题
#include <stdio.h>

int main(void)
{
	int count;
	scanf("%d", &count);
	int a[count];
	int b[count];
	int c[count];
	int i,j,sum;
	for (int k = 0; k < count; k++)
	{
		scanf("%d", &a[k]);
	}
	for (int k = 0; k <= count; k++)
	{
		if (k == count)
		{
			//printf("%d %d %d", 0, a[0], a[count - 1]);
			printf("0 0 0");
			return 0;
		}
		if (a[k] > 0)
			break;
	}
	b[0] = a[0];
	for (int k = 1; k < count; k++)
	{
		b[k] = a[k] + b[k - 1];
	}
	j = 0;
	for (int k = 1; k < count; k++)
	{
		if (b[k] > b[j])
			j = k;
	}	
	c[count - 1] = a[count - 1];
	for (int k = count - 2; k >= 0; k--)
	{
		c[k] = a[k] + c[k + 1];
		//printf("%d ", c[k]);
	}
	i = count - 1;
	//printf("%d ", i);
	for (int k = count - 2; k >= 0; k--)
	{
		if (c[k] > c[i])
			i = k;
	}
	sum = 0;
	for (int k = i; k <= j; k++)
	{
		sum += a[k];
	}
	printf("%d %d %d", sum, a[i], a[j]);
	return 0;
}
