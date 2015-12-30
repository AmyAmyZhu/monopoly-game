#ifndef __DISPLAY_H__
#define __DISPLAY_H__
#include <iostream>
#include <string>

class BoardDisplay {

	//int numPlayers; // the total number of players

	char playerAbb[6]; // an array to record the player's abbreviation
	int playerLocation[6]; // an array to store players current location

	std::string improvement[40]; // the improvement level of the academic building
	char Owner[40]; // record the academic building owner

public:

	void display(); // print the current map of the game

	BoardDisplay(); // constructor

	void notifyImprov(int index, int numImprov, char owner); // update the new improvements
	void notifyLocation(int index, int where); // update all players
	void notifyPlayer(int index, char abb);

	char getPlayerAbb(int index);
};

#endif

