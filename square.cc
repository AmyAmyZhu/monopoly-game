#include "square.h"
using namespace std;

Square::Square(int index, std::string buildingName) : index(index), buildingName(buildingName) {}

Square::~Square() {}

int Square::getIndex() {
	return index;
}

string Square::getBuildingName() {
	return buildingName;
}


