/*

	2.4: Partition: Write code to partition a linked list around a value x, such that all nodes less
than x come before all nodes greater than or equal to x. If x is contained within the list, the values
of x only need to be after the elements less than x (see below). The partition element x can appear'
anywhere in the "right partition"; it does not need to appear between the left and right partions.

EXAMPLE

input: 3->5->8->5->10->2->1 [ partition = 5 ]
output: 3->1->2->10->5->5->8

*/

#include <iostream>
#include "/Users/johns/Documents/Visual Studio 2015/Projects/CCI_2/Helper/Node.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

template<class T>
Node<T>* buildList(){
	Node<T>* nNode = nullptr;
	Node<T>* head = new Node<T>( rand() % 10 );
	for( int i=0; i<15; i++ ){
		nNode = new Node<T>( rand() % 9 + 1 );
		nNode->setNext( head );
		head = nNode;
	}
	return head;
}


template<class T>
void part_01( Node<T>* head, int p ){
	if( head == nullptr ){ return; }
	if( p < 0 ){ return; }

	// - initialize pNode
	// pNode = new node head->data;
	Node<T>* pNode = new Node<T>( head );

	// -   since we add nodes and copy information forward the first
	// - node in our new list will always be the head, so just remember that.
	// outNode = pNode;
	Node<T>* outHead = pNode;

	// -run through list
	Node<T>* runner = head->getNext();
	// while runner
	while(runner){
		// if runner is < p
		if( *runner->getData() < p ){
			// insert and new node after pNode
			pNode->setNext( new Node<T>( pNode->getData(), pNode->getNext() ) );
			// replace info in org node.
			pNode->setData( *runner->getData() );
			// more pNode forward.
			pNode = pNode->getNext();
		} else { // else if( *runner->setData() >= p ){
			// - insert new node after p
			pNode->setNext(new Node<T>(*runner->getData(), pNode->getNext()));
		}
		runner = runner->getNext();
	}
	outHead->printTail(); cout << endl;
	outHead->deleteTail();
	delete outHead;
}

int main(void){

	srand(time(NULL));

	Node<int> *head = nullptr;

	head = buildList<int>();
	head->printTail(); cout << endl;
	part_01( head, 5 );
	head->deleteTail();
	delete head;
	cout << endl;

	head = buildList<int>();
	head->printTail(); cout << endl;
	part_01(head, 6);
	head->deleteTail();
	delete head;
	cout << endl;

	head = buildList<int>();
	head->printTail(); cout << endl;
	part_01(head, 7);
	head->deleteTail();
	delete head;
	cout << endl;

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}