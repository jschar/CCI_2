#include "/Users/johns/Documents/Visual Studio 2015/Projects/CCI_2/Helper/Stack.h"
#include <iostream>

template<class T>
Stack<T>::~Stack(){
	Node<T> *dNode = nullptr;
	while(head){
		dNode = head;
		head = head->getNext();
		delete dNode;
	}
}

template<class T>
T* Stack<T>::pop(){
	if( head == nullptr ){ return nullptr; }
	Node<T> *dNode = head;
	T* outData = dNode->getData();
	head = head->getNext();
	dNode->setNext(nullptr);
	size--;
	delete dNode;
	return outData;
}

template<class T>
void Stack<T>::push(T inData){
	push( new T(inData) );
}

template<class T>
void Stack<T>::push(T* inData){
	if( inData == nullptr ){ return; }
	push( new Node<T>(inData) );
}

template<class T>
void Stack<T>::push(Node<T>* inNode){
	if( inNode == nullptr ){ return; }
	size++;
	inNode->setNext(head);
	head = inNode;
}

template<class T>
Node<T>* Stack<T>::peek(){
	return head;
}

template<class T>
bool Stack<T>::isEmpty(){
	return (head)? true:false;
}

template<class T>
void Stack<T>::printStack(){
	Node<T>* walker = head;
	while( walker ){
		std::cout << *walker->getData() << ' ';
		walker = walker->getNext();
	}
}

template<class T>
short unsigned int Stack<T>::getSize(){
	return size;
}

template class Stack<int>;