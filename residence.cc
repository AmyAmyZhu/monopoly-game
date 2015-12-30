#include "residence.h"
#include "player.h"
using namespace std;

Residence::Residence(int index, std::string buildingName, Board* gb) :
	Building(index, buildingName, 200, gb),
	numRes() {}

void Residence::changeNumRes(int numRes) {
	this->numRes = numRes;
}

int Residence::getFees() {
	if (Mortgaged) {
		return 0;
	}
	if (owner->getRes() == 1) {
		return 25;
	}
	else if (owner->getRes() == 2) {
		return 50;
	}
	else if (owner->getRes() == 3) {
		return 100;
	}
	else {
		return 200;
	}
}

void Residence::setOwner(Player * owner) {
	if (this->owner) {
		this->owner->setRes(-1);
	}
	this->owner = owner;
	this->owner->setRes(1);
}


