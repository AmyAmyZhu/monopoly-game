#include "acedemic.h"
#include "board.h"

using namespace std;

AcademicBuilding::AcademicBuilding(int index, std::string monopoly, std::string buildingName,
	int cost, int improvCost, int level0, int level1, int level2, int level3, int level4, int level5, Board *gb) :
	Building(index, buildingName, cost, gb),
	monopoly(monopoly),
	improv(0),
	improvCost(improvCost) {
	improvFees[0] = level0;
	improvFees[1] = level1;
	improvFees[2] = level2;
	improvFees[3] = level3;
	improvFees[4] = level4;
	improvFees[5] = level5;
}

int AcademicBuilding::getFees() {
	if (Mortgaged) {
		return 0;
	}
	return improvFees[improv];
}

void AcademicBuilding::changeImprov(int improv) {
	this->improv = improv;
	notifyImprov();
}

int AcademicBuilding::getImprov() {
	return improv;
}
/*
int AcademicBuilding::inImprovFees() {
	return improvFees[getImprov() + 1];
}

int AcademicBuilding::deImprovFees() {
	return improvFees[getImprov()] / 2;
}
*/

void AcademicBuilding::notifyImprov() {
	gb->notifyImprov(index, improv, owner);
}

string AcademicBuilding::getMonopoly() {
	return monopoly;
}

int AcademicBuilding::getImprovCost() {
	return improvCost;
}



