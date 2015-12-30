#ifndef __ACEDEMIC_H__
#define __ACEDEMIC_H__
#include "building.h"
#include <iostream>
#include <string>

class AcademicBuilding : public Building {

	std::string monopoly; // record the monopoly block

	int improv; // current improvement level
	int improvCost; // improvement cost

	int improvFees[6]; // the array of different level improvement tuition

public:

	AcademicBuilding(int index, std::string monopoly, std::string buildingName, int cost, int improvCost,
		int level0, int level1, int level2, int level3, int level4, int level5, Board* gb); // constructor
	//int inImprovFees(); // fees for increasing improvement level
	//int deImprovFees(); // money back for decreasing improvement level

	int getImprov(); // get the current improvement level
	void changeImprov(int improv); // add or sell the improvement level

	std::string getMonopoly(); // get the monopoly of the academic building
	int getImprovCost();

	int getFees(); // get fees the other players need to pay

	void notifyImprov();

};
#endif


