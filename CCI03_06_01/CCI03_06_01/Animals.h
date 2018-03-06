#pragma once
#ifndef ANIMALS_H
#define ANIMALS_H

#include <iostream>
#include <time.h>
#include <memory>


// Abstract class
class Animal{
private:
	int tEntered;
	std::string aName;

public:
	Animal();
	Animal(std::string &inTime);
	Animal(int inTime, const std::string &inName);
	virtual void speak() = 0;

	void setName(const std::string &inName);
	std::string getName();

	void setTime(int inTime);
	int getTime() const;

	bool Animal::operator<(const Animal & other);
};

class Dog : public Animal {
private:

public:
	Dog();
	Dog(std::string &inName);
	Dog(int inTime, const std::string &inName);
	void speak();
};

class Cat : public Animal {
private:

public:
	Cat();
	Cat(std::string &inName);
	Cat(int inTime, const std::string &inName);
	void speak();
};

std::ostream &operator<<(std::ostream &output, const Cat &C);
std::ostream &operator<<(std::ostream &output, const Dog &D);

#endif
