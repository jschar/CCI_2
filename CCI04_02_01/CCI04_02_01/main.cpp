/*

	Minimal Tree: Given a sorted (increasing order) array with unique integer elements, write an 
algorithm to create a binary search tree with minimal height.

*/

#include <iostream>
#include <utility>
#include <queue>

using namespace std;

#define ARR_MAX 20

template<class T>
class BST {

private:
	class Node {
	private:
		T* data;
		Node* lChild;
		Node* rChild;

	public:
		Node():data(nullptr), lChild(nullptr), rChild(nullptr) { }
		Node(T* inData):data(inData), lChild(nullptr), rChild(nullptr) { }

		void setData(T* inData){ data = inData; }
		T* getData(){ return data; }

		void setLChild(Node* inNode){ lChild = inNode; }
		Node* getLChild(){ return lChild; }

		void setRChild(Node* inNode){ rChild = inNode; }
		Node* getRChild(){ return rChild; }

	};

	Node* root;

public:

	BST(): root(nullptr){ }
	
	void add(T inData);
	void print();

};

template<class T>
void BST<T>::add(T inData){
	Node* nNode = new Node(new T(inData));
	if(root == nullptr){ root = nNode; return; }
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
}

template<class T>
void BST<T>::print(){
	if(root == nullptr){ return; }
	int level = 0;

	typedef pair<Node*,int> node_level;
	queue<node_level> aQue;
	aQue.push(node_level(root,1));

	while(!aQue.empty()){
		node_level n1 = aQue.front();
		aQue.pop();
		if( n1.first != nullptr ){
			if(level != n1.second){ // new level.
				cout << '\n' << "Level: " << n1.second << endl;
				level = n1.second;
			}
			cout << *n1.first->getData() << ' ';
			aQue.push(node_level(n1.first->getLChild(), level + 1));
			aQue.push(node_level(n1.first->getRChild(), level + 1));
		}
	}
	cout << endl;
}

template<class T>
void buildTree( BST<T>* tree, int arr[ARR_MAX], int start, int end ){
	if(start > end){ return; }
	tree->add(arr[(start+end)/2-1]);
	buildTree(tree, arr, start, (start+end)/2-1);
	buildTree(tree, arr, (start+end)/2+1, end);
}

int main(void){

	int iArr[ARR_MAX] = {0};
	BST<int> aTree;

	for( int i=0; i < ARR_MAX; i++ ){
		iArr[i] = i;
	}

	buildTree<int>( &aTree, iArr, 1, ARR_MAX );
	aTree.print();

	cout << "End of line." << endl;
	cin.ignore();

	return 0;
}