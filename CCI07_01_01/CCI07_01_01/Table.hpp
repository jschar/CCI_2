#pragma once
#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <list>
#include <queue>
#include "Player.hpp"

class Table {
private:
	std::list<Player> playerList;
	Player dealer;
	Deck tableDeck;
	double odds;

public:
	Table();
	void addPlayer();
	void newGame();
	void playRound();
	void processPlayer(Player &inPlayer);
	
};

Table::Table():odds(3.0/2){

}

void Table::addPlayer(){
	std::string npName = "Default";
	int npMoney = 0;
	bool badData = true;

	while(badData){
		std::cout << "Enter player's name: ";
		getline(std::cin,npName);
		//std::cout << std::endl;
		std::cout << "Enter player's money: ";
		std::cin >> npMoney;
		std::cin.ignore(); // FLUSH
		//std::cout << std::endl;
		if(askYN("Is the Player's info correct?")){
			badData = false;
		}
	}
	playerList.push_back(Player(npName,npMoney));
}

void Table::newGame(){
	tableDeck.newDeck();
	while(!playerList.empty()){ playerList.pop_front(); }
	while(askYN("Add player?")){
		this->addPlayer();
	}
}

void Table::playRound(){

	tableDeck.newDeck();

	//List players and money.
	std::cout << "Players at table." << std::endl;
	for(std::list<Player>::iterator it = playerList.begin(); it != playerList.end(); it++){
		std::cout << "Player: " << it->getPlayerName() << ", Money: " << it->getMoney() << std::endl;
	}
	std::cout << std::endl;

	//place bets and add a default hand,.
	for(std::list<Player>::iterator it = playerList.begin(); it != playerList.end(); it++){
		it->addHand(Hand());
		std::cout << it->getPlayerName() << ", place bet: ";
		int pBet = 0;
		std::cin >> pBet;
		pBet = it->deductMoney(pBet);
		it->getPlayerHand().front().setBet(pBet);
	}
	dealer.addHand(Hand());
	
	//Draw first cards for players.
	for(auto it = playerList.begin(); it != playerList.end(); it++){
		it->getPlayerHand().front().addCard(tableDeck.draw());
	}
	//Draw card for dealer.
	dealer.getPlayerHand().front().addCard(tableDeck.draw());

	//Draw second cards for players.
	for (auto it = playerList.begin(); it != playerList.end(); it++) {
		it->getPlayerHand().front().addCard(tableDeck.draw());
	}
	//Draw second card for dealer.
	dealer.getPlayerHand().front().addCard(tableDeck.draw());

	// Show table state.
	std::cout << std::endl;
	//std::cout << "Dealer: "; dealer.getPlayerHand().front().printHand(); std::cout << "." << std::endl;
	std::cout << "Dealer: " << dealer.getPlayerHand().front().getHandCards().begin()->pValue() << " X." << std::endl;
	for( auto itP = playerList.begin(); itP != playerList.end(); itP++ ){
		std::cout << itP->getPlayerName() << ": ";
		for( auto itH = itP->getPlayerHand().begin(); itH != itP->getPlayerHand().end(); itH++ ){
			itH->printHand();
			std::cout << ".";
		}
		std::cout << std::endl;
	}

	///////
	// Play game.
	///////
	//Process players
	for(auto it = playerList.begin(); it != playerList.end(); it++){
		processPlayer(*it);
	}

	//Process dealer.
	while(dealer.getPlayerHand().front().getHandValue() <= 16){
		dealer.getPlayerHand().front().addCard(tableDeck.draw());
	}
	std::cout << "Dealer: "; dealer.getPlayerHand().front().printHand();
	if(dealer.getPlayerHand().front().getHandValue() > 21){ 
		std::cout << " BUST!";
	}
	std::cout << "." << std::endl;

	// Iterate through players.
	for(auto itP = playerList.begin(); itP != playerList.end(); itP++){
		// Iterate through players hands.
		for(auto itH = itP->getPlayerHand().begin(); itH != itP->getPlayerHand().end(); itH++){
			if(dealer.getPlayerHand().front().getHandValue() > 21){ // Dealer busted.
				if(itH->getHandValue() <= 21){
					itP->addMoney(itH->getBet() * odds);
				} else {
					// Player busted too.
				}
			} else if( itH->getHandValue() > dealer.getPlayerHand().front().getHandValue() ){ // Player beat dealer.
				itP->addMoney(itH->getBet() * odds);
			} else if(itH->getHandValue() == dealer.getPlayerHand().front().getHandValue()) { // Push.
				itP->addMoney(itH->getBet());
			} else { 
				// Dealer won
			}
		}
	}
	
	for(auto it = playerList.begin(); it != playerList.end(); it++){
		it->deleteHands();
	}
	dealer.deleteHands();
}

void Table::processPlayer(Player &inPlayer){
	// Iterate through all the players hands.
	for(std::list<Hand>::iterator it = inPlayer.getPlayerHand().begin(); it != inPlayer.getPlayerHand().end(); it++){
		bool stand = false;
		while( it->getHandValue() <= 21 && !stand ){
			std::cout << "Player: " << inPlayer.getPlayerName() << ". Bet: " << it->getBet();
			std::cout << ". Hand: "; it->printHand(); std::cout << "." << std::endl;
			std::cout << "Hit(1), Double Down(2), Stand(3), Split(4): ";
			int choice;
			std::cin >> choice;
			switch(choice){
				case 1: it->addCard(tableDeck.draw()); break;
				case 2: 
					it->addCard(tableDeck.draw());
					it->setBet(inPlayer.deductMoney(it->getBet()) + it->getBet());
					stand = true;
					break;

				case 3: stand = true; break;
				case 4: break;
			};
		}
		std::cout << "Player: " << inPlayer.getPlayerName() << ". Bet: " << it->getBet();
		std::cout << ". Hand: "; it->printHand(); std::cout << ".";

		if(it->getHandValue() > 21){
			std::cout << " BUST!";
		}

		std::cout << std::endl;
	}
}

#endif
