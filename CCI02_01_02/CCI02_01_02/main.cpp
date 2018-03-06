

#include <iostream>
#include <unordered_map>
#include "C:\Users\johns\Documents\Visual Studio 2015\Projects\CCI_2\Helper\lList.h"
using namespace std;


/*
	Check values against a hash map to see if they already exist.
*/
template<class T>
void removeDup_01(lList<T> &inList) {
	unordered_map<int, bool> buffer;
	lList<T> outList;
	T* ptrData = nullptr;
	
	while( ptrData = inList.popData() ){
		if( buffer.count(*ptrData) <= 0 ){
			buffer[*ptrData] = true;
			outList.append(ptrData);
		}
	}

	while( outList.peek() ){
		inList.append( outList.pop() );
	}
}

template<class T>
void removeDup_02(lList<T> &inList){

}

//////////////////////////////////////////////////////
// Main.
/////////////////////////////////////////////////////

int main(void){

	lList<int> aList;

	aList.append(9);
	aList.append(1);
	aList.append(2);
	aList.append(3);
	aList.append(4);
	aList.append(5);
	aList.append(6);
	aList.append(6);
	aList.append(7);
	aList.append(8);
	aList.append(3);
	aList.append(9);

	removeDup_01( aList );
	aList.print();

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}