/*

	Stack of stacks. Us an array to store stacks.

*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "/Users/johns/Documents/Visual Studio 2015/Projects/CCI_2/Helper/Stack.h"

using namespace std;

#define ARR_MAX 10
#define STA_MAX 10

template<class T>
class ArrStack {
private:
	Stack<T> sArr[ARR_MAX];
	int sIndex;

public:
	ArrStack() : sIndex(0) {}
	void push(T inData);
	bool push(T *inData);
	T* pop();
	void printArrSta();

};

int main(void){

	srand(time(NULL));

	ArrStack<int> ArrSta01;
	for( int i=0; i < 35; i++ ){
		ArrSta01.push( rand() % 20 + 1 );
	}
	ArrSta01.printArrSta(); cout << endl;

	for( int j=0; j<6; j++ ){
		delete ArrSta01.pop();
	}
	ArrSta01.printArrSta(); cout << endl;
	

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}

template<class T>
void ArrStack<T>::push(T inData){
	if(sIndex >= STA_MAX-1){ return; } // Stack is full.
	push(new T(inData));
}

template<class T>
bool ArrStack<T>::push(T *inData){
	bool success = false;
	if(inData == nullptr){ return success; }
	if(sIndex >= STA_MAX-1){ return success; } // This could be bad because inData might not get deleted.
	success = true;
	if(sArr[sIndex].getSize() >= 10){ sIndex++; }
	sArr[sIndex].push(inData);
	return success;
}

template<class T>
T* ArrStack<T>::pop(){
	if(sIndex <= 0){ return nullptr; }
	Node<T>* outNode = sArr[sIndex].pop();
	T* outData = nullptr;
	if(outNode){ outData = outNode->getData(); } // We never pop from an empty list but what ever.
	if(sArr[sIndex].getSize() <= 0){ sIndex--; }
	outNode->setData(nullptr);
	return outData;
}

template<class T>
void ArrStack<T>::printArrSta(){
	if(sArr[sIndex].peek() == nullptr){ return; }
	for(int i=0; i<=sIndex; i++){
		sArr[i].printStack(); cout << " | ";
	}
}