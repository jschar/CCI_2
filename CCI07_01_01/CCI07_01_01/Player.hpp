#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <list>
#include "Hand.hpp"

class Player {
private:
	std::list<Hand> playerHand;
	int money;
	std::string playerName;

public:

	Player();
	Player(std::string inName, int inMoney);

	std::list<Hand>& getPlayerHand();
	void addHand(Hand inHand);

	void setMoney(int inMoney);
	void addMoney(int inMoney);
	int deductMoney(int rMoney);
	int getMoney();

	void setPlayerName( const std::string& inStr );
	std::string getPlayerName();

	void deleteHands();
};

Player::Player():playerName("Default"), money(0){

}

Player::Player(std::string inName, int inMoney): playerName(inName), money(inMoney){

}

std::list<Hand>& Player::getPlayerHand(){
	return playerHand;
}

void Player::addHand(Hand inHand){
	playerHand.push_back(inHand);
}

void Player::setMoney(int inMoney){
	money = inMoney;
}

void Player::addMoney(int inMoney){
	money += inMoney;
}

/*

	When the player makes a bet remove that much money and return the bet.
	If the player doesn't have enough money to cover the bet, return
	the part of the bet the player can cover.
	bet(500) money(400) -> return 400 money(0)

*/
int Player::deductMoney(int rMoney){
	int rValue = 0;
	if(rMoney <= 0){
		rValue = 0;
	} else if( rMoney <= money ){
		money -= rMoney;
		rValue = rMoney;
	} else {
		rMoney = money;
		money = 0;
		rValue = rMoney;
	}
	return rValue;
}

int Player::getMoney(){
	return money;
}

void Player::setPlayerName(const std::string& inStr){
	playerName = inStr;
}

std::string Player::getPlayerName(){
	return playerName;
}

void Player::deleteHands(){
	playerHand.clear();
}

#endif