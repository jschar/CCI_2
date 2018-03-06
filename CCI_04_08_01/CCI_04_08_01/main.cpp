/*

	4.8: First Common Ancestor: Design an algoritm and write code to find the first common
ancestor of two node in a binary tree. Avoid storing additional nodes in a data structure.
NOTE: This is not necessarily a binary search treee.

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

class Node{
private:

public:
	int *data;
	Node *lChild;
	Node *rChild;
	Node *parent;

	Node(): data(nullptr), lChild(nullptr), rChild(nullptr), parent(nullptr) { }
	Node(int inData): data(new int(inData)), lChild(nullptr), rChild(nullptr), parent(nullptr) { }

};

/////
// Sol 1
//////
Node* goUpBy(Node*,int);
int depth(Node*);

Node* commonAncestor(Node* p, Node* q){

	int delta = depth(p) - depth(q);
	Node* first = delta > 0 ? q : p;
	Node* second = delta > 0 ? p : q;
	second = goUpBy(second, abs(delta));

	while(first != second && first != nullptr && second != nullptr){
		first = first->parent;
		second = second->parent;
	}
	return first == nullptr || second == nullptr ? nullptr:first;
}

Node* goUpBy(Node* node, int delta){
	while(delta > 0 && node != nullptr){
		node = node->parent;
		delta--;
	}
	return node;
}

int depth(Node* node){
	int depth = 0;
	while(node != nullptr){
		node = node->parent;
		depth++;
	}
	return depth;
}
///// Sol 1

//////
// Sol 2
///////

bool covers(Node*, Node*);
Node* getSibling(Node*);

Node* commonAn(Node* root, Node* p, Node* q){

	if(!covers(root, p) || !covers(root,q)){	
		return nullptr;
	} else if( covers(p,q) ){
		return p;
	} else if( covers(q,p) ){
		return q;
	}

	Node* sibling = getSibling(p);
	Node* parent = p->parent;
	while(!covers(sibling, q)){
		sibling = getSibling(parent);
		parent = parent->parent;
	}
	return parent;
}

bool covers(Node* root, Node* p){
	if(root == nullptr){ return false; }
	if(root == p){ return true; }
	return covers(root->lChild,p) || covers(root->rChild,p);
}

Node* getSibling(Node* node){
	if(node == nullptr || node->parent == nullptr){ return nullptr;	}
	Node* parent = node->parent;
	return (parent->lChild == node) ? parent->rChild : parent->lChild;
}

// end Sol 2

//////
// Sol 3
/////

Node* CAHelper(Node*, Node*, Node*);

Node* CA(Node* root, Node* p, Node* q){
	if(!covers(root,p)||!covers(root,q)){
		return nullptr;
	}
	return CAHelper(root,p,q);
}

Node* CAHelper(Node* root, Node* p, Node* q){
	if(root==nullptr || root == p || root == q){
		return root;
	}

	bool pIsOnLeft = covers(root->lChild, p);
	bool qIsOnLeft = covers(root->lChild, q);
	if(pIsOnLeft != qIsOnLeft){
		return root;
	}

	Node* childSide = pIsOnLeft ? root->lChild : root->rChild;
	return CAHelper(childSide, p, q);
}

int main(void){

	Node* root = new Node(20);
////////
	root->lChild = new Node(10);
	root->lChild->parent = root;

	root->rChild = new Node(30);
	root->rChild->parent = root;
////////
	root->lChild->lChild = new Node(5);
	root->lChild->lChild->parent = root->lChild;

	root->lChild->rChild = new Node(15);
	root->lChild->rChild->parent = root->lChild;
//////
	root->lChild->lChild->lChild = new Node(3);
	root->lChild->lChild->lChild->parent = root->lChild->lChild;

	root->lChild->lChild->rChild = new Node(7);
	root->lChild->lChild->rChild->parent = root->lChild->lChild;

	root->lChild->rChild->rChild = new Node(17);
	root->lChild->rChild->rChild->parent = root->lChild->rChild;
///////

	//cout << *commonAncestor(root->lChild->lChild->lChild, root->lChild->rChild->rChild)->data << endl;
	//cout << *commonAn(root, root->lChild->lChild->lChild, root->lChild->rChild->rChild)->data << endl;
	//cout << *CA(root, root->lChild->lChild->lChild, root->lChild->rChild->rChild)->data << endl;

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}