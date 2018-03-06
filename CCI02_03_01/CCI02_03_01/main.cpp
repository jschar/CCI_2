/*
	Delete middle node: Implement an algorithm to delete a node in the middle
(i.e., any node but the first and the lastnode, not necessarily the exact middle)
of a singly linked list, given only access to that node.
*/

#include <iostream>
#include "/Users/johns/Documents/Visual Studio 2015/Projects/CCI_2/Helper/Node.h"

using namespace std;

Node<int>* buildList(){
	Node<int> *head = new Node<int>(9);
	Node<int> *nNode = nullptr;
	for( int i=8; i>0; i-- ){
		nNode = new Node<int>(i);
		nNode->setNext(head);
		head = nNode;
	}
	nNode = nullptr;
	return head;
}

template<class T>
void delMid( Node<T> *head, T tar ){
	Node<T> *walker = head;
	Node<T> *dNode = nullptr;
	while(walker){
		if( *walker->getData() == tar ){
			delete walker->getData();							// Delete old data.
			walker->setData( walker->getNext()->getData() );	// Copy the data back.
			walker->getNext()->setData(nullptr);				// Set the data we cpoied from to nothing.
			dNode = walker->getNext();							// Store the node we'll delete.
			walker->setNext( walker->getNext()->getNext() );	// Remove the node from the list.
			delete dNode;
			dNode = nullptr;
		}
		walker = walker->getNext();
	}
}

int main(void){

	Node<int> *head = nullptr;
	head = buildList();
	head->printTail(); cout << endl;

	delMid( head, 5 );
	head->printTail(); cout << endl;

	delMid(head, 4);
	head->printTail(); cout << endl;

	delMid(head, 6);
	head->printTail(); cout << endl;
	

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}