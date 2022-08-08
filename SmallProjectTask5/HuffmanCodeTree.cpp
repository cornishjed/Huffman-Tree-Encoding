#include "HuffmanCodeTree.h"

HuffmanCodeTree::HuffmanCodeTree()
{
}

HuffmanCodeTree::~HuffmanCodeTree()
{
	deleteTree(root);
}

void HuffmanCodeTree::buildTree(string file)
{
	searchFile(file);
	createLeafNodes();
	createPriorityQueue();

	while(!pq.empty()) {
		node* n1 = pq.top(); // The two highest priority nodes are noted before popping from pq
		pq.pop();
		node* n2 = pq.top();
		pq.pop();
		node* n3 = new node; // A new node becomes their parent node
		n3 = merge(n1, n2);
		n3->value = NULL;
		pq.push(n3);
		if (pq.size() == 1) {
			setRootNode(pq.top()); // The remaining node is the tree root node
			pq.pop();
		}
	}
	
	labelParentNodes(root);
	buildHuffmanCodes(root);
} // Breakpoint here and check 'root' variable in debugger to see the formed tree

void HuffmanCodeTree::createLeafNodes()
{
	map<char, double>::iterator it;

	for (it = chars->begin(); it != chars->end(); it++) {
		node* n = new node;
		n->value = it->first;
		n->freq = it->second;
		nodes.push_back(n);
	}
}

void HuffmanCodeTree::createPriorityQueue()
{
	vector<node*>::iterator it;

	for (it = nodes.begin(); it != nodes.end(); it++) {
		pq.push(*it);
	}

	nodes.clear(); // All leaf nodes pushed to pq so vector no longer required. Memory deallocated.
}

void HuffmanCodeTree::labelParentNodes(node* n)
{
	if (n == NULL)
		return;
	
	node* lptr = n->left;
	node* rptr = n->right;

	if(lptr != NULL)
		lptr->code = '0';
	if(rptr != NULL)
		rptr->code = '1';

	labelParentNodes(n->left);
	labelParentNodes(n->right);
}

void HuffmanCodeTree::buildHuffmanCodes(node* n)
{
	static string current = "";

	if ((n->left != nullptr) && (n->right != nullptr)) {	
		current += n->code;

		buildHuffmanCodes(n->left);	
		current.pop_back(); // drops last char when working back through the tree

		buildHuffmanCodes(n->right);
		current.pop_back();
	}
	else {
		current += n->code;
		cout << n->value << " : " << current << endl;
	}
}