/* linkedlist.c */
#include <stdlib.h>
#include "linkedlist.h"

static link head = NULL;

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
	p->next = head;
	head = p;
}

void delete(link p)
{
	link *pnext;
	for (pnext = &head; *pnext; pnext = &(*pnext)->next)
		if (*pnext == p) 
		{
			*pnext = p->next;
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
}
