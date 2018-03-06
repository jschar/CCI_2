/*

	3.6: Animal shelter: An animal shelter, which holds only dogs and cats, operates on a strickly
"first in, first out" basis. People must adopt either the "oldest" (based on arrival time)
of all animals at the shelter, or they can select whether they would prefer adog or a cat
(and will receive the oldest animal of that type). They cannot select which specific animal they
would like. Createthe data structure to maintain this system and implement operations such as
enqueue, dequeueAny, dequeueDog, and dequeueCat. You may use the built-on LinkedList data structure.

*/

#include <iostream>
#include "/Users/johns/Documents/Visual Studio 2015/Projects/CCI_2/Helper/Queue.h"
#include "Animals.h"
#include <string>

using namespace std;

void test(int &&num){

	return;
}

class Shelter{
private:
	unsigned long int serialNumber;
	Queue<Dog> dQue;
	Queue<Cat> cQue;

public:
	Shelter(): serialNumber(0) { }
	void enqueue( Cat *inCat );
	void enqueue( Dog *inDog );
	Animal* dequeueAny();
	Dog* dequeueDog();
	Cat* dequeueCat();

	void print();

};

void Shelter::enqueue( Cat *inCat ){
	if( inCat == nullptr ){ return; }
	serialNumber++;
	inCat->setTime(serialNumber);
	cQue.enqueue(inCat);
}

void Shelter::enqueue( Dog *inDog ){
	if(inDog == nullptr){ return; }
	serialNumber++;
	inDog->setTime(serialNumber);
	dQue.enqueue(inDog);
}

Animal* Shelter::dequeueAny(){
	Animal *outAn = nullptr;
	if(dQue.peek()->getTime() < cQue.peek()->getTime()){
		outAn = dQue.dequeue();
	} else {
		outAn = cQue.dequeue();
	}
	return outAn;
}

Dog* Shelter::dequeueDog(){ return dQue.dequeue(); }

Cat* Shelter::dequeueCat(){ return cQue.dequeue(); }

void Shelter::print(){
	cQue.print(); cout << endl;
	dQue.print(); cout << endl;
}

int main(void){

	Shelter aShel;

	string name = "";
	for(int i=0; i<10; i++){
		aShel.enqueue(new Dog(string("Dog " + to_string(i))));
		aShel.enqueue(new Cat(string("Cat " + to_string(i))));
	}
	aShel.print();
	for(int i=0; i<10; i++){
		Animal* anyOut = nullptr;
		anyOut = aShel.dequeueAny();
		cout << anyOut->getName() << " : " << anyOut->getTime() << endl;
		delete anyOut;
		anyOut = nullptr;
	}

	for(int i=0; i<3; i++){
		Cat* catOut = nullptr;
		catOut = aShel.dequeueCat();
		cout << catOut->getName() << " : " << catOut->getTime() << endl;
		delete catOut;
		catOut = nullptr;	
	}

	for(int i=0; i<3; i++){
		Dog* dogOut = nullptr;
		dogOut = aShel.dequeueDog();
		cout << dogOut->getName() << " : " << dogOut->getTime() << endl;
		delete dogOut;
		dogOut = nullptr;
	}

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}