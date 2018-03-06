/*

	2.8 Loop Detection: Given a circular linked list, implement an algorithm that returns
the node at the beginning of the loop.

Definition
Circular linked list: A (corrupt) linked list in which a node's next pointer points to an
to an earlier node, so as to make a loop in the linked list.
Example
input: a->b->c->d->e->c [the same as earlier]
output: c

*/

#include <iostream>
#include "/Users/johns/Documents/Visual Studio 2015/Projects/CCI_2/Helper/Node.h"

using namespace std;

template<class T>
Node<T>* findLoop( Node<T>* head ){
	if( head == nullptr ){ return nullptr; }

	Node<T>* sPtr = head;
	Node<T>* fPtr = head;
	Node<T>* outNode = nullptr;

	while( sPtr && fPtr && fPtr->getNext() ){
		sPtr = sPtr->getNext();
		fPtr = fPtr->getNext()->getNext();
		if( sPtr == fPtr ){
			break;
		}
	}
	sPtr = head;
	while( sPtr != fPtr ){
		sPtr = sPtr->getNext();
		fPtr = fPtr->getNext();
	}
	outNode = sPtr;
	fPtr = fPtr->getNext();
	while( sPtr != fPtr->getNext() ){
		fPtr = fPtr->getNext();
	}
	fPtr->setNext(nullptr);
	return outNode;
}

template<class T>
void printRecu( Node<T>* head, int n ){
	if( head == nullptr || n == 0 ){ return; }
	cout << *head->getData() << ' ';
	printRecu( head->getNext(), n-1 );
}

int main(void){
	
	Node<char> *head = new Node<char>('A');
	head->setNext( new Node<char>('B') );
	head->getNext()->setNext(new Node<char>('C'));
	head->getNext()->getNext()->setNext(new Node<char>('D'));
	head->getNext()->getNext()->getNext()->setNext( new Node<char>('E') );
	head->getNext()->getNext()->getNext()->getNext()->setNext( head->getNext()->getNext() );

	printRecu( head, 8 ); cout << endl;

	Node<char> *loopS = findLoop( head );
	cout << *loopS->getData() << endl;
	head->printTail(); cout << endl;

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}