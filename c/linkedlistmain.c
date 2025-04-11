/* main.c */
#include <stdio.h>
#include "linkedlist.h"

void print_item(link p)
{
	printf("%d ", p->item); 
}

int main(void)
{
	link p = make_node(10);
	insert(p);
	p = make_node(5);
	insert(p);
	p = make_node(90);
	insert(p);
	p = make_node(96);
	insert(p);
	p = make_node(7);
	insert(p);
	p = make_node(100);
	insert(p);
	p = make_node(45);
	insert(p);
	//p = search(5);
	//delete(p);
	//free_node(p);
	traverse(print_item);
	printf("\n");
	insert_sort();
	traverse(print_item);
	printf("\n");
	
	p = make_node(38);
	enqueue(p);
	p = dequeue();
	free_node(p);
	traverse(print_item);
	printf("\n");
	insert_sort();
	traverse(print_item);
	printf("\n");
	reverse();
	traverse(print_item);
	printf("\n");

	destroy();

	p = make_node(7);
	insert(p);
	traverse(print_item);
	printf("\n");
	reverse();
	traverse(print_item);
	printf("\n");
	p = make_node(100);
	insert(p);
	traverse(print_item);
	printf("\n");
	reverse();
	traverse(print_item);
	printf("\n");

	destroy();
	/*
	p = make_node(100);
	push(p);
	p = make_node(200);
	push(p);
	p = make_node(250);
	push(p);
	while (p = pop()) {
		print_item(p);
		free_node(p);
	}
	*/

	return 0;
}

