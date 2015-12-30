#include "building.h"
#include "board.h"

using namespace std;


Building::Building(int index, std::string buildingName, int cost, Board* gb) :
	Square(index, buildingName),
	cost(cost),
	owner(),
	gb(gb) {}

void Building::setOwner(Player * owner) {
	this->owner = owner;
	notifyImprov();
}

Player * Building::getOwner() {
	return owner;
}

int Building::getCost() {
	return cost;
}

int Building::getFees() {
	return 0;
}

int Building::checkMortgaged() {
	return Mortgaged;
}

void Building::setMortgage(int i) {
	if (i==-1) {
		if (Mortgaged) {
			Mortgaged = 0;
		}
		else if (!Mortgaged) {
			Mortgaged = 1;
		}
	}
	else {
		Mortgaged = i;
	}
}

void Building::notifyImprov() {
	gb->notifyImprov(index, -1, owner);
}



