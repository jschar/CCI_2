#include "/Users/johns/Documents/Visual Studio 2015/Projects/CCI_2/Helper/Queue.h"
#include <iostream>

template<class T>
void Queue<T>::enqueue(T inData){
	enqueue( new T(inData) );
}

template<class T>
void Queue<T>::enqueue(T* inData){
	if(inData == nullptr){ return; }
	enqueue( new Node<T>(inData) );
}

template<class T>
void Queue<T>::enqueue(Node<T>* inNode){
	if( inNode == nullptr ){ return; }
	if( head == nullptr ){ head = inNode; return; }
	Node<T>* walker = head;
	while( walker->getNext() ){ walker = walker->getNext(); }
	walker->setNext(inNode);
}

template<class T>
T* Queue<T>::dequeue(){
	if(head == nullptr){ return nullptr; }
	Node<T>* dNode = head;
	T* outData = dNode->getData();
	head = head->getNext();
	dNode->setNext(nullptr);
	dNode->setData(nullptr);
	return outData;
}

template<class T>
T* Queue<T>::peek(){
	return head->getData();
}

template<class T>
bool Queue<T>::isEmpty(){
	return (head)? true:false;
}

template<class T>
void Queue<T>::print(){
	if(head == nullptr){ return; }
	Node<T>* walker = head;
	while( walker ){
		std::cout << *walker->getData() << ' ';
		walker = walker->getNext();
	}
}

// Use an implimentation file for other data types.
//template class Queue<int>;