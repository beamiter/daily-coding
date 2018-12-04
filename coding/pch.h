#ifndef PCH_H
#define PCH_H

#include <iostream>

struct Node
{
	int key;
	Node* prev;
	Node* next;
	Node(int x): prev(NULL), next(NULL), key(x) {}
	Node(): key(0) {}
};

struct List
{
	Node* head;
	List():head(NULL) {}
};

struct ListNil
{
	Node* nil;
	ListNil(){
		nil = new Node();
		nil->next = nil;
		nil->prev = nil;
	}
};

void nil_insert(ListNil* l, Node* x);
void nil_test();

#endif //PCH_H
