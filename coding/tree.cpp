#include "pch.h"

void nil_insert(ListNil* l, Node* x) {
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
	while (p != l->nil) {
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

void inorder_tree_walk(TreeNode* x) {
	if (x) {
		inorder_tree_walk(x->left);
		std::cout << x->key << "  ";
		inorder_tree_walk(x->right);
	}
	return;
}

TreeNode* tree_search(TreeNode* x, int key) {
	if (!x || x->key == key) {
		return x;
	}
	if (x->key < key) {
		return tree_search(x->right, key);
	}
	else {
		return tree_search(x->left, key);
	}
}

TreeNode* iterative_tree_search(TreeNode* x, int key) {
	while (x) {
		if (x->key < key) {
			x = x->right;
		}
		else if (x->key > key) {
			x = x->left;
		}
		else {
			break;
		}
	}
	return x;
}

TreeNode* tree_minimum(TreeNode* x) {
	if (!x) {
		return x;
	}
	while (x->left) {
		x = x->left;
	}
	return x;
}

TreeNode* tree_maximum(TreeNode* x) {
	if (!x) {
		return x;
	}
	while (x->right) {
		x = x->right;
	}
	return x;
}

TreeNode* tree_successor(TreeNode* x) {
	if (!x) {
		return x;
	}
	if (x->right) {
		return tree_minimum(x->right);
	}
	TreeNode* y = x->p;
	while (y && x == y->right) {
		x = y;
		y = x->p;
	}
	return y;
}

TreeNode* tree_predecessor(TreeNode* x) {
	if (!x) {
		return x;
	}
	if (x->left) {
		return tree_minimum(x->left);
	}
	TreeNode* y = x->p;
	while (y && x == y->left) {
		x = y;
		y = x->p;
	}
	return y;
}

void tree_insert(BSTree* tree, TreeNode* x) {
	TreeNode* y = tree->root;
	TreeNode* z = NULL;
	if (!y) {
		tree->root = x;
		return;
	}
	while (y) {
		z = y;
		if (y->key > x->key) {
			y = y->left;
		}
		else {
			y = y->right;
		}
	}
	x->p = z;
	if (x->key < z->key) {
		z->left = x;
	}
	else {
		z->right = x;
	}
	return;
}

void transplant(BSTree* tree, TreeNode* u, TreeNode* v) {
	if (!u->p) {
		tree->root = v;
	}
	else if (u == u->p->left) {
		u->p->left = v;
	}
	else {
		u->p->right = v;
	}
	if (!v) {
		v->p = u->p;
	}
	return;
}

void tree_delete(BSTree* tree, TreeNode* x) {
	if (x->left == NULL) {
		transplant(tree, x, x->right);
	}
	else if (x->right == NULL) {
		transplant(tree, x, x->left);
	}
	else {
		TreeNode* y = tree_minimum(x->right);
		if (!(y->p == x)) {
			transplant(tree, y, y->right);
			y->right = x->right;
			y->right->p = y;
		}
		transplant(tree, x, y);
		y->left = x->left;
		y->left->p = y;
	}
	return;
}

void tree_test() {
	BSTree* tree = new BSTree();
	TreeNode* x0 = new TreeNode(4);
	TreeNode* x1 = new TreeNode(1);
	TreeNode* x2 = new TreeNode(2);
	TreeNode* x3 = new TreeNode(3);
	TreeNode* x4 = new TreeNode(7);
	TreeNode* x5 = new TreeNode(5);
	TreeNode* x6 = new TreeNode(6);
	TreeNode* x7 = new TreeNode(4);
	tree_insert(tree, x0);
	tree_insert(tree, x1);
	tree_insert(tree, x2);
	tree_insert(tree, x3);
	tree_insert(tree, x4);
	tree_insert(tree, x5);
	tree_insert(tree, x6);
	tree_insert(tree, x7);
	inorder_tree_walk(tree->root);
	std::cout << std::endl;
	std::cout << tree->root->key << std::endl;
}