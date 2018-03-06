/*
	Sum Lists: You have two numbers represented by a linked ist, where each node contains a single
digit. The digits are stored in reverse order, such that the 1's digit is at the head of the list.
Write a function that adds the two numbers and returns the sum as a linked list.

Example
Input: (7->1->6) + (5->9->2). That is, 617 + 295.
Output: 2->1->9. That is, 912

Follow up.
Suppose the digits are stored in foward order. Repeat the above problem.

Example
Input: (6->1->7) + (2->9->5). That is, 617+295.
Output: 9->1->2. That is, 912.
*/

#include <iostream>
#include "/Users/johns/Documents/Visual Studio 2015/Projects/CCI_2/Helper/Node.h"

using namespace std;

template<class T>
void addLists( Node<T>* aList, Node<T>* bList ){
	if(aList == nullptr || bList == nullptr){ return; }
	Node<T> *aRunner = aList;
	Node<T> *bRunner = bList;
	Node<T> *lNode = nullptr; // Last node.
	Node<T> *head = nullptr;
	int sum = 0;
	int carry = 0;

	sum = *aList->getData() + *bList->getData();
	carry = (sum >= 10)? 1:0;
	head = new Node<T>(sum % 10);
	lNode = head;

	aRunner = aRunner->getNext();
	bRunner = bRunner->getNext();
	sum = 0;

	while( aRunner || bRunner ){
		if( aRunner ){ sum += *aRunner->getData(); aRunner = aRunner->getNext(); }
		if( bRunner ){ sum += *bRunner->getData(); bRunner = bRunner->getNext(); }
		sum += carry;
		carry = (sum >= 10)? 1 : 0;
		lNode->setNext(new Node<T>(sum % 10));
		sum = 0;
		lNode = lNode->getNext();
	}
	head->printTail(); cout << endl;
	head->deleteTail();
	delete head;
}

int main(void){

	Node<int> *num1 = nullptr;
	Node<int> *num2 = nullptr;

	num1 = new Node<int>(7, new Node<int>(1, new Node<int>(new Node<int>(6))));
	cout << "num1: "; num1->printTail(); cout << endl;

	num2 = new Node<int>(5, new Node<int>(9, new Node<int>(new Node<int>(2))));
	cout << "num2: "; num2->printTail(); cout << endl;

	addLists( num1, num2 );

	delete num1; num1 = nullptr;
	delete num2; num1 = nullptr;

	num1 = new Node<int>(1, new Node<int>(1, new Node<int>(new Node<int>(1))));
	cout << "num1: "; num1->printTail(); cout << endl;

	num2 = new Node<int>(1, new Node<int>(1, new Node<int>(1,new Node<int>(1,new Node<int>(1)))));
	cout << "num2: "; num2->printTail(); cout << endl;

	addLists(num1, num2);

	delete num1; num1 = nullptr;
	delete num2; num1 = nullptr;

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}