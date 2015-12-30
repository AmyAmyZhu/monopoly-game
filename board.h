#ifndef __BOARD_H__
#define __BOARD_H__
#include <string>
#include <iostream>

/***************
 0:COLLECT OSAP     1:AL             2:SLC            3:ML          4:TUITION
 5:MKV              6:ECH            7:NEEDLES HALL   8:PAS         9:HH
 10:DC Tims Line    11:RCH           12:PAC           13:DWE        14:CPH
 15:UWP             16:LHI           17:SLC           18:BMH        19:OPT
 20:Goose Nesting   21:EV1           22:NEEDLES HALL  23:EV2        24:EV3
 25:V1              26:PHYS          27:B1            28:CIF        29:B2
 30:GO TO TIMS      31:EIT           32:ESC           33:SLC        34:C2
 35:REV             36:NEEDLES HALL  37:MC            38:COOP FEE   39:DC
 **************/

const int totalSquares = 40;
const int maxPlayers = 6;

class BoardDisplay;
class Square;
class Player;

class Board {

	bool rollable;

	int current; // the current player number
	int numPlayers; // the total number of players in the game

	BoardDisplay * display; // a pointer to display board
	Square * squares[totalSquares]; // a pointer of an array to all squares
	Player * Cups[4];
	Player * players[maxPlayers]; // a pointer of an array to all players
	bool isTesting;
	bool cheating;

    char playerChar[8]; // G, B,...
    
    bool end;
	int numDoubles;


	void addPlayer(); // add one player
	void removePlayer(int index=-1); // remove the current player

	void Bankrupt(int loserIndex, Player * owed = 0);

	void commandCheat();

	int PlayerIndex(); // show the current player's index
	void roll(); // roll and respectly reset dice1 and dice2 
	std::string PlayerBuildingName(); // get the current player's land building name
	void Move(int movements); // add/sub movements for the current player's location

	int getPlayerBalance(); // show the current player's balance
	void changePlayerBalance(Player * who, int changes); // add/sub changes for the current player's balance

	void checkLand(); // check what action will happen in this index
	bool checkMonopoly(std::string monopoly); // check if the player owns monopoly

	void purchLand(Player *Owner); // purchase a building for the player
	int IsBuilding(int index); // check which building is it. 1 is academic building, 2 is residence, 3 is gym

	void commandRoll(); // when the player choose to roll
	void commandImprove(); // to buy or sell an improvement for property
	void commandTrade(); // trade to name that offers give and request receive.

	void DCTimsLine(); // when move to DC tims Line
	void Tuition(); // when move to Tuition: need to pay 10% fees or pay $300
	void SLC(); // when move to SLC: can move forward or backward or get cup
	void NeedlesHall(); // when move to NeedlesHall: can get or lose money or get cup


	int findIndex(std::string property);

	//    void setMortgage(); // set the building mortgaged
	//    int getFees(); // get fees the other players need to pay
	//    void payFees(Player *players); // pay fees to the specific player

	int dice1();
	int dice2();

	void commandMortgage();

	void commandUnmortgage();

	bool checkImproMono(int index);

	void auction(int index);

	void save(std::string filename);

public:

	Board();
	~Board();

	void initPlayers(); // read info from user to initialize the game

	bool load(std::string filename); // load the game saved in <filename>

	void enableTest(); // enable testing mode

	void enableCheating(); // enable cheating mode

	void runTurn(); // run one turn of the game

	void notifyImprov(int ImprovIndex, int numImprov, Player * owner); // notify all improvements

	void notifyLocation(); // notify all player's current location

	void notifyPlayer(); // notify the player's abb
};

#endif

