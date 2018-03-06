#pragma once
#ifndef CARD_H
#define CARD_H

#include "cgMisc.hpp"

class Card {
private:

public:
	SUIT cSuit;
	FACE fValue; // Card's face value, QUEEN KING ACE TWO.
	int cValue; // Number for counting score.
	

	Card();
	Card(SUIT inSuit, int cValue, FACE inFace);

	std::string pSuit();
	std::string pValue();

};

Card::Card() : cSuit(SUIT(0)), cValue(0), fValue(FACE(0)){

}

Card::Card(SUIT inSuit, int inVal, FACE inFace) {
	cSuit = inSuit;
	cValue = inVal;
	fValue = inFace;
}

std::string Card::pSuit() {
	std::string outVal = "";
	switch (cSuit) {
		case HEART:		outVal = "H"; break;
		case DIAMOND:	outVal = "D"; break;
		case SPADE:		outVal = "S"; break;
		case CLUB:		outVal = "C"; break;
		case JOKE:		outVal = "JK"; break;
	}
	return outVal;
}

std::string Card::pValue() {
	std::string outVal = "";
	switch (fValue) {
		case ACE:	outVal = "A"; break;
		case TEN:	outVal = "10"; break;
		case JACK:	outVal = "J"; break;
		case QUEEN:	outVal = "Q"; break;
		case KING:	outVal = "K"; break;
		default:	outVal = '0' + cValue;
	}
	return outVal;
}

#endif