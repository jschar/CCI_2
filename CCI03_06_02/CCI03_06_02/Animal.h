#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <time.h>
#include <memory>

class Animal{
private:
	time_t rEntered; // Raw time entered.
	char cEntered[26] = {0}; // char/string entered.
	struct tm dtEntered; // Detailed time entered.
	std::string name;

public:
	Animal();
	Animal(time_t &inTime, std::string &inName);
	Animal(Animal &&inAn);
	Animal& operator=(Animal&& other);

	void setTime( time_t inTime );
	time_t getrTime() const ;
	std::string getTime() const;

	void setName( const std::string &inName );
	std::string getName() const;

	virtual void speak()=0;

	bool operator < (const Animal &other){
		return this->getrTime() < other.getrTime();
	}

	friend std::ostream &operator<<( std::ostream& output, const Animal& obj);

	template<typename T>
	static std::shared_ptr<T> creat( std::string &&name);

};

///////
// Dog
//////
class Dog : public Animal{
private:

public:
	Dog();
	Dog(const Dog& inDog);
	Dog(Animal &&inAn);
	virtual void speak();

};

///////
// Cat
///////
class Cat : public Animal {
private:

public:
	Cat();
	Cat(const Cat& inCat);
	Cat(Animal &&inAn);
	virtual void speak();

};

#endif