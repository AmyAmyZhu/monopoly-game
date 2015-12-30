#ifndef __RESIDENCE_H__
#define __RESIDENCE_H__
#include "building.h"
#include <iostream>
#include <string>

class Residence : public Building {

	int numRes; // the number of residence

public:

	Residence(int index, std::string buildingName, Board* gb); // constructor

	int getFees(); // get fees the other players need to pay

	void setOwner(Player * owner);

	void changeNumRes(int numRes); // change the number of residence

};
#endif



