/*

	3.5: Sort Stack: Write a program such that the smallest items are on the top.
You can use an additional temporary stack, but you may not copy the elements into
any other data structure (such as an array). The stack supports the following
operations: push, pop, peek, and isEmpty.

*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "/Users/johns/Documents/Visual Studio 2015/Projects/CCI_2/Helper/Stack.h"

using namespace std;

template<class T>
void sortStack( Stack<T> &inStack ){

	if(inStack.peek() == nullptr){ return; } // Stack empty.
	Stack<T> oStack; // Other stack.
	T* hPtr = nullptr; // Holder pointer.

	oStack.push( inStack.pop() );

	while(inStack.peek()){
		hPtr = inStack.pop();
		while(oStack.peek() != nullptr && *hPtr < *oStack.peek()->getData()){
			inStack.push(oStack.pop());
		}
		oStack.push(hPtr);
	}
	// Move everything back in sorted order.
	while(oStack.peek()){
		inStack.push(oStack.pop());
	}
	return;
}

int main(void){

	srand(time(NULL));

	Stack<int> aSta;

	for(int i=0; i<20; i++){
		aSta.push( rand() % 20 + 1 );
	}
	aSta.printStack(); cout << endl;
	sortStack(aSta);
	aSta.printStack(); cout << endl;

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}