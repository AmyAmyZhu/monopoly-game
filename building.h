#ifndef __BUILDING_H__
#define __BUILDING_H__
#include "square.h"
#include <iostream>
#include <string>

class Board;
class Player;

class Building : public Square {

protected:
	int Mortgaged; // if the building is mortgaged or not
	int cost; // the purchase cost of the building

	Player * owner; // the building owner player
	Board * gb; // current game board

public:
	Building(int, std::string, int, Board*); // constructor

	Player * getOwner(); // get who is the owner of the building
	virtual void setOwner(Player * owner); // set the building owner
	int getCost(); // get the purchase cost of the building

	virtual int getFees(); // get fees the other players need to pay

	int checkMortgaged(); // check if the building is mortgaged or not
	void setMortgage(int i = -1); // set the building to be mortgaged or not mortgaged

	virtual void notifyImprov();
};
#endif



