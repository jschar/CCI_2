/*
	Intersection: Given two (singly) linked lists, determine if the two lists intersect.
Return the intersecting node. Note that the intersectin is defined based on reference, not value.
That is, if the kth node of the first linked list is the exact same node (by reference) as the
jth node of the second linked list, then they are intersecting.
*/

#include <iostream>
#include "/Users/johns/Documents/Visual Studio 2015/Projects/CCI_2/Helper/Node.h"

using namespace std;

template<class T>
int lLen( Node<T> *head ){
	if( head == nullptr ){ return 0; }
	int count = 0;
	Node<T> *runner = head;
	while( runner ){
		count++;
		runner = runner->getNext();
	}
	return count;
}

template<class T>
Node<T>* intersect( Node<T>* head1, Node<T>* head2 ){
	if( head1 == nullptr || head2 == nullptr ){ return nullptr; }

	Node<T>* lRun = head1;
	Node<T>* sRun = head2;

	while( lRun->getNext() || sRun->getNext() ){
		if(lRun->getNext()){ lRun = lRun->getNext(); }
		if(sRun->getNext()){ sRun = sRun->getNext(); }
	}

	if( lRun != sRun ){ return nullptr; }

	int len1 = lLen(head1);
	int len2 = lLen(head2);

	lRun = (len1 > len2) ? head1 : head2;
	sRun = (len1 < len2) ? head1 : head2;

	for( int i=0; i<std::abs(len1-len2); i++ ){
		lRun = lRun->getNext();
	}

	while( lRun && sRun ){
		if( lRun == sRun ){ return lRun; }
		lRun = lRun->getNext();
		sRun = sRun->getNext();
	}
	return nullptr;
}

int main(void){

	Node<int> *head1 = new Node<int>(5);
	head1->setNext( new Node<int>(6) );
	head1->getNext()->setNext( new Node<int>(7) );
	head1->getNext()->getNext()->setNext( new Node<int>(8) );
	head1->getNext()->getNext()->getNext()->setNext( new Node<int>(9) );

	Node<int> *head2 = new Node<int>(2);
	head2->setNext( new Node<int>(3) );
	head2->getNext()->setNext( new Node<int>(4) );
	head2->getNext()->getNext()->setNext( head1->getNext()->getNext() );

	head1->printTail(); cout << endl;
	head2->printTail(); cout << endl;

	Node<int>* corr = intersect( head1, head2 );

	if( corr ){
		cout << "Node: " << *corr->getData() << endl;
	} else {
		cout << "Nullptr." << endl;
	}

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}