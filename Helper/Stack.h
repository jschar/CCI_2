#pragma once
#ifndef STACK_H
#define STACK_H

#include "/Users/johns/Documents/Visual Studio 2015/Projects/CCI_2/Helper/Node.h"

template<class T>
class Stack{

private:
	Node<T> *head;
	short unsigned int size;

public:

	Stack(): head(nullptr), size(0){ };
	~Stack();

	T* pop();
	void push( T inData );
	void push( T* inData );
	void push( Node<T>* inNode );
	Node<T>* peek();
	bool isEmpty();
	void printStack();

	short unsigned int getSize();

};

#endif