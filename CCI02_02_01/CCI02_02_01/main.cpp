/*
	Return Kth to last: Implement an algorithm to find the kth to last element
of a singly linked list.
*/

#include <iostream>
#include "/Users/johns/Documents/Visual Studio 2015/Projects/CCI_2/Helper/lList.h"

using namespace std;

template<class T>
T KtoLast_01( Node<T>* head ){

}

template<class T>
T* KtoLast_02( lList<T> &inList, int k ){
	if( k <= 0 ){ return nullptr; }
	lList<T> cList(inList.dupList()); // Deep copied inList.
	lList<T> rList; // Reversed list.
	while( cList.peek() ){
		rList.push( *cList.popData() );
	}

	for( int i=1; i<k && rList.peek(); i++ ){
		delete rList.popData();
	}
	return rList.popData();
}

int main(void){

	lList<int> aList;

	for( int i=1; i<10; i++ ){
		aList.append(i);
	}

	cout << "aList: ";
	aList.print();

	int* num = nullptr;
	if( num = KtoLast_02( aList, 3 ) ){
		cout << "Number out: " << *num << endl;
	}

	if (num = KtoLast_02(aList, 1)) {
		cout << "Number out: " << *num << endl;
	}

	if (num = KtoLast_02(aList, 2)) {
		cout << "Number out: " << *num << endl;
	}


	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}