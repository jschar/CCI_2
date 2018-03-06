/*

	4.6: Successor: Write an algorithm to find the "next" node (i.e., in-order successor) of a given
node in a binary search tree. You may assume that each node has a link to its parent.

*/

#include <iostream>

using namespace std;

class Node{
private:

public:

	int *data;
	Node* lChild;
	Node* rChild;
	Node* parent;

	Node():data(nullptr), lChild(nullptr), rChild(nullptr), parent(nullptr){ }
	Node(int inData): data(new int(inData)), lChild(nullptr), rChild(nullptr), parent(nullptr){ }

};

Node* inOrder(Node* root, int mark){
	if(root == nullptr){ return nullptr; }
	
}



int main(void){

	Node *root = new Node(20);

	//20
	root->lChild = new Node(10);
	root->rChild = new Node(30);

	// 10
	root->lChild->lChild = new Node(5);
	root->lChild->rChild = new Node(15);

	//30
	root->rChild->lChild = new Node(25);
	root->rChild->rChild = new Node(35);
	

	return 0;
}