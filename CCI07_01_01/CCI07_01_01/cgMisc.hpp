#pragma once
#ifndef CGMISC_H
#define CGMISC_H

#include <iostream>

enum SUIT { JOKE = 0, HEART, DIAMOND, SPADE, CLUB };
enum FACE { JK = 0, ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

bool askYN(const std::string &inStr){
	std::string input;
	bool rVal = false;
	bool again = true;
	while(again){
		std::cout << inStr << std::endl;
		std::cout << "Yes/No?: ";
		getline(std::cin,input);
		if(input[0] == 'Y' || input[0] == 'y'){
			rVal = true;
			again = false;
		} else if(input[0] == 'N' || input[0] == 'n'){
			rVal = false;
			again = false;
		} else {
			std::cout << " Invalid input: " << input;
		}
		std::cout << std::endl;
	}
	return rVal;
}

#endif`
