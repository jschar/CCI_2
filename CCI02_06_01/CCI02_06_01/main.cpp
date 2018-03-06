/*

	2.6: Palindrome: Implement a function to check if a linked list is a palindrome.

	recursive: pass header.
	iteritive: pass half of the list into a stack.
	other: reverce the list.

*/

#include <iostream>
#include <string>
#include "/Users/johns/Documents/Visual Studio 2015/Projects/CCI_2/Helper/Node.h"

using namespace std;

template<class T>
bool isPalin( Node<T>* head ){
	return isPalinHelper( head, head );
}

template<class T>
bool isPalinHelper( Node<T>*& lPtr, Node<T>* rPtr ){
	if( rPtr == nullptr ){ return true; }
	bool flagPalin = isPalinHelper(lPtr, rPtr->getNext());
	if( !flagPalin ){ return false; }

	flagPalin = ( *lPtr->getData() == *rPtr->getData() );
	lPtr = lPtr->getNext();
	return flagPalin;	
}


int main(void){

	Node<char> *head = nullptr;
	
/*
	for( char c : string("racecar") ){
		head = new Node<char>( c, head );
	}
	head->printTail(); cout << endl;
	cout << "palin: " << isPalin( head ) << endl;
	head->deleteTail();
	head = nullptr;

	for (char c : string("battle") ){
		head = new Node<char>(c, head);
	}
	head->printTail(); cout << endl;
	cout << "palin: " << isPalin( head ) << endl;
	head->deleteTail();
	head = nullptr;

	for (char c : string("rattar")) {
		head = new Node<char>(c, head);
	}
	head->printTail(); cout << endl;
	cout << "palin: " << isPalin(head) << endl;
	head->deleteTail();
	head = nullptr;
*/

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}