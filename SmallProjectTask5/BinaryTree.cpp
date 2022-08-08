#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	node* root = new node;
	root = NULL;
}

BinaryTree::~BinaryTree()
{
}

node* BinaryTree::merge(node* a, node* b)
{
	node* c = new node;
	c->left = a;
	c->right = b;
	c->freq = a->freq + b->freq;

	return c;
}

void BinaryTree::printTree(node* r)
{
	if (r != NULL) {
		printTree(r->left);
		printTree(r->right);
		cout << r->value << " ";
	}
}

void BinaryTree::setRootNode(node* n)
{
	this->root = n;
}

void BinaryTree::deleteTree(node * n)
{
	if (n == NULL)
		return;

	deleteTree(n->left);
	deleteTree(n->right);

	delete n;
}