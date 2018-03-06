/*

	4.3: List of Depths: Given a binary tree, design an algorithm which creates a linked list
of all the nodes at each depth (e.g., If you have a tree with depth D, you'll have D linked lists).

*/

#include <iostream>
#include <list>
#include <queue>
#include <utility>

using namespace std;

class BST{

private:
	class Node {
	private:
		int* data;
		Node* lChild;
		Node* rChild;

	public:
		Node(): data(nullptr), lChild(nullptr), rChild(nullptr) { }
		Node(int inData): data(new int(inData)), lChild(nullptr), rChild(nullptr) { }
	
		void setData(int* inData){ data = inData; }
		int* getData(){ return data; }
	
		void setLChild(Node* nNode){ lChild = nNode; }
		Node* getLChild(){ return lChild; }

		void setRChild(Node* nNode){ rChild = nNode; }
		Node* getRChild(){ return rChild; }

	};

	Node* root;
	int size;
	list<Node*> *arr;

public:

	BST():root(nullptr), size(0), arr(nullptr){ }

	void add(int inData);
	void buildTree(int *arr, int size);
	Node* buildTreeHelper(int *arr, int start, int end);
	void tree2list();
	int getDepth(Node* root);
	void printList();

};

void BST::add(int inData){
	Node* nNode = new Node(inData);
	if( root == nullptr ){ root = nNode; return; }
	bool found = false;
	Node* walker = root;
	while(!found){
		if( *nNode->getData() < *walker->getData() ){
			if( walker->getLChild() ){
				walker = walker->getLChild();
			} else {
				walker->setLChild(nNode);
				found = true;
			}
		} else {
			if(walker->getRChild()){
				walker = walker->getRChild();
			} else {
				walker->setRChild(nNode);
				found = true;
			}
		}
	}
	return;
}

void BST::buildTree(int *arr, int size){
	if(size <= 0){ return; }
	root = buildTreeHelper(arr, 1, size);
}


typename BST::Node* BST::buildTreeHelper(int *arr, int start, int end){
	if(start > end){ return nullptr; }
	int mid = (start+end)/2;
	BST::Node* node = new BST::Node(arr[mid-1]);
	node->setLChild(buildTreeHelper(arr, start, mid-1));
	node->setRChild(buildTreeHelper(arr, mid+1, end));
	return node;
}

void BST::tree2list(){
	if(root == nullptr){ return; }
	size = getDepth(root);
	int level = 0;
	arr = new list<Node*>[size];
	typedef pair<Node*,int> node_level;
	node_level lNode;
	lNode.first = root;
	lNode.second = level;
	queue<node_level> aQue;
	aQue.push(lNode);

	while(!aQue.empty()){
		lNode = aQue.front();
		aQue.pop();
		arr[lNode.second].push_front(lNode.first);
		if(level != lNode.second){ level++; }
		if(lNode.first->getLChild()){
			aQue.push(pair<Node*,int>(lNode.first->getLChild(),level+1));
		}

		if(lNode.first->getRChild()){
			aQue.push(pair<Node*,int>(lNode.first->getRChild(),level+1));
		}
	}
}

int BST::getDepth(Node* root){
	if( root == nullptr ){ return 0; }
	int num1 = getDepth(root->getLChild());
	int num2 = getDepth(root->getRChild());
	return (num1 > num2)? num1+1:num2+1;	
}

void BST::printList(){
	if(arr == nullptr){ return; }
	for( int i = 0; i<size; i++ ){
		cout << "Level " << i + 1 << ":";
		for(list<Node*>::iterator it = arr[i].begin(); it != arr[i].end(); it++){
			cout << " " << *(*it)->getData();
		}
		cout << endl;
	}
}



#define ARR_MAX 20

int main(void){

	int iArr[ARR_MAX] = {0};
	for( int i=0; i<20; i++ ){
		iArr[i] = i;
	}

	BST aTree;
	aTree.buildTree(iArr, ARR_MAX);
	aTree.tree2list();
	aTree.printList();

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}