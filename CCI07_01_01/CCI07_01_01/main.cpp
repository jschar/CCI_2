/*

	7.1: Deck of cards: Design the data structures for a generic deck of cards. Explain how
you would subclass the data structures to implement blackjack.

*/

#include <iostream>
#include <list>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iomanip>

#include "Card.hpp"
#include "Hand.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Table.hpp"

using namespace std;

int main(void){

	srand(time(nullptr));

	std::cout << "Welcome to Blackjack." << '\n' << endl;

	Table aTable;

	while(askYN("Play a new game?")){
		aTable.newGame();
		do{
			aTable.playRound();
		} while (askYN("Play another round?"));
	}

	std::cout << "End of line." << endl;
	std::cin.ignore();
	return 0;
}