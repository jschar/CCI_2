#pragma once
#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <iomanip>
#include <exception>
#include "Card.hpp"

// Deck size.
#define DSIZE 52

// Suit size.
#define SSIZE 4

// Value size.
#define VSIZE 11

class Deck {
private:
	//list<Card> cardList;
	Card *cardArr;
	int size;
	void buildDeck();

public:

	Deck();
	void printA();
	void newDeck();
	void shuffleDeck();
	Card draw();

};

Deck::Deck() : cardArr(new Card[DSIZE]()), size(DSIZE) {
	this->buildDeck();
}

void Deck::buildDeck() {
	int index = 0;

	// Aces
	for(int su=HEART; su <= CLUB; su++){
		cardArr[index] = Card(SUIT(su), 11, ACE);
		index++;
	}

	// Cards 2-10.
	for(int val=TWO; val<=TEN; val++){
		for( int su=HEART; su <= CLUB; su++){
			cardArr[index] = Card(SUIT(su), val, FACE(val));
			index++;
		}
	}

	// Face cards. J-K
	for( int fVal=JACK; fVal <= KING; fVal++ ){
		for(int su=HEART; su <= CLUB; su++){
			cardArr[index] = Card(SUIT(su), 10, FACE(fVal));
			index++;
		}
	}
}

void Deck::printA() {
	for (int i = 0; i<DSIZE; i++) {
		if (i % 13 == 0 && i != 0) {
			std::cout << std::endl;
		}
		std::cout << std::setw(6) << std::left;
		std::cout << cardArr[i].pSuit() + ":" + cardArr[i].pValue();
	}
	std::cout << std::endl;
}

void Deck::newDeck(){
	this->size = DSIZE;
	this->shuffleDeck();
}

/*
	Shuffle the current deck.
	Copy the deck into an array and shuffle the array.
	Copy the array back into the deck.
*/
void Deck::shuffleDeck() {
	if (size <= 1) { return; }
	for (int i = 0; i<size; i++) {
		int index = rand() % size;
		Card temp = cardArr[i];
		cardArr[i] = cardArr[index];
		cardArr[index] = temp;
	}
}

Card Deck::draw() {
	if (size <= 0) { this->newDeck(); } // No cards to draw, build a new deck.
	size--;
	return Card(cardArr[size]);
}

#endif