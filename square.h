#ifndef __SQUARE_H__
#define __SQUARE_H__
#include <iostream>
#include <string>

class Player;

class Square {

protected:
	int index; // stores one of 0-39
	std::string buildingName; // records the name of the square

public:
	Square(int index, std::string buildingName); // constructor
	virtual ~Square(); // virtual dtor

	int getIndex(); // returns the index of the square
	std::string getBuildingName(); // returns the building name
};
#endif


