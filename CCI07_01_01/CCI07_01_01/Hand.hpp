#pragma once
#ifndef HAND_H
#define HAND_H

#include <list>
#include "Card.hpp"

class Hand {
private:
	int bet;
	int handValue;
	std::list<Card> handCards;

public:

	Hand();

	void setBet(int inBet);
	int getBet();

	void setHandValue(int inVal);
	int getHandValue();

	void addCard(Card inCard);
	std::list<Card>& getHandCards();
	void printHand();
};

Hand::Hand() : bet(0), handValue(0) {

}

void Hand::setBet(int inBet) {
	if (inBet < 0) { return; }
	bet = inBet;
}

int Hand::getBet() {
	return bet;
}

void Hand::setHandValue(int inVal) {
	handValue = inVal;
}

int Hand::getHandValue() {
	return handValue;
}

void Hand::addCard(Card inCard) {
	handCards.push_front(inCard);
	handValue += inCard.cValue;
	if(handValue > 21){ // Bust.
		// Cycle through hand and change the first ace we find at 11 to 1.
		bool found = false;
		for(std::list<Card>::iterator it = handCards.begin(); it != handCards.end() && !found; it++){
			if(it->fValue == ACE && it->cValue == 11){
				found = true;
				it->cValue = 1;
				handValue -= 10;
			}
		}
	}
}

std::list<Card>& Hand::getHandCards(){
	return handCards;
}

void Hand::printHand(){
	if(handCards.size() == 0){
		std::cout << "Empty hand." << std::endl;
	} else {
		for(std::list<Card>::iterator it = handCards.begin(); it != handCards.end(); it++){
			std::cout << it->pValue() << " ";
		}
		std::cout << "| " << handValue;
	}
}

#endif