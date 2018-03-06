#include "Animal.h"

////////////////
// Animal
///////////////
Animal::Animal() : rEntered(time_t(0)), name("No Name") {

}

Animal::Animal(time_t &inTime, std::string &inName) {
	rEntered = inTime;
	localtime_s(&dtEntered, &rEntered);
	asctime_s(cEntered, 26, &dtEntered);
	name = inName;
}

Animal::Animal(Animal &&inAn) : rEntered(0), name("") {
	if (this != &inAn) {
		*this = std::move(inAn);
	}
}

Animal& Animal::operator= (Animal&& other) {
	this->name = other.name;
	this->setTime(other.getrTime());
	other.name = "No name";
	other.setTime(time_t(0));
	return *this;
}

void Animal::setTime(time_t inTime) {
	rEntered = inTime;
	localtime_s(&dtEntered, &rEntered);
	asctime_s(cEntered, 26, &dtEntered);
}

time_t Animal::getrTime() const {
	return rEntered;
}

std::string Animal::getTime() const {
	return std::string(cEntered);
}

void Animal::setName(const std::string &inName) {
	name = inName;
}

std::string Animal::getName() const {
	return name;
}

std::ostream & operator<<(std::ostream &output, const Animal & obj) {
	output << obj.getName() << " : " << obj.getTime();
	return output;
}

template<typename T>
static std::shared_ptr<T> Animal::creat(std::string &&name) {
	return make_shared<T>(std::move(name));
}

/////////
// Dog
/////////
Dog::Dog() {

}

Dog::Dog(const Dog& inDog) {

}

Dog::Dog(Animal &&inAn) : Animal(std::move(inAn)) {

}

void Dog::speak() {
	std::cout << "Woof!" << std::endl;
}

/////////
// Cat
/////////
Cat::Cat() {

}

Cat::Cat(const Cat& inCat) {

}

Cat::Cat(Animal &&inAn) : Animal(std::move(inAn)) {

}

void Cat::speak() {
	std::cout << "Meow" << std::endl;
}
