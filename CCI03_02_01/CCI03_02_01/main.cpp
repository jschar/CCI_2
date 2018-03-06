/*

		3.2 Stack Min: How would you design a stack which, in addition to push and pop,
has a function min which returns the minimum element? Push, pop, min should all operate in
O(1) time.

*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "/Users/johns/Documents/Visual Studio 2015/Projects/CCI_2/Helper/Stack.h"

using namespace std;

void keepMin(){
	Stack<int> aStack;
	Stack<int> minStack; 
	int inData = 0;
	
	for(int i=0; i<20; i++){
		inData = rand() % 10 + 1;
		aStack.push(inData);
		if( minStack.peek() == nullptr || *minStack.peek()->getData() >= inData ){
			minStack.push(inData);
		}
	}
	cout << "aStack: ";   aStack.printStack();   cout << endl;
	cout << "minStack: "; minStack.printStack(); cout << endl;

	while( *aStack.peek()->getData() != *minStack.peek()->getData() ){
		delete aStack.pop();
	}
	cout << "aStack: ";   aStack.printStack();   cout << endl;
	cout << "minStack: "; minStack.printStack(); cout << endl;
}

int main(void){

	srand(time(NULL));

	keepMin();

	cout << "End of line." << endl;
	cin.ignore();	
	return 0;
}