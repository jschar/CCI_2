/*



*/


#include <iostream>
#include <memory>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "Animal.h"
#include "/Users/johns/Documents/Visual Studio 2015/Projects/CCI_2/Helper/Queue.h"

using namespace std;

class Shelter{
private:
	Queue<shared_ptr<Dog>> qDog;
	Queue<shared_ptr<Cat>> qCat;
	

public:
	Shelter(){ }

	void enqueue( shared_ptr<Animal> &&inAn );
	shared_ptr<Animal> dequeueAny();
	shared_ptr<Animal> dequeueCat();
	shared_ptr<Animal> dequeueDog();
	
	class BadAnimalException {};

};

void Shelter::enqueue(shared_ptr<Animal> &&inAn){
	//if( auto dog = dynamic_pointer_cast<Dog>(inAn)){
	//	qDog.enqueue(dog);
	//} else if( auto cat = dynamic_pointer_cast<Cat>(inAn)){
	//	qCat.enqueue(cat);
	//} else {
	//	throw BadAnimalException();
	//}
}

shared_ptr<Animal> Shelter::dequeueAny(){
	//if(qDog.isEmpty() && qCat.isEmpty()){
	//	return nullptr;
	//} else if(qDog.isEmpty()) {
	//	return *qCat.dequeue();
	//} else if(qCat.isEmpty()){
	//	return *qDog.dequeue();
	//}
	//else if(*qDog.peek() < *qCat.peek()){
	//	return *qDog.dequeue();
	//}
	//else {
	//	return *qCat.dequeue();
	//}
	return nullptr; //Remove.
}

shared_ptr<Animal> Shelter::dequeueCat(){
	//return (qCat.isEmpty())? *qCat.dequeue():nullptr;
	return nullptr;
}

shared_ptr<Animal> Shelter::dequeueDog(){
	//return (qDog.isEmpty())? *qDog.dequeue():nullptr;
	return nullptr;
}

int main(void){

	srand(time(nullptr));

	Shelter aShel;

	Queue<int> aQue;
	aQue.isEmpty();
	Queue<Dog> bQue;
	bQue.isEmpty();

	Queue<shared_ptr<Dog>> cQue;
	cQue.isEmpty();

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}