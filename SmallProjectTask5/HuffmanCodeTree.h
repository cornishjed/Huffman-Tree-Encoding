#ifndef HUFFMANCODETREE_H
#define HUFFMANCODETREE_H

#include <queue>
#include "SymbolFreq.h"
#include "BinaryTree.h"
#include "Compare.h"
#include <string>
using namespace std;

class HuffmanCodeTree : public SymbolFreq, BinaryTree
{
public:
	HuffmanCodeTree();
	~HuffmanCodeTree();
	void buildTree(string);
	void createLeafNodes();
	void createPriorityQueue();
	void labelParentNodes(node*);
	void buildHuffmanCodes(node*);
private:
	vector <node*> nodes;
	priority_queue<node*, vector<node*>, Compare> pq;
};

#endif // !HUFFMANCODETREE_H