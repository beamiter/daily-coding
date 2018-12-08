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


struct TreeNode
{
	TreeNode* p;
	TreeNode* left;
	TreeNode* right;
	int key;
	TreeNode(int a): key(a), p(NULL), left(NULL), right(NULL) {}
};

struct BSTree
{
	TreeNode* root;
	BSTree() {
		root = NULL;
	}
};


void nil_test();

void tree_test();

#endif //PCH_H
