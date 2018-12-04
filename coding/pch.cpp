
#include "pch.h"

void nil_insert(ListNil* l, Node* x) {
	if (l->nil->next) {

	}
	if (l->nil->prev) {

	}
	x->next = l->nil->next;
	l->nil->next->prev = x;
	l->nil->next = x;
	x->prev = l->nil;
	
	//x->next = l->nil->next;
	//l->nil->next->prev = x;
	//l->nil->next = x;
	//x->prev = l->nil;
	return;
}

void nil_delete(ListNil* l, Node* x) {
	x->prev->next = x->next;
	x->next->prev = x->prev;
	delete x;
}

void nil_delete(Node* x) {
	x->prev->next = x->next;
	x->next->prev = x->prev;
	delete x;
}

void nil_print(ListNil* l) {
	Node* p = l->nil->next;
	while (p != l->nil) {
		std::cout << p->key << ",  ";
		p = p->next;
	}
	std::cout << std::endl;
}

Node* nil_search(ListNil* l, int k) {
	Node* p = l->nil->next;
	while (p != l->nil){
		if (p->key == k) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void nil_test() {
	ListNil* l = new ListNil();
	Node* x = new Node(1);
	nil_insert(l, x);
	Node* x2 = new Node(2);
	nil_insert(l, x2);
	Node* x3 = new Node(3);
	nil_insert(l, x3);
	Node* x4 = new Node(5);
	nil_insert(l, x4);
	nil_print(l);
	nil_delete(l, x);
	nil_print(l);
	nil_delete(x4);
	nil_print(l);

	auto a = nil_search(l, 2);
	std::cout << "a: " << a->key << std::endl;
}
