#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include "/Users/johns/Documents/Visual Studio 2015/Projects/CCI_2/Helper/Node.h"

template<class T>
class Queue{

private:
	Node<T>* head;
	void enqueue(Node<T>* inNode);

public:
	Queue(): head(nullptr) { }

	void enqueue( T inData );
	void enqueue( T* inData );
	T* dequeue();
	T* peek();
	bool isEmpty();
	void print();
};

#endif
