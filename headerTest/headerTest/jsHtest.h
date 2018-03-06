#ifndef JSHTEST_H
#define JSHTEST_H

#include <iostream>

class Balloon{

public:
	int size;
	void print();

	Balloon():size(5) { };
};

/*
void Balloon::print(){
	std::cout << "Balloon size: " << size << std::endl;
}
*/

#endif
