#include "Animals.h"
#include <time.h>
#include <iostream>
#include <string>
#include <memory>

//////////////
//Animal class.
/////////////////
Animal::Animal(){ }
Animal::Animal(std::string &inName): aName(inName){ }
Animal::Animal(int inTime, const std::string &inName):tEntered(inTime), aName(inName) {

}

void Animal::setTime(int inTime){ tEntered = inTime; }

int Animal::getTime() const { return tEntered; }

void Animal::speak() { }

void Animal::setName(const std::string &inStr){ aName = inStr; }

std::string Animal::getName(){ return aName; }

bool Animal::operator<(const Animal &other)
{
	return (tEntered < other.getTime());
}


///////////////////
// Dog class.
//////////////////
Dog::Dog() { }

Dog::Dog(std::string &inName): Animal(inName){ }

Dog::Dog(int inTime, const std::string &inName): Animal(inTime,inName){
	
}

void Dog::speak(){
	std::cout << "Woof" << std::endl;
}

std::ostream &operator<<(std::ostream &output, const Dog &D) {
	output << const_cast<Dog*>(&D)->getName();
	return output;
}

//////////////
// Cat class.
////////////////
Cat::Cat() { }

Cat::Cat(std::string &inName): Animal(inName){ }

Cat::Cat(int inTime, const std::string &inName): Animal(inTime,inName){

}

void Cat::speak(){
	std::cout << "Meow" << std::endl;
}

std::ostream &operator<<(std::ostream &output, const Cat &C){
	output << const_cast<Cat*>(&C)->getName();
	return output;
}