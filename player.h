#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "player.h"
#include <string>
#include <iostream>

class Square;

class Player {
	char playerAbb; // record the player's abbreviation
	std::string playerName; // record the player's name
	int balance; // the balance of the player
	int numRes;
	int numGym;
	int DCLineTurn; // 0 for not in line, 1-3 for turns spend in line

	Square * currentPosition; // record the current position of the player

	int dice1; // stores the second dice of the roll
	int dice2; // stores the first dice of the roll

public:
	Player(char playerAbb, std::string playerName, Square * now);

	char getPlayerAbb(); // get the player's abbreviation
	void setPlayerAbb(char abb); // set the player's abbreviation

	std::string getPlayerName(); // get the player's name
	void setPlayerName(std::string name); // set the player's name

	int getBalance(); // get the current balance
	void setMoney(int money); // set the new balance of the player

	Square * getPosition(); // get the current position of the player
	void changePosition(Square *now); // change the position of the player

	int getRes(); // getter for numRes
	void setRes(int); // setter for numRes

	int getGym(); // getter for numGym
	void setGym(int); // setter for numGym

	int getLineTurn(); // getter for DCLineTurn
	void subLineTurn(); // add one to DCLineTurn. reset it to 0 if it is max (3)
	void setLineTurn(int LineTurn);

	int getDice1(); // getter for dice1
	int getDice2(); // setter for dice1

	void setDice1(int dice); // getter for dice2
	void setDice2(int dice); // setter for dice2
};
#endif


