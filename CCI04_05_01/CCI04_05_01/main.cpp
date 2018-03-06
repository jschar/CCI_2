/*

	4.5: Validate BST: Implement a funtion to check if a binary tree is a binary tree.

*/

#include <iostream>
#include <vector>

using namespace std;

class BSTree{
private:
	
public:

};

class TNode{
private:

public:
	int *data;
	TNode* lChild;
	TNode* rChild;

	TNode():data(nullptr), lChild(nullptr), rChild(nullptr) { }
	TNode(int inData):data(new int(inData)), lChild(nullptr), rChild(nullptr) { }
};

void copyBST(TNode* root, vector<int> &arr){
	if(root == nullptr){ return; }
	copyBST(root->lChild, arr);
	arr.push_back(*root->data);
	copyBST(root->rChild, arr);
}

bool checkTreeIOT(TNode *root) {
	vector<int> arr;
	copyBST(root, arr);
	for (int i = 1; i<arr.size(); i++) {
		if (arr[i - 1] >= arr[i]) { return false; }
	}
	return true;
}

bool checkTreeL(TNode *nRoot, int **last){
	if(nRoot == nullptr){ return true; }
	if(!checkTreeL(nRoot->lChild,last)){ return false; }
	if(last != nullptr && *last != nullptr && *nRoot->data <= **last){ return false;	}
	*last = nRoot->data;
	if(!checkTreeL(nRoot->rChild,last)){ return false; }
	return true;
}

bool checkTreeMM(TNode* nRoot);
bool checkTreeMM(TNode* nRoot, int min, int max);

bool checkTreeMM(TNode* nRoot){
 return checkTreeMM(nRoot, INT_MIN, INT_MAX);
}

bool checkTreeMM(TNode *nRoot, int min, int max){
	if( nRoot == nullptr ){ return true; }
	if((min != INT_MIN && *nRoot->data <= min) || (max != INT_MAX && *nRoot->data > max)){
		return false;
	}
	if(!checkTreeMM(nRoot->lChild, min, *nRoot->data) || !checkTreeMM(nRoot->rChild, *nRoot->data, max)){
		return false;
	}
	return true;
}

int main(void){

	TNode* root;
	root = new TNode(9);
	root->lChild = new TNode(5);
	root->rChild = new TNode(12);
	
	root->lChild->lChild = new TNode(3);
	root->lChild->rChild = new TNode(7);

	root->rChild->lChild = new TNode(10);
	root->rChild->rChild = new TNode(14);

	int *passer = nullptr;

	//cout << (checkTreeIOT(root)? "True":"False") << endl;
	//cout << (checkTreeL(root, &passer)?"True":"False") << endl;
	cout << (checkTreeMM(root) ? "True" : "False") << endl;

	root->lChild->lChild->lChild = new TNode(20);
	//cout << (checkTreeIOT(root) ? "True" : "False") << endl;
	//cout << (checkTreeL(root, &passer)?"True":"Fasle") << endl;
	cout << (checkTreeMM(root) ? "True" : "False") << endl;



	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}