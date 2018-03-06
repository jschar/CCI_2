/*

	4.4: Check Balanced: Implement a functin to check if a binary tree is balanced.
For the purposees of this question, a balanced tree is defined to be a tree such that the height of the two
subtrees of any node never differ by more than one.

*/

#include <iostream>
#include <stdlib.h>
#include <queue>
#include <utility>

using namespace std;

class BST{
private:
	class Node{
	private:

	public:
		int *data;
		Node *lChild;
		Node *rChild;

		Node():data(nullptr),lChild(nullptr),rChild(nullptr){ }
		Node(int *inData): data(inData), lChild(nullptr), rChild(nullptr) { }
	};

	Node* findNode(int mark);
	Node* buildTree(int *arr, int start, int end);
	int checkBalanceHelper(Node* root, bool& balanced);
	int getDepth();

public:
	Node* root;
	
	BST():root(nullptr){ }

	void add(int inData);
	void remove(int mark);
	void buildTree(int *arr, int size);
	void print();
	bool checkBalance();
};

void BST::add(int inData){
	Node* nNode = new Node(new int(inData));
	if(root == nullptr){ root = nNode; return; }
	bool found = false;
	Node* walker = root;
	
	while(!found){
		if( *nNode->data < *walker->data ){
			if (walker->lChild == nullptr) {
				walker->lChild = nNode;
				found = true;
			} else {
				walker = walker->lChild;
			}
		} else {
			if( walker->rChild == nullptr){
				walker->rChild = nNode;
				found = true;
			} else {
				walker = walker->rChild;
			}
		}
	}
}

BST::Node* BST::findNode(int mark){
	if(root = nullptr){ return nullptr; }
	Node* walker = root;
	bool found = false;
	while(!found){
		if(*walker->data == mark){ 
			found = true; 
		} else if( *walker->data < mark ){
			if(walker->lChild){
				// Keep going.
				walker = walker->lChild;
			} else {
				// Mark not found.
				return nullptr; 
			}
		} else { // walker > mark
			if(walker->rChild){
				// Keep going.
				walker = walker->rChild;
			} else {
				// mark not found.
				return nullptr;
			}
		}
	}
	return walker;
}

void BST::remove(int mark){
	if(root == nullptr){ return; }
	Node* walker = root;
	Node* parent = root;
	bool found = false;

	// Find node.
	while(!found){
		if(*walker->data == mark){
			found = true;
		} else {
			if(mark < *walker->data){
				if(walker->lChild){
					parent = walker;
					walker = walker->lChild;
				} else {
					// Mark isn't in tree.
					return;
				}
			} else { // mark > wlaker
				if(walker->rChild){
					parent = walker;
					walker = walker->rChild;
				} else {
					// Mark isn't in tree.
					return;
				}
			} // walker < mark.
		} // walker == mark
	} // while !found

	// Swap nodes.

	// Node is a leaf.
	// Delete node and remove from parent.
	if(walker->rChild == nullptr && walker->lChild == nullptr){
		if(walker == parent->lChild){
			parent->lChild = nullptr;
		} else if( walker == parent->rChild ){
			parent->rChild = nullptr;
		}
		delete walker;
	} else if(walker->rChild == nullptr){ //No right child to swap. Move left child up.
		Node* dNode = walker->lChild;
		delete walker->data;
		walker->data = dNode->data;
		walker->lChild = dNode->lChild;
		walker->rChild = dNode->rChild;
		delete dNode;
	} else { //Find the next greatest node. The right nodes left most node.
		Node* mNode = walker;
		parent = walker;
		walker = walker->rChild;
		if(walker->lChild == nullptr){
			// There's no left node so swap right nodes up.
			delete parent->data;
			parent->data = walker->data;
			parent->rChild = walker->rChild;
		} else {
			// Find left most node.
			bool found = false;
			while (!found) {
				if (walker->lChild == nullptr) {
					found = true;
				}
				else {
					parent = walker;
					walker = walker->lChild;
				}
			}
			parent->lChild = nullptr;
			delete mNode->data;
			mNode->data = walker->data;
			delete walker;
		}
	}	
}

void BST::buildTree(int *arr, int size){
	if(arr == nullptr || size == 0){ return; }
	root = buildTree(arr,1,size);
}

BST::Node* BST::buildTree(int *arr, int start, int end){
	if(start > end){ return nullptr; }
	int mid = (start+end)/2;
	Node* nNode = new Node(new int(arr[mid-1]));
	nNode->lChild = buildTree(arr, start, mid-1);
	nNode->rChild = buildTree(arr, mid+1, end);
	return nNode;	
}

void BST::print(){
	if(root == nullptr){ return; }
	int level = 0;
	typedef pair<Node*,int> node_level;
	node_level nl;
	queue<node_level> aQue;
	aQue.push(pair<Node*,int>(root,1));	

	while(!aQue.empty()){
		nl = aQue.front();
		aQue.pop();
		if(nl.second != level){
			level++;
			cout << '\n' << "Level " << level << endl;
		}
		cout << " " << *nl.first->data;
		if(nl.first->lChild){
			aQue.push(pair<Node*,int>(nl.first->lChild, level+1));
		}

		if(nl.first->rChild){
			aQue.push(pair<Node*,int>(nl.first->rChild, level+1));
		}
	}
	cout << endl;
}

bool BST::checkBalance(){
	bool unBalanced = false;
	checkBalanceHelper(root, unBalanced);
	return (unBalanced == false);
}

int BST::checkBalanceHelper(Node* root, bool& unBalanced){
	if(root == nullptr){ return 0; }
	if(unBalanced){ return 2; }
	int diff = abs(checkBalanceHelper(root->lChild, unBalanced)- checkBalanceHelper(root->rChild, unBalanced));
	if (diff > 1) { unBalanced = true; }
	return diff+1;
}

#define ARR_MAX 20

int main(void){

	int arr[ARR_MAX] = {0};
	BST aTree;

	for( int i=0; i<20; i++ ){
		arr[i] = i;
	}

	aTree.buildTree(arr,ARR_MAX);

	//cout << (aTree.checkBalance()?"True":"False") << endl;
	//aTree.remove(19);
	//aTree.remove(18);
	//cout << (aTree.checkBalance() ? "True" : "False") << endl;

	BST bTree;
	
	bTree.add(2);
	bTree.add(1);
	bTree.add(3);
	cout << (bTree.checkBalance() ? "True" : "False") << endl;
	bTree.add(4);
	cout << (bTree.checkBalance() ? "True" : "False") << endl;
	bTree.add(5);
	cout << (bTree.checkBalance() ? "True" : "False") << endl;
	bTree.print();
	bTree.remove(5);
	cout << (bTree.checkBalance() ? "True" : "False") << endl;
	bTree.print();

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}