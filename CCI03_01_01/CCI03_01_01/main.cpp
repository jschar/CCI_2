/*
		Three in one: Describe how you could use a single array to implement
	three stacks.
*/

#include <iostream>
#include "/Users/johns/Documents/Visual Studio 2015/Projects/CCI_2/Helper/Stack.h"
#include "/Users/johns/Documents/Visual Studio 2015/Projects/CCI_2/Helper/Queue.h"

using namespace std;

#define ARR_MAX 20
#define DIV 3

enum _SNUM { FIRST = 1, SECOND, THIRD }; // The arr is divided into three stacks, each stack has a position.

class arrStack{
private:
	int arr[ARR_MAX] = {0};
	int s1Count = 0, s2Count = 0, s3Count = 0;
	int sLen = ARR_MAX/DIV;

	// Insert by copying all elements in the stack backwards.
	bool insert( int data, _SNUM pos ){
		// Copy all elements backwards.
		int start = sLen*pos-1; // Start at the back of the stack.
		int end = sLen*(pos-1); // Stop at the front.
		for( int i = start; i > end; i-- ){
			arr[i] = arr[i-1];
		}
		arr[end] = data;
		return true;
	}

	// Remove elements by copying them forward.
	int remove(_SNUM pos){
		int outVar = arr[sLen*(pos-1)];	// The element to return.
		// Copy everything forward.
		for(int i=sLen*(pos-1); i<sLen*pos-1; i++){
			arr[i] = arr[i+1];
		}
		return outVar;
	}

public:
	bool push(int data, _SNUM pos) {
		bool success = false;
		switch (pos) {
		case _SNUM::FIRST:
			if (s1Count < sLen) { s1Count++; success = insert(data, pos); } break;
		case _SNUM::SECOND:
			if (s2Count < sLen) { s2Count++; success = insert(data, pos); } break;
		case _SNUM::THIRD:
			if (s3Count < sLen) { s3Count++; success = insert(data, pos); } break;
		} // End switch.
		return success;
	} // end push()

	int pop(_SNUM pos){
		int outVar = 0;
		switch(pos){
			case _SNUM::FIRST:
				if(s1Count > 0){ s1Count--; outVar = remove(pos); } break;
			case _SNUM::SECOND:
				if(s2Count > 0){ s2Count--; outVar = remove(pos); } break;
			case _SNUM::THIRD:
				if(s3Count > 0){ s3Count--; outVar = remove(pos); } break;
		} // end of switch.
		return outVar;
	}

	void printArr(){
		for( int i=0; i<ARR_MAX; i++ ){
			cout << arr[i] << ' ';
		}
	}
};


int main(void){

	arrStack aStack;

	aStack.push(4, SECOND);
	aStack.push(5, SECOND);
	aStack.push(6, SECOND);
	aStack.push(7, SECOND);
	aStack.push(8, SECOND);
	aStack.push(4, SECOND);
	aStack.push(5, SECOND);
	aStack.push(6, SECOND);
	aStack.push(7, SECOND);
	aStack.push(8, SECOND);
	aStack.printArr(); cout << endl;
	
	cout << "Pop: " << aStack.pop(SECOND) << endl;
	cout << "Pop: " << aStack.pop(SECOND) << endl;
	cout << "Pop: " << aStack.pop(SECOND) << endl;
	cout << "Pop: " << aStack.pop(SECOND) << endl;
	cout << "Pop: " << aStack.pop(SECOND) << endl;
	cout << "Pop: " << aStack.pop(SECOND) << endl;
	cout << "Pop: " << aStack.pop(SECOND) << endl;

	aStack.printArr(); cout << endl;

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}

/*
Stack<int> aStack;
for( int i=0; i<10; i++ ){
aStack.push(i);
}
aStack.printStack(); cout << endl;
Node<int> *aNode = aStack.pop();
cout << "aNode: " << *aNode->getData() << endl;
cout << *aStack.peek()->getData() << endl;
cout << "is empty: " << aStack.isEmpty() << endl;
*/

/*
Queue<int> aQueue;
for( int i=0; i<10; i++ ){
aQueue.add(i);
}
aQueue.printQueue(); cout << endl;
Node<int> *aNode = aQueue.remove();
cout << "aNode: " << *aNode->getData() << endl;
cout << "Peek: " << *aQueue.peek()->getData() << endl;
cout << "isEmpty: " << aQueue.isEmpty() << endl;
*/