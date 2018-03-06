#pragma once
#ifndef _LLIST_HPP
#define _LLIST_HPP

#include <iostream>

template<class T>
class lList{

private:
	class Node{
	private:
		Node *next;
		T* data;
	public:
		Node(T inData);
		~Node();

		Node* getNext();
		void setNext(Node *inNode);

		T* getData();
		void setData(T *ptrData);

	};

	Node *head;

public:

	lList();
	~lList();
	
	bool add(T inData);
	T* remove();
	T* peek();
	bool contains(T mark);
	void print();
};

template<class T>
lList<T>::Node::Node(T inData){
	next = nullptr;
	data = new T(inData);
}


template<class T>
typename lList<T>::Node* lList<T>::Node::getNext(){
	return next;
}


template<class T>
void lList<T>::Node::setNext(Node *inNode){
	next = inNode;
}

template<class T>
T* lList<T>::Node::getData(){
	return data;
}

template<class T>
void lList<T>::Node::setData(T *ptrData){
	data = ptrData;
}

template<class T>
lList<T>::Node::~Node(){
	next = nullptr;
	delete data;
	data = nullptr;
}

template<class T>
lList<T>::lList(){
	head = nullptr;
}

template<class T>
lList<T>::~lList(){
	Node* dNode = nullptr;
	while(head){
		dNode = head;
		head = head->getNext();
		delete dNode;
		dNode = nullptr;
	}
}

template<class T>
bool lList<T>::add(T inData){
	if( this->contains(inData) ){ return false; }
	Node *nNode = new Node(inData);
	if(head == nullptr){
		head = nNode;
	} else {
		nNode->setNext(head);
		head = nNode;
	}
	return true;
}

template<class T>
T* lList<T>::remove(){
	if(head == nullptr){ return nullptr; }
	Node* delNode = head;
	T* outData = head->getData();
	head = head->getNext();
	delNode->setNext(nullptr);
	delNode->setData(nullptr);
	delete delNode;
	delNode = nullptr;
	return outData;
}

template<class T>
T* lList<T>::peek(){
	return head? head->getData():nullptr;
}

template<class T>
bool lList<T>::contains(T mark){
	if(head == nullptr){ return false; }
	bool found = false;
	Node* runner = head;
	while(runner && !found){
		if(*runner->getData() == mark){
			found = true;
		}
		runner = runner->getNext();
	}
	return found;
}

template<class T>
void lList<T>::print(){
	if(head == nullptr){ return; }
	Node* runner = head;
	while(runner){
		std::cout << ' ' << *runner->getData();
		runner = runner->getNext();
	}
	std::cout << endl;
}

#endif