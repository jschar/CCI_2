
#include <iostream>
#include "/Users/johns/Documents/Visual Studio 2015/Projects/CCI_2/Helper/Node.h"

using namespace std;

template<class T>
Node<T>* buildList(){

	Node<T>* outHead = new Node<T>(9);
	Node<T>* nNode = nullptr;

	for( int i=8; i>1; i-- ){
		nNode = new Node<T>(i);
		nNode->setNext( outHead );
		outHead = nNode;
	}
	return outHead;
}

/*
	send two runners, one k places ahead of the other. 
When one reached the end the other must be k places from the end.
*/
template<class T>
void KtoLast_01( Node<T> *head, int k ){
	if( head == nullptr ){ return; }
	if( k <= 0 ){ return; }
	Node<T>* runner = head;
	Node<T>* place = head;

	place = head;
	for( int i=1; i<k; i++ ){
		runner = runner->getNext();
		if(runner == nullptr){ return; } // List isn't long enough.
	}

	while( runner->getNext() ){
		place = place->getNext();
		runner = runner->getNext();
	}
	cout << k << " : " << *place->getData() << endl;	
}

//Use recursion to count the nodes.
template<class T>
T* KtoLast_02( Node<T> *head, int k ){
	Node<T> *node = nullptr;
	int  i = 0;
	node = K2Lrecur( head, k, i);
	return (node)? node->getData():nullptr;
}

template<class T>
Node<T>* K2Lrecur( Node<T> *head, int k, int &i ){
	Node<T> *node = nullptr;
	if( head == nullptr ){ return nullptr; }
	node = K2Lrecur( head->getNext(), k, i );
	i++;
	if( i == k ){ return head; }
	return node;
}

template<class T>
void print( Node<T> *head ){
	if(head == nullptr){ return; }
	Node<T>* walker = head;
	while(walker){
		cout << *walker->getData() << " ";
		walker = walker->getNext();
	}
	cout << endl;
}

int main(void){

	Node<int> *head = buildList<int>();
	int* place = nullptr;
	print( head );
	//KtoLast_01( head, 3 );
	//KtoLast_01(head, 5);
	//KtoLast_01(head, 1);
	place = KtoLast_02( head, 3 );
	
	if(place){
		cout << *place << endl;
	}

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}