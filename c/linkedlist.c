/* linkedlist.c */
#include <stdlib.h>
//#include <stdio.h>
#include "linkedlist.h"

static link head = NULL;
static link tail = NULL;

link make_node(unsigned char item)
{
	link p = malloc(sizeof *p);
	p->item = item;
	p->next = NULL;
	return p;
}

void free_node(link p)
{
	free(p);
}

link search(unsigned char key)
{
	link p;
	for (p = head; p; p = p->next)
		if (p->item == key)
			return p;
	return NULL;
}

void insert(link p)
{
	if (head == NULL)
	{
		tail = p;
	}
	p->next = head;
	head = p;
}

/*
 * 要维护tail的话，貌似那个指向指针的指针就不好用啦
 */
void delete(link p)
{
	link pre;
	if (p == head) 
	{
		head = p->next;
		if (head == NULL)
		{
			tail = NULL;
		}
		return;
	}
	for (pre = head; pre; pre = pre->next)
		if (pre->next == p) 
		{
			pre->next = p->next;
			if (p->next == NULL)
			{
				tail = pre;
			}
			return;
		}
}

void traverse(void (*visit)(link))
{
	link p;
	for (p = head; p; p = p->next)
		visit(p);
}

void destroy(void)
{
	link q, p = head;
	head = NULL;
	while (p) 
	{
		q = p;
		p = p->next;
		free_node(q);
	}
}

void push(link p)
{
	insert(p);
}

link pop(void)
{
	if (head == NULL)
		return NULL;
	else 
	{
		link p = head;
		head = head->next;
		if (head == NULL)
			tail = NULL;
		return p;
	}
}

/*
 * address d0  b0  90  70  50  30  10
 * number  45  100 7   96  90  5   10
 *
 * 没有pnext = m;时
 *         i   k
 * address 90  d0  b0  70  50  30  10
 * number  7   45  100 96  90  5   10
 *         m           p   j
 *
 * 有了pnext = m;之后
 *         i   k
 * address 90  d0  b0  70  50  30  10
 * number  7   45  100 96  90  5   10
 *                 m   p   j
 *
 */     


void insert_sort(void)
{
	link pnext;
	link i;
	link j;
	link k;
	link m;
	for (pnext = head; pnext; m = pnext, pnext = j)
	{
		i = head;
		j = pnext->next;
		while (i != pnext)
		{
			k = i->next;
			if ((k == pnext) && (pnext->item >= i->item))
				/*说明p比之前序列中的所有数都要大，不需要变动*/
				break;
			if ((i == head) && (pnext->item <= i->item))
			{
				/*说明p比之前序列中的所有数都要小，把他改到链表的最开始处*/
				head = pnext;
				pnext->next = i;
				m->next = j;
				pnext = m;
				break;
			}
			if ((pnext->item <= k->item) && (pnext->item >= i->item))
			{
				/*改变next指向的值，使p位于i和k之间*/
				i->next = pnext;
				pnext->next = k;
				m->next = j;
				pnext = m;
				break;
			}
			i = i->next;
		}

	}
	//貌似有tail的话，应该等全部重排完了再摸到tail上面去
	for (i = head; i; i = i->next)
		if (i->next == NULL)
			tail = i;
}

/*
void print_tail(void)
{
	printf("tail:%d\n", tail->item); 
}
*/

void enqueue(link p)
{
	tail->next = p;
	p->next = NULL;
	tail = p;
	return;
}

link dequeue(void)
{
	return pop();
}


void reverse(void)
{
	link i;
	link j;
	link k;
	i = NULL;
	j = head;
	if (head == NULL)
		return;
	k = head->next;
	//if (k == NULL)
	//	return;
	//这个可以不要	
	while(k)
	{
		j->next = i;
		i = j;
		j = k;
		k = k->next;
	}
	j->next = i;

	i = head;
	head = tail;
	tail = i;
	return;
}
