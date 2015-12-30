#ifndef __GYM_H__
#define __GYM_H__
#include "building.h"
#include <iostream>
#include <string>

class Gym : public Building {

	int numOwned;

public:
	Gym(int index, std::string buildingName, Board* gb); // constructor

	void setNumOwned(int numOwned); // set the number of gyms are onwed by the player

	void setOwner(Player * owner); // set the number of gyms

	int getFees(); // get fees the other players need to pay
};
#endif


