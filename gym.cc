#include "gym.h"
#include <cstdlib>
#include <ctime>
#include "player.h"

using namespace std;

Gym::Gym(int index, string buildingName, Board* gb) :
	Building(index, buildingName, 150, gb),
	numOwned() {}

int Gym::getFees() {
	if (Mortgaged) {
		return 0;
	}
	srand((unsigned)time(0));
	int dice1 = (rand() % 6 + 1);
	int dice2 = (rand() % 6 + 1);
	if (owner->getGym() == 2) { // if two gyms are owned by a player
		return 10 * (dice1 + dice2);
	}
	else { // if one gym is owned by a player
		return 4 * (dice1 + dice2);
	}
}

void Gym::setNumOwned(int numOwned) {
	this->numOwned = numOwned;
}

void Gym::setOwner(Player * owner) {
	if (this->owner) {
		this->owner->setGym(-1);
	}
	this->owner = owner;
	this->owner->setGym(1);
}


