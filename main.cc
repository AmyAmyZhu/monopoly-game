#include "board.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[]) {
	cout << "*****WELCOME TO THE VIDEO GAME BUILDINGBUYER7000*****" << endl;
	cout << "     -----------------------------------------" << endl;
	cout << "     |                                       |" << endl;
	cout << "     |  ###   ###    ####  ###   ###   ###   |" << endl;
	cout << "     |  #  #  #  #     #  #   # #   # #   #  |" << endl;
	cout << "     |  ####  ####    #   #   # #   # #   #  |" << endl;
	cout << "     |  #   # #   #  #    #   # #   # #   #  |" << endl;
	cout << "     |  ####  ####  #      ###   ###   ###   |" << endl;
	cout << "     |                                       |" << endl;
	cout << "     -----------------------------------------" << endl;
	cout << "*****WELCOME TO THE VIDEO GAME BUILDINGBUYER7000*****" << endl << endl;
	cout << "This game allows 2-6 players..." << endl << endl;
	Board game;
	bool load = false;
    // a loop to check the module
	for (int i = 1; i < argc; i++) {
		string arg = argv[i];
        // checks if its a testing module
		if (arg == "-testing") {
			game.enableTest();
			cout << "Testing Mode Enable." << endl;
		}
        // checks if its a loading module
		if (arg == "-load") {
			string filename = argv[i + 1];
			i++;
			if (!game.load(filename)) {
				cout << "Invalid save file. Program will be terminated." << endl;
				return 233;
			}
			load = true;
			cout << "You have load the saved game with file '" << filename << "'" << endl;
			cout << "Enter any input to continue:" << endl;
			string temp;
			cin >> temp;
		}
		if (arg == "-cheat") {
			game.enableCheating();
			cout << "Cheating Mode Enable." << endl;
		}
	}
    // this is a normal game
	if (!load) {
		game.initPlayers();
	}
	game.runTurn();
}



