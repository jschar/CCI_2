#pragma once
#ifndef NODE_H
#define NODE_H
template<class T>
class Node{
private:
	Node<T>* next;
	T* data;

public:
	Node();
	Node( T inData );
	Node( T* inData );
	Node( Node<T>* inNode );
	Node(  T inData, Node<T>* inNext );
	Node( T* inData, Node<T>* inNext);
	~Node();

	void setNext( Node<T>* inNode ){ next = inNode; }
	Node<T>* getNext(){ return next; }

	void setData( T inData ){ setData(new T(inData)); }
	void setData( T* inData ){ data = inData; }
	T* getData(){ return data; }

	void printTail();
	void deleteTail();
	
};

template<class T>
Node<T>::Node(): next(nullptr), data(nullptr){ }

template<class T>
Node<T>::Node( T inData ): next(nullptr), data(new T(inData)){ }

template<class T>
Node<T>::Node( T* inData ): next(nullptr), data(inData){ }

template<class T>
Node<T>::Node(T inData, Node<T>* inNext) : data(new T(inData)), next(inNext) { }

template<class T>
Node<T>::Node(T* inData, Node<T>* inNext) : data(inData), next(inNext) { }

//Deep copy a node.
template<class T>
Node<T>::Node( Node<T>* inNode ): next(nullptr) {
	if( inNode ){
		if( inNode->getData() ){
			data = new T( *inNode->getData() );
		}
	}
}

template<class T>
Node<T>::~Node(){
	next = nullptr;
	data = nullptr;
}

template<class T>
void Node<T>::printTail(){
	if( data ){ cout << *data << " "; }
	if( next ){ next->printTail(); }
}

template<class T>
void Node<T>::deleteTail(){
	Node<T>* dNode = nullptr;
	while(next){
		dNode = next;
		next = next->next;
		delete dNode->getData();
		delete dNode;
		dNode = nullptr;
	}
	delete data;
	data = nullptr;
	next = nullptr;
}
#endif