#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/*
 * 1、Josephus是公元1世纪的著名历史学家，相传在一次战役中他和另外几个人被围困在山洞里，他们宁死不屈，决定站成一圈，每次数到三个人就杀一个，直到全部死光为止。Josephus和他的一个朋友不想死，于是串通好了站在适当的位置上，最后只剩下他们俩的时候这个游戏就停止了。如果一开始的人数为N，每次数到M个人就杀一个，那么要想不死应该站在什么位置呢？这个问题比较复杂，[具体数学]的1.3节研究了Josephus问题的解，有兴趣的读者可以参考。现在我们做个比较简单的练习，用链表模拟Josephus他们玩的这个游戏，N和M作为命令行参数传入，每个人的编号依次是1~N，打印每次被杀者的编号，打印最后一个幸存者的编号。
 * https://akaedu.github.io/book/ch26s01.html
 */

void print_item(link p)
{
	printf("%d ", p->item); 
}

link next_m(link p, int m)
{
	link q=p;
	for (int i = 1; i <= m; i++)
		if (q->next != NULL)
			q = q->next;
		else
			return NULL;
	return q;
}


int main(int argc, char *argv[]) 
{
	if (argc != 3) 
	{
		printf("用法: %s <数字1> <数字2>\n", argv[0]);
		return 1;
	}

	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	link p;
	for (int i = n; i >= 1; i--)
	{
		p = make_node(i);
		insert(p);
	}
	printf("初始队列：");
	traverse(print_item);
	printf("\n");
	link q = next_m(p, m - 1);
	while (q)
	{
		while (q)
		{
			link r = next_m(q, m);
			printf("被杀掉：");
			print_item(q);
			delete(q);
			free_node(q);
			q = r;
		}
		q = next_m(p, m - 1);
		printf("幸存者：");
		traverse(print_item);
		printf("\n");
	}

	destroy();

	return 0;
}
