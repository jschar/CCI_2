/*

Remove Dups: Write code to remove duplicates from an unsorted linked list.

How would you solve this problem if a temporary buffer is not allowed?.

*/

#include <iostream>

using namespace std;

template <class T>
class Node {

private:
	Node<T> *next;
	T *data;

public:
	Node(){
		next = nullptr;
		data = nullptr;
	}

	Node( T inData ){
		next = nullptr;
		data = new T( inData );
	}

	~Node(){
		next = nullptr;
		delete data;
		data = nullptr;
	}
	
	Node<T>* getNext(){ return next; }
	void setNext( Node<T> *nNext ){ next = nNext; }

	T* getData(){ return data; }
	void setData( T* inData ){ data = inData; }
	
};

template<class T>
class lList{

private:
	Node<T> *head;

public:
	lList(){
		head = nullptr;
	}

	lList( Node<T> *inNode ){
		head = inNode;
	}

	Node<T>* peek(){ return head; }
	void printList();
	void prepend( Node<T> *inNode );
	void append( Node<T> *inNode );
	void deleteNode( T val );
	Node<T>* removeNode();

};

template<class T>
void lList<T>::printList(){
	if(head == nullptr){ return; }
	Node<T> *walker = head;
	while( walker != nullptr ){
		cout << *(walker->getData()) << " ";
		walker = walker->getNext();
	}
	cout << endl;
}

template<class T>
void lList<T>::prepend(Node<T> *inNode){
	if(inNode == nullptr){ return; }
	inNode->setNext(head);
	head = inNode;
}

template<class T>
void lList<T>::append(Node<T> *inNode){
	if(inNode == nullptr){ return; }
	if(head == nullptr){ head = inNode; return; }
	Node<T> *walker = head;

	while( walker->getNext() != nullptr ){
		walker = walker->getNext();
	}
	walker->setNext(inNode);
}

template<class T>
void lList<T>::deleteNode( T val ){
	if( head == nullptr ){ return; }

	Node<T> *walker = head;

	if( *(walker->getData()) == val ){
		head = walker->getNext();
		walker->setNext(nullptr);
		delete walker;
		return;
	}

	Node<T> *prev = walker;
	walker = walker->getNext();

	while( walker != nullptr ){
		if( *(walker->getData()) == val ){
			prev->setNext(walker->getNext());
			walker->setNext(nullptr);
			delete walker;
			break;
		}
		prev = walker;
		walker = walker->getNext();
	}
}

template<class T>
Node<T>* lList<T>::removeNode(){
	if(head == nullptr){ return nullptr; }
	Node<T>* dNode = head;
	head = head->getNext();
	dNode->setNext(nullptr);
	return dNode;
}

template<class T>
lList<T>* removeDups_01( lList<T> &inList ){

	if( inList.peek() == nullptr ){ return nullptr; }
	Node<T>* iNode = nullptr;
	bool found = false;
	Node<T>* prev = nullptr;
	Node<T>* curr = nullptr;
	Node<T>* head = nullptr;

	while(iNode = inList.removeNode()){
		if(head == nullptr){
			head = iNode;
		} else if( *(head->getData()) == *(iNode->getData()) ){
			delete iNode;
			iNode = nullptr;
		} else if( *(head->getData()) > *(iNode->getData()) ){
				iNode->setNext(head);
				head = iNode;
		} else {
			if(head->getNext() == nullptr ){
				head->setNext(iNode);
				continue;
			}
			prev = head;
			curr = head->getNext();
			while(curr){
				if( *(curr->getData()) == *(iNode->getData()) ){ // New node is a dup, remove it.
					delete iNode;
					iNode = nullptr;
					curr = nullptr;
				} else if( *(curr->getData()) > *(iNode->getData()) ){ // insert new node.
					prev->setNext(iNode);
					iNode->setNext(curr);
					curr = nullptr;
				} else if( *(curr->getData()) < *(iNode->getData()) ){ // Move new node down the list.
					if(curr->getNext() == nullptr){ // New node goes at the end of the list.
						curr->setNext(iNode);
						curr = nullptr;
					} else { // Keep moving down the list.
						prev = curr;
						curr = curr->getNext();
					}
				}
			}
		}
	}

	lList<T> *outList = new lList<T>;
	outList->append(head);
	return outList;
}


int main(void){

	/*
	Node<int> head(1);
	for( int i=2; i<=10; i++ ){
		head.appendToTail( new Node<int>(i) );
	}
	head.appendToTail(new Node<int>(3));
	head.appendToTail(new Node<int>(6));
	head.appendToTail(new Node<int>(9));
	head.print();
	cout << endl;
	*/

	/*
	lList<int> aList;
	for( int i=1; i<10; i++){
		aList.append(new Node<int>(i));
	}

	aList.printList();
	aList.deleteNode(5);
	aList.printList();
	*/

	lList<int> aList;
	lList<int> *bList = nullptr;

	aList.append(new Node<int>(6));
	aList.append(new Node<int>(7));
	aList.append(new Node<int>(8));
	aList.append(new Node<int>(9));
	aList.append(new Node<int>(4));
	aList.append(new Node<int>(5));
	aList.append(new Node<int>(9));
	aList.append(new Node<int>(6));
	aList.append(new Node<int>(1));
	aList.append(new Node<int>(2));
	aList.append(new Node<int>(3));
	aList.append(new Node<int>(3));

	aList.printList();

	bList = removeDups_01( aList );

	bList->printList();

	cout << "End of line." << endl;
	cin.ignore();

	return 0;
}