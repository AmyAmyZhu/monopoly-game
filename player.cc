#include "player.h"
using namespace std;

Player::Player(char playerAbb, string playerName, Square * now) :
	playerAbb(playerAbb), playerName(playerName), balance(1500), numRes(), numGym(), DCLineTurn(),
	currentPosition(now) {}

void Player::changePosition(Square *now) {
	currentPosition = now;
}

void Player::setMoney(int money) {
	balance = money;
}

int Player::getBalance() {
	return balance;
}

Square * Player::getPosition() {
	return currentPosition;
}

string Player::getPlayerName() {
	return playerName;
}

char Player::getPlayerAbb() {
	return playerAbb;
}

void Player::setPlayerName(string name) {
	playerName = name;
}

void Player::setPlayerAbb(char abb) {
	playerAbb = abb;
}

int Player::getRes() {
	return numRes;
}
void Player::setRes(int i) {
	numRes += i;
}

int Player::getGym() {
	return numGym;
}

void Player::setGym(int i) {
	numGym += i;
}

int Player::getLineTurn() {
	return DCLineTurn;
}

void Player::subLineTurn() {
	if (DCLineTurn != 0) {
		DCLineTurn--;
	}
	else {
		DCLineTurn = 3;
	}
}

void Player::setLineTurn(int LineTurn) {
	DCLineTurn = LineTurn;
}

int Player::getDice1() {
	return dice1;
}

int Player::getDice2() {
	return dice2;
}

void Player::setDice1(int dice) {
	dice1 = dice;
}

void Player::setDice2(int dice) {
	dice2 = dice;
}



