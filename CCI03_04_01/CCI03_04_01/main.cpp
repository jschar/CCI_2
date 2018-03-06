/*
		3.4: Implement a MyQueue class which implements a queue using two stacks.
*/

#include <iostream>
#include "/Users/johns/Documents/Visual Studio 2015/Projects/CCI_2/Helper/Stack.h"

using namespace std;

template<class T>
class QueSta{
private:
	Stack<T> bSta; // Queue backwards.

public:
	void push(T inData);
	T* pop();
	void print();
};

template<class T>
void QueSta<T>::push(T inData){
	bSta.push(inData);
}

template<class T>
T* QueSta<T>::pop(){
	Stack<T> fSta; //Stack forwards.

	while(bSta.peek()){
		fSta.push(bSta.pop());
	}
	T* outData = fSta.pop();
	while(fSta.peek()){
		bSta.push(fSta.pop());
	}
	return outData;
}

template<class T>
void QueSta<T>::print(){
	bSta.printStack();
}

int main(void){

	QueSta<int> aQue;
	int *dData = nullptr;

	for(int i=0; i<10; i++){
		aQue.push(i);
	}
	aQue.print(); cout << endl;
	dData = aQue.pop();
	cout << *dData << endl;
	aQue.print(); cout << endl;
	dData = aQue.pop();
	cout << *dData << endl;
	aQue.print(); cout << endl;
	aQue.push(77);
	aQue.print(); cout << endl;

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}