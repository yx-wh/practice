/* linkedlist.h */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node *link;
struct node {
	int item;
	link next;
};

link make_node(int item);
void free_node(link p);
link search(int key);
void insert(link p);
void delete(link p);
void traverse(void (*visit)(link));
void destroy(void);
void push(link p);
link pop(void);

void insert_sort(void);
//void print_tail(void);
void enqueue(link p);
link dequeue(void);
void reverse(void);
#endif
