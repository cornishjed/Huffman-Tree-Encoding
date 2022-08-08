#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;

typedef struct BinaryTreeNode
{
	char value;
	char code;
	double freq;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	BinaryTreeNode()
	{
		freq = NULL;
		code = NULL;
		left = NULL;
		right = NULL;
	}
}node;

class BinaryTree
{
protected:
	BinaryTree();
	~BinaryTree();
	node* merge(node*, node*);
	void printTree(node* root);
	void setRootNode(node*);
	void deleteTree(node*);
	node* root;
};

#endif // !BINARYTREE_H