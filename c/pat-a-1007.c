//我的做法是错误的，这个题应该用穷举或者动态规划
//https://www.patest.cn/contests/pat-a-practise/1007
//10
//-10 1 2 3 4 -5 -23 3 7 -21
//出来的结果就有问题

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int k;
	int *data;
	int i;

	int start, end, sum, temp, tempi, tempj;

	while (scanf("%d", &k) != EOF) {
		data = (int *)malloc(k * sizeof(int));
		for (i = 0; i < k; i++) {
			scanf("%d", &data[i]);
		}
		sum = 0;
		start = 0;
		end = k - 1;
		temp = 0;
		tempi = 0;
		tempj = 0;
		for (i = 0; i < k; i++) {
			if (temp >= 0) {
				temp += data[i];
				tempj = i;
			} else {
				temp = data[i];
				tempi = i;
				tempj = i;
			}

			/*为什么这里是temp大于等于0就继续加，而小于0就新开一块呢，
			 *可以假设有这样的情况，A、B都是一串数字，x是个负数。
			 *  [A]x[B]
			 *设A=m，若A+x<0，那么x<-m。要想使A+x+B大于m，那么必然B>m而且B的绝对值要比x大。
			 *Maximum Subsequence Sum就该是B了。所以这个时候要重新算temp。
			 *而且注意和相等的时候i和j的值要最小。
			 *10
			 *-10 1 2 3 4 -5 -23 3 7 -21
			 *(gdb) i locals 
			 *k = 10
			 *data = 0x555555756420
			 *i = 4
			 *start = 1
			 *end = 4
			 *sum = 10
			 *temp = 10
			 *tempi = 1
			 *tempj = 4
			 *(gdb) i locals 
			 *k = 10
			 *data = 0x555555756420
			 *i = 5
			 *start = 1
			 *end = 4
			 *sum = 10
			 *temp = 5
			 *tempi = 1
			 *tempj = 5
			 *(gdb) i locals 
			 *k = 10
			 *data = 0x555555756420
			 *i = 6
			 *start = 1
			 *end = 4
			 *sum = 10
			 *temp = -18
			 *tempi = 1
			 *tempj = 6
			 *(gdb) i locals 
			 *k = 10
			 *data = 0x555555756420
			 *i = 9
			 *start = 1
			 *end = 4
			 *sum = 10
			 *temp = -11
			 *tempi = 7
			 *tempj = 9
			 *(gdb) i locals 
			 *k = 10
			 *data = 0x555555756420
			 *i = 10
			 *start = 1
			 *end = 4
			 *sum = 10
			 *temp = -11
			 *tempi = 7
			 *tempj = 9
			 *
			 */
			if (temp > sum || (temp == 0 && end == k - 1))	//temp确实比sum大, 或者, sum依然是初始状态(end == k-1即表示)而且temp==0, 需要替换
			{
				sum = temp;
				start = tempi;
				end = tempj;
			}
		}
		printf("%d %d %d\n", sum, data[start], data[end]);
	}
	return 0;
}
