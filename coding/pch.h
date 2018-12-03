

#ifndef PCH_H
#define PCH_H

struct Node
{
	int key;
	Node* p;
	Node* lc;
	Node* rc;
};

void generate_tree();

#endif //PCH_H
