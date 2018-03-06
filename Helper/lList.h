#include <iostream>
#include "/Users/johns/Documents/Visual Studio 2015/Projects/CCI_2/Helper/Node.h"

template<class T>
class lList{

private:
	Node<T>* head;
	size_t count;

public:

	lList();
	lList( Node<T> *inHead );
	lList( lList<T> *inList);
	lList( lList<T> &inList );
	~lList();

	void append( T inData );
	void append( T *inData );
	void append( Node<T> *inNode );

	void push(T inData);
	void push(T *inData);
	void push(Node<T> *inNode);

	Node<T>* popNode();
	T* popData();

	T* peek();

	Node<T>* dupList();

	bool contains(T inData);

	void print();

};

///////////////////////////////////
// lList member functions.
///////////////////////////////////


template<class T>
lList<T>::lList(){
	head = nullptr;
	count = 0;
}

template<class T>
lList<T>::lList(Node<T> *inHead){
	head = inHead;
	Node<T>* walker = head;
	count = 0;
	while(walker){
		count++;
		walker = walker->getNext();
	}
}

template<class T>
lList<T>::lList(lList<T> *inList){
	head = inList->dupList(inList);
}

template<class T>
lList<T>::lList(lList<T> &inList){
	head = dupList(inList);
}

template<class T>
lList<T>::~lList(){
	Node<T>* dNode = nullptr;
	while(head){
		dNode = head;
		head = head->getNext();
		dNode->setNext(nullptr);
		delete dNode;
		dNode = nullptr;
	}
}

template<class T>
void lList<T>::append(T inData){
	append(new T(inData));
}

template<class T>
void lList<T>::append(T *inData){
	if( inData == nullptr ){ return; }
	append(new Node<T>(inData));
}

template<class T>
void lList<T>::append(Node<T> *inNode){
	if( inNode == nullptr ){ 
		return;
	} else if(head == nullptr ){
		head = inNode;
	} else {
		Node<T>* walker = head;
		while( walker->getNext() ){
			walker = walker->getNext();
		}
		walker->setNext(inNode);		
	}
	count++;
}

template<class T>
void lList<T>::push(T inData){
	push( new T(inData) );
}

template<class T>
void lList<T>::push(T *inData){
	push( new Node<T>(inData) );
}

template<class T>
void lList<T>::push(Node<T> *inNode){
	if (inNode == nullptr) {
		return;
	}
	else if (head == nullptr) {
		head = inNode;
	}
	else {
		inNode->setNext(head);
		head = inNode;
	}
	count++;
}

// Print all links in list.
template<class T>
void lList<T>::print(){
	Node<T>* walker = head;
	while(walker){
		std::cout << *(walker->getData()) << " ";
		walker = walker->getNext();
	}
	std::cout << std::endl;
}

template<class T>
Node<T>* lList<T>::popNode(){
	if(head == nullptr){ return nullptr; }
	Node<T>* rNode = head;
	head = head->getNext();
	rNode->setNext(nullptr);
	count--;
	return rNode;
}

template<class T>
T* lList<T>::popData(){
	if(head == nullptr){ return nullptr; }
	Node<T>* dNode = head;
	T* outData = head->getData();
	head = head->getNext();
	dNode->setNext(nullptr);
	dNode->setData(nullptr);
	delete dNode;
	dNode = nullptr;
	count--;
	return outData;	
}

template<class T>
T* lList<T>::peek(){
	if(head == nullptr){ return nullptr; }
	return head->getData();
}

template<class T>
Node<T>* lList<T>::dupList(){
	lList<T> outList;
	Node<T>* outHead = nullptr;
	Node<T>* walker = this->head;
	
	while(walker){
		outList.append( *(walker->getData()) );
		walker = walker->getNext();
	}
	outHead = outList.head;
	outList.head = nullptr;
	return outHead;
}

template<class T>
bool lList<T>::contains(T inData){
	if(head == nullptr){ return false; }
	bool found = false;
	Node<T> *runner = head;
	while(runner && !found){
		if(*runner->getData() == inData){
			found = true;
		}
		runner = runner->getNext();
	}
	return found;
}