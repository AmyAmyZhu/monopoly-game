#include "board.h"
#include "display.h"
#include "player.h"
#include "square.h"
#include "acedemic.h"
#include "gym.h"
#include "residence.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>
#include <fstream>
#include <sstream>


/*TODO£º
...
-More Testing on everything!!!!!!!!!!!!!!
-UML
-Documentation
-Final Design
-Possible DLC : house rules && cheat display command && board themes

*/

using namespace std;

Board::Board() : rollable(1), current(), numPlayers(), display(), Cups(), players(), isTesting(), cheating(), playerChar(), end(false){
    playerChar[0]='G'; playerChar[1]='B'; playerChar[2]='D'; playerChar[3]='P'; playerChar[4]='S';
    playerChar[5]='$'; playerChar[6]='L'; playerChar[7]='T'; // initialize characters to be G, B, D, P, S, $, L, T
    display = new BoardDisplay; // create a new display
	//create each block
	squares[0] = new Square(0, "COLLECT OSAP");
	squares[1] = new AcademicBuilding(1, "Arts1", "AL", 40, 50, 2, 10, 30, 90, 160, 250, this);
	squares[2] = new Square(2, "SLC");
	squares[3] = new AcademicBuilding(3, "Arts1", "ML", 60, 50, 4, 20, 60, 180, 320, 450, this);
	squares[4] = new Square(4, "TUITION");
	squares[5] = new Residence(5, "MKV", this);
	squares[6] = new AcademicBuilding(6, "Arts2", "ECH", 100, 50, 6, 30, 90, 270, 400, 550, this);
	squares[7] = new Square(7, "NEEDLES HALL");
	squares[8] = new AcademicBuilding(8, "Arts2", "PAS", 100, 50, 6, 30, 90, 270, 400, 550, this);
	squares[9] = new AcademicBuilding(9, "Arts2", "HH", 120, 50, 8, 40, 100, 300, 450, 600, this);
	squares[10] = new Square(10, "DC Tims Line");
	squares[11] = new AcademicBuilding(11, "Eng", "RCH", 140, 100, 10, 50, 150, 450, 625, 750, this);
	squares[12] = new Gym(12, "PAC", this);
	squares[13] = new AcademicBuilding(13, "Eng", "DWE", 140, 100, 10, 50, 150, 450, 625, 750, this);
	squares[14] = new AcademicBuilding(14, "Eng", "CPH", 160, 100, 12, 60, 180, 500, 700, 900, this);
	squares[15] = new Residence(15, "UWP", this);
	squares[16] = new AcademicBuilding(16, "Health", "LHI", 180, 100, 14, 70, 200, 550, 750, 950, this);
	squares[17] = new Square(17, "SLC");
	squares[18] = new AcademicBuilding(18, "Health", "BMH", 180, 100, 14, 70, 200, 550, 750, 950, this);
	squares[19] = new AcademicBuilding(19, "Health", "OPT", 200, 100, 16, 80, 220, 600, 800, 1000, this);
	squares[20] = new Square(20, "Goose Nesting");
	squares[21] = new AcademicBuilding(21, "Env", "EV1", 220, 150, 18, 90, 250, 700, 875, 1050, this);
	squares[22] = new Square(22, "NEEDLES HALL");
	squares[23] = new AcademicBuilding(23, "Env", "EV2", 220, 150, 18, 90, 250, 700, 875, 1050, this);
	squares[24] = new AcademicBuilding(24, "Env", "EV3", 240, 150, 20, 100, 300, 750, 925, 1100, this);
	squares[25] = new Residence(25, "V1", this);
	squares[26] = new AcademicBuilding(26, "Sci1", "PHYS", 260, 150, 22, 110, 330, 800, 975, 1150, this);
	squares[27] = new AcademicBuilding(27, "Sci1", "B1", 260, 150, 22, 110, 330, 800, 975, 1150, this);
	squares[28] = new Gym(28, "CIF", this);
	squares[29] = new AcademicBuilding(29, "Sci1", "B2", 280, 150, 24, 120, 360, 850, 1025, 1200, this);
	squares[30] = new Square(30, "GO TO TIMS");
	squares[31] = new AcademicBuilding(31, "Sci2", "EIT", 300, 200, 26, 130, 390, 900, 1100, 1275, this);
	squares[32] = new AcademicBuilding(32, "Sci2", "ESC", 300, 200, 26, 130, 390, 900, 1100, 1275, this);
	squares[33] = new Square(33, "SLC");
	squares[34] = new AcademicBuilding(34, "Sci2", "C2", 320, 200, 28, 150, 450, 1000, 1200, 1400, this);
	squares[35] = new Residence(35, "REV", this);
	squares[36] = new Square(36, "NEEDLES HALL");
	squares[37] = new AcademicBuilding(37, "Math", "MC", 350, 200, 35, 175, 500, 1100, 1300, 1500, this);
	squares[38] = new Square(38, "COOP FEE");
	squares[39] = new AcademicBuilding(39, "Math", "DC", 400, 200, 50, 200, 600, 1400, 1700, 2000, this);
}

Board::~Board() {
	delete display; // delete the display
	for (int i = 0; i < numPlayers; i++) { // delete all players
        if(players[i]){
            delete players[i];
        }
	}
	for (int i = 0; i < 4; i++) { // delete the cups
		delete Cups[i];
	}
	for (int i = 0; i < totalSquares; i++) { // delte all squares
		delete squares[i];
	}
}

void Board::initPlayers() {
	cout << "How many players do you want?" << endl; // read in the total number of player the customs want to have
	cin >> numPlayers;
	if (numPlayers >= maxPlayers) {
		numPlayers = maxPlayers;
	}
	if (numPlayers < 2) {
		numPlayers = 2;
	}
	while (current < numPlayers) { // add players one by one
		addPlayer();
	}
}

void Board::addPlayer() {
	char abb;
	string name;
    
    
	cout << "Hello, player" << current + 1 << "! What is your name?" << endl; // NOTE: current start with 0
	cin >> name;
    
    if(name=="bank"){ // NOTE: players can not name as bank
        cout<<"Sorry, you cannot name as bank"<<endl;
        return;
    }
    
    for(int i=0; i<current; i++){ // players cannot have the same name
        if(name==players[i]->getPlayerName()){
            cout<<"Sorry, players cannot use the same name."<<endl; return;
        }
    }
    // players choose only one of the characters as his/her name
    cout << "Hello! " << name << ", please choose one of the following character as your name." << endl;

    for(int i=0; i<8; i++){
        cout<<playerChar[i]<<" ";
    }
    cout<<endl;
    cin >> abb;
    
    bool charExist=false;
    for(int i=0; i<8; i++){ // after the player chose one char, others cannot choose the same one
        if(abb==playerChar[i]){
            playerChar[i]='\0';
            charExist=true;
            
        }
    }
    
    if(!charExist){
        
        cout<<"Sorry, you have to choose one of the above character as your name."<<endl;
        return;
    }
    
	players[current] = new Player(abb, name, squares[0]);
	notifyPlayer(); // notify display the player's Abb
	notifyLocation(); // notify the player's Location
	current++; // here to next player
}

void Board::notifyImprov(int ImprovIndex, int numImprov, Player * owner) {
	display->notifyImprov(ImprovIndex, numImprov, owner->getPlayerAbb());
}

void Board::notifyLocation() {
	display->notifyLocation(current, PlayerIndex());
}

void Board::notifyPlayer() {
	display->notifyPlayer(current, players[current]->getPlayerAbb());
}

/*********** runTurn *********
 check commands for all players
 *****************************/
void Board::runTurn() {
	current = 0;
	while (current < numPlayers) { // take actions for all players, one by one
		cout << numPlayers << endl;
		display->display();
		numDoubles = 0;
		string command;
		cout << players[current]->getPlayerName() << ", What action do you want to take?" << endl << endl;
        cout<<"You can choose the following commands:"<<endl<<endl;
        cout<<"roll: moves the sum of two dices."<<endl;
        cout<<"next: give the control to the next player"<<endl;
        cout<<"trade <name> <give> <receive>: trade to name that offers give and request receive."<<endl;
        cout<<"improve <property> buy/sell: to buy or sell an improvement for property."<<endl;
        cout<<"mortgage <property>: to mortgage property."<<endl;
        cout<<"unmortgage <property>: to unmortgage property."<<endl;
        cout<<"bankrupt: player declares bankruptcy."<<endl;
        cout<<"assets: displays the assets of the current player."<<endl;
        cout<<"save <filename>: saves the current state of the game."<<endl<<endl;
        
		while ((cin >> command)) { // contiously read in command
			if (command == "next") {
				if (!rollable) {
					break;
				}
				else {
					cout << "You have to end your trun after finishing rolling. Please call roll command." << endl;
				}
			}
			if (command == "assets") { // display the assets: mortgaged building, owned building, current balance
				cout << players[current]->getPlayerName() << ", your current balance is: $" << getPlayerBalance() << endl;
				cout << "You have the following assests:" << endl;
				for (int i = 0; i < 40; i++) {
					if (IsBuilding(i) < 4) {
						if (dynamic_cast<Building*>(squares[i])->getOwner() == players[current]) {
							cout << squares[i]->getBuildingName();
							if (dynamic_cast<Building*>(squares[i])->checkMortgaged()) {
								cout << " Mortgaged";
							}
							cout << endl;
						}
					}
				}
			}
			if (command == "improve") { // improve owned academic building
				commandImprove();
			}
			if (command == "roll") { // roll dices
				if (!rollable) { // if already rolled
					cout << "Already Rolled." << endl;
				}
				else if (players[current]->getLineTurn()) {
					DCTimsLine();
                    if(end) return;
				}
				else {
					commandRoll();
                    if(end) return;
				}
			}
            if(command == "trade"){ // can trade property with others
                commandTrade();
                if(end) return;
            }
            
			if (command == "mortgage") { // can mortgage the property
				commandMortgage();
			}
			if (command == "unmortgage") { // to unmortgage the property
				commandUnmortgage();
			}
			if (command == "quit") { // end the game
				cout << "Received quit command. The game is ended with no result." << endl;
				return;
			}
			if (command == "board") { // to display the game
				display->display();
			}
			if (command == "save") { // save file
				string filename;
				cin >> filename;
				save(filename);
				cout << "Saved successfully!" << endl;
			}
			if (command == "cheat") {
				if (cheating) {
					commandCheat();
				}
			}
			if (command == "TestingEnable") {
				isTesting = true;
			}
			if (command == "DisableTesting") {
				isTesting = false;
			}
		}
        if(end){ // if all bankrupt, only one player left, end the game
            cout<<"This is the end of the game!"<<endl;
            return;
        }
        
		current++;
		rollable = true;
	}
	runTurn(); // this is a recursively method to run turns all the time
}

void Board::Move(int movements) {
	// check if this move is free:
	if (dice1() == dice2()) {
		numDoubles++;
		if (rollable) {
			cout << "(Note you have rolled a doubles, you can roll again after this event)" << endl;
		}
	}
	else {
		rollable = false;
	}
	if (numDoubles == 3) {
		cout << "You have rolled 3 doubles. You would be moved to DC Tims Line." << endl;
		players[current]->changePosition(squares[10]);
		players[current]->subLineTurn();
		notifyLocation();
	}
	players[current]->changePosition(squares[players[current]->getPosition()->getIndex() + movements]);
	notifyLocation(); // notify the current location
	display->display();
	checkLand(); // after moved, have to check which land is it
    if(end) return;
}

int Board::PlayerIndex() {
	return players[current]->getPosition()->getIndex();
}

void Board::roll() {
	if (isTesting) {
		int d1=1, d2=1;
		cin >> d1 >> d2;
		if (d1 < 1 || d1>6 || d2 < 1 || d2>6) {
			cout << "Invalid dices. Please re-enter two digits. (digits only)" << endl;
			roll();
			return;
		}
		players[current]->setDice1(d1);
		players[current]->setDice2(d2);
	}
	else {
		srand((unsigned)time(0));
		players[current]->setDice1(rand() % 6 + 1);
		players[current]->setDice2(rand() % 6 + 1);
	}
	cout << "You rolled " << dice1() << " and " << dice2() << "." << endl;
}

void Board::commandTrade(){
    string name;
    string give;
    string receive;
    
    cin>>name;
    cin>>give;
    cin>>receive;

    bool giveInt=false; bool receiveInt=false;
    
    int giveMoney;
    istringstream s(give);
    
    if(s>>giveMoney){
        giveInt=true;
    }
    
    int receiveMoney;
    istringstream ss(receive);
    if(ss >> receiveMoney){
        receiveInt=true;
    }
    
    if(name==players[current]->getPlayerName()){
        cout<<"Sorry, you cannot trade with yourself"<<endl; return;
    }else{
        int tradeWith=10; // another player's index
        for(int i=0; i<numPlayers; i++){
            if(name==players[i]->getPlayerName()){
                tradeWith=i;
            }
        }
        if(tradeWith==10){
            cout<<"Sorry, people you are trading with is not exist."<<endl; return;
        }else if((giveInt)&&(receiveInt)){
            cout<<"Sorry, you cannot trade money with money."<<endl; return;
        }
        
        if(giveInt){ // give is money, receive is a property
            int receiveIndex=41;
            for(int i=0; i<totalSquares; i++){
                if(squares[i]->getBuildingName()==receive){
                    receiveIndex=squares[i]->getIndex();
                }
            }
            
            if(IsBuilding(receiveIndex)==1){
                if(checkImproMono(receiveIndex)){
                    cout<<players[tradeWith]->getPlayerName()<< ", do you want to give "<<receive<<" to receive "<<give<<endl;
                    cout<<"1. accept"<<endl;
                    cout<<"2. reject"<<endl;
                    string option;
                    cin>>option;
                    if(option=="1"||option=="accept"){
                        if(players[current]->getBalance() < giveMoney){
                            Bankrupt(current);
                            return;
                        }else{
                            changePlayerBalance(players[current], -giveMoney);
                            changePlayerBalance(players[tradeWith], giveMoney);
                            dynamic_cast<Building *>(squares[receiveIndex])->setOwner(players[current]);
                            cout<<"You give "<<give<<" to "<<name<<" to receive "<<receive<<endl;
                            cout << "Your current balance is $" << getPlayerBalance() << endl;
                            cout << name <<" current balance is $" << players[tradeWith]->getBalance()<< endl;
                        }
                    } else {
                        cout<<players[tradeWith]->getPlayerName()<< " reject this trade."<<endl;
                        return;
                    }
                }else{
                    cout<<"Sorry, you cannot trade this property."<<endl; return;
                }
            }else if((IsBuilding(receiveIndex)==2)||(IsBuilding(receiveIndex)==3)){
                cout<<players[tradeWith]->getPlayerName()<< ", do you want to give "<<receive<<" to receive "<<give<<endl;
                cout<<"1. accept"<<endl;
                cout<<"2. reject"<<endl;
                string option;
                cin>>option;
                if(option=="1"||option=="accept"){
                    if(players[current]->getBalance() < giveMoney){
                        Bankrupt(current);
                        return;
                    }else{
                        changePlayerBalance(players[current], -giveMoney);
                        changePlayerBalance(players[tradeWith], giveMoney);
                        dynamic_cast<Building *>(squares[receiveIndex])->setOwner(players[current]);
                        cout<<"You give "<<give<<" to "<<name<<" to receive "<<receive<<endl;
                        cout << "Your current balance is $" << getPlayerBalance() << endl;
                        cout << name <<" current balance is $" << players[tradeWith]->getBalance()<< endl;
                    }
                } else {
                    cout<<players[tradeWith]->getPlayerName()<< " reject this trade."<<endl;
                    return;
                }
            } else{
                cout<<"Sorry, you can only trade academic buildings, residences, or gyms."<<endl; return;
            }
        
            
            
            
        } else if(receiveInt){ // give is a property, receive is money
            int giveIndex=41;
            for(int i=0; i<totalSquares; i++){
                if(squares[i]->getBuildingName()==give){
                    giveIndex=squares[i]->getIndex();
                }
            }
            if(IsBuilding(giveIndex)==1){
                if(checkImproMono(giveIndex)){
                    cout<<players[tradeWith]->getPlayerName()<< ", do you want to give "<<receive<<" to receive "<<give<<endl;
                    cout<<"1. accept"<<endl;
                    cout<<"2. reject"<<endl;
                    string option;
                    cin>>option;
                    if(option=="1"||option=="accept"){
                        if(players[tradeWith]->getBalance() < giveMoney){
                            Bankrupt(tradeWith);
                            return;
                        }else{
                            changePlayerBalance(players[current], receiveMoney);
                            changePlayerBalance(players[tradeWith], -receiveMoney);
                            dynamic_cast<Building *>(squares[giveIndex])->setOwner(players[tradeWith]);
                            cout<<"You give "<<give<<" to "<<name<<" to receive "<<receive<<endl;
                            cout << "Your current balance is $" << getPlayerBalance() << endl;
                            cout << name <<" current balance is $" << players[tradeWith]->getBalance()<< endl;
                        }
                    } else {
                        cout<<players[tradeWith]->getPlayerName()<< " reject this trade."<<endl;
                        return;
                    }
                }else{
                    cout<<"Sorry, you cannot trade this property."<<endl; return;
                }
            }else if((IsBuilding(giveIndex)==2)||(IsBuilding(giveIndex)==3)){
                cout<<players[tradeWith]->getPlayerName()<< ", do you want to give "<<receive<<" to receive "<<give<<endl;
                cout<<"1. accept"<<endl;
                cout<<"2. reject"<<endl;
                string option;
                cin>>option;
                if(option=="1"||option=="accept"){
                    if(players[tradeWith]->getBalance() < giveMoney){
                        Bankrupt(tradeWith);
                        return;
                    }else{
                        changePlayerBalance(players[current], receiveMoney);
                        changePlayerBalance(players[tradeWith], -receiveMoney);
                        dynamic_cast<Building *>(squares[giveIndex])->setOwner(players[tradeWith]);
                        cout<<"You give "<<give<<" to "<<name<<" to receive "<<receive<<endl;
                        cout << "Your current balance is $" << getPlayerBalance() << endl;
                        cout << name <<" current balance is $" << players[tradeWith]->getBalance()<< endl;
                    }
                } else {
                    cout<<players[tradeWith]->getPlayerName()<< " reject this trade."<<endl;
                    return;
                }
            }else{
                cout<<"Sorry, you can only trade academic buildings, residences, or gyms."<<endl; return;
            }
            
            
            
            
            
        } else{ // give and receive are both property
            int giveIndex=41;
            for(int i=0; i<totalSquares; i++){
                if(squares[i]->getBuildingName()==receive){
                    giveIndex=squares[i]->getIndex();
                }
            }
            int receiveIndex=41;
            for(int i=0; i<totalSquares; i++){
                if(squares[i]->getBuildingName()==receive){
                    receiveIndex=squares[i]->getIndex();
                }
            }
            if(IsBuilding(giveIndex)==1){
                if(checkImproMono(giveIndex)){
                    if(IsBuilding(receiveIndex)==1){
                    if(checkImproMono(receiveIndex)){
                        cout<<players[tradeWith]->getPlayerName()<< ", do you want to give "<<receive<<" to receive "<<give<<endl;
                        cout<<"1. accept"<<endl;
                        cout<<"2. reject"<<endl;
                        string option;
                        cin>>option;
                        if(option=="1"||option=="accept"){
                    cout<<"You give "<<give<<" to "<<name<<" to receive "<<receive<<endl;
                    dynamic_cast<Building *>(squares[giveIndex])->setOwner(players[tradeWith]);
                    dynamic_cast<Building *>(squares[receiveIndex])->setOwner(players[current]);
                    } else {
                        cout<<players[tradeWith]->getPlayerName()<< " reject this trade."<<endl;
                        return;
                    }
                    
                    }else{
                        cout<<"Sorry, you cannot trade "<<receive<<endl; return;
                    }
                    }else if((IsBuilding(receiveIndex)==2)||(IsBuilding(receiveIndex)==3)){
                        cout<<players[tradeWith]->getPlayerName()<< ", do you want to give "<<receive<<" to receive "<<give<<endl;
                        cout<<"1. accept"<<endl;
                        cout<<"2. reject"<<endl;
                        string option;
                        cin>>option;
                        if(option=="1"||option=="accept"){
                    cout<<"You give "<<give<<" to "<<name<<" to receive "<<receive<<endl;
                    dynamic_cast<Building *>(squares[giveIndex])->setOwner(players[tradeWith]);
                    dynamic_cast<Building *>(squares[receiveIndex])->setOwner(players[current]);
                        } else {
                            cout<<players[tradeWith]->getPlayerName()<< " reject this trade."<<endl;
                            return;
                        }

                }else{
                    cout<<"Sorry, receive is not one of academic buildings, residences, or gyms."<<endl; return;
                }
                }else{
                    cout<<"Sorry, you cannot trade "<<give<<endl; return;
                }
            }else if((IsBuilding(giveIndex)==2)||(IsBuilding(giveIndex)==3)){
                if(IsBuilding(receiveIndex)==1){
                    if(checkImproMono(receiveIndex)){
                        cout<<players[tradeWith]->getPlayerName()<< ", do you want to give "<<receive<<" to receive "<<give<<endl;
                        cout<<"1. accept"<<endl;
                        cout<<"2. reject"<<endl;
                        string option;
                        cin>>option;
                        if(option=="1"||option=="accept"){
                    cout<<"You give "<<give<<" to "<<name<<" to receive "<<receive<<endl;
                    dynamic_cast<Building *>(squares[giveIndex])->setOwner(players[tradeWith]);
                    dynamic_cast<Building *>(squares[receiveIndex])->setOwner(players[current]);
                        } else {
                            cout<<players[tradeWith]->getPlayerName()<< " reject this trade."<<endl;
                            return;
                        }
                    }else{
                        cout<<"Sorry, you cannot trade "<<receive<<endl; return;
                    }
                }else if((IsBuilding(receiveIndex)==2)||(IsBuilding(receiveIndex)==3)){
                    cout<<players[tradeWith]->getPlayerName()<< ", do you want to give "<<receive<<" to receive "<<give<<endl;
                    cout<<"1. accept"<<endl;
                    cout<<"2. reject"<<endl;
                    string option;
                    cin>>option;
                    if(option=="1"||option=="accept"){
                    cout<<"You give "<<give<<" to "<<name<<" to receive "<<receive<<endl;
                    dynamic_cast<Building *>(squares[giveIndex])->setOwner(players[tradeWith]);
                    dynamic_cast<Building *>(squares[receiveIndex])->setOwner(players[current]);
                    } else {
                        cout<<players[tradeWith]->getPlayerName()<< " reject this trade."<<endl;
                        return;
                    }
                }else{
                    cout<<"Sorry, receive is not one of academic buildings, residences, or gyms."<<endl; return;
                }
            }else{
                cout<<"Sorry, give is not one of academic buildings, residences, or gyms."<<endl; return;
            }
        }
    }
}

void Board::commandRoll() {
	roll();
	int totalMove = dice1() + dice2();
	cout << players[current]->getPlayerName() << ", please move " << dice1() << " + " << dice2() << " = " << totalMove << " moves " << endl;

	// change the player's current position to the moved position
	if (totalMove + PlayerIndex() > 39) { // when the player run one round
		Move(totalMove - totalSquares);
        if(end) return;
		cout << "Collect OSAP $200!" << endl;
		changePlayerBalance(players[current], 200);
		cout << "Your current balance is $" << getPlayerBalance() << endl;
	}
	else {
		Move(totalMove);
        if(end) return;
	}
}

int Board::findIndex(string property) {
	int index = 0; // find the index of the property
	for (int i = 0; i <= 39; i++) {
		if (squares[i]->getBuildingName() == property) {
			index = i;
		}
	}
	return index;
}

void Board::commandImprove() {
	string property;
	string todo; // one of "buy" or "sell"
	cin >> property;
	cin >> todo;

	if (IsBuilding(findIndex(property)) != 1) {
		cout << "Sorry, this is not an academic building. You cannot improve it." << endl;
	}
	else if (dynamic_cast<Building *>(squares[findIndex(property)])->getOwner() != players[current]) {
		cout << "Sorry, you cannot improve this property since you do not own it" << endl;
	}
	else if (!checkMonopoly(dynamic_cast<AcademicBuilding *>(squares[findIndex(property)])->getMonopoly())) {
		cout << "Sorry, you do not own monopoly for " << property << ". You cannot improve." << endl;
	}
	else {
		if (todo == "buy") {
			if (dynamic_cast<AcademicBuilding *>(squares[findIndex(property)])->getImprov() + 1 > 5) {
				cout << "Now it's level 5. Sorry, you cannot increase the improvement level." << endl;
			}
			else {
				cout << players[current]->getPlayerName() << ", increase the improvement of the current position to be level ";
				cout << dynamic_cast<AcademicBuilding *>(squares[findIndex(property)])->getImprov() + 1 << "." << endl;
				cout << "You paid $" << dynamic_cast<AcademicBuilding *>(squares[findIndex(property)])->getImprovCost() << "." << endl;
				changePlayerBalance(players[current], dynamic_cast<AcademicBuilding *>(squares[findIndex(property)])->getImprovCost()*(-1));
				cout << "Your current balance is: $" << getPlayerBalance() << endl;
				dynamic_cast<AcademicBuilding *>(squares[findIndex(property)])->changeImprov(dynamic_cast<AcademicBuilding *>(squares[findIndex(property)])->getImprov() + 1);
			}
		}
		else {
			if (dynamic_cast<AcademicBuilding *>(squares[findIndex(property)])->getImprov() - 1 < 0) {
				cout << "Now it's level 0. Sorry, you cannot decrease the improvement level" << endl;
			}
			else {
				cout << players[current]->getPlayerName() << ", decrease the improvement of the current position to be level ";
				cout << dynamic_cast<AcademicBuilding *>(squares[findIndex(property)])->getImprov() - 1 << "." << endl;
				cout << "You get $" << (dynamic_cast<AcademicBuilding *>(squares[findIndex(property)])->getImprovCost()) / 2 << "." << endl;
				changePlayerBalance(players[current], dynamic_cast<AcademicBuilding *>(squares[findIndex(property)])->getImprovCost()*(1 / 2));
				cout << "Your current balance is: $" << getPlayerBalance() << endl;
				dynamic_cast<AcademicBuilding *>(squares[findIndex(property)])->changeImprov(dynamic_cast<AcademicBuilding *>(squares[findIndex(property)])->getImprov() - 1);
			}
		}
	}
}

bool Board::checkMonopoly(string monology) {
	if (monology == "Arts1") {
		if (dynamic_cast<Building *>(squares[1])->getOwner() == dynamic_cast<Building *>(squares[3])->getOwner() &&
			(dynamic_cast<Building *>(squares[1])->getOwner() != NULL)) {
			return true;
		}
	}
	else if (monology == "Arts2") {
		if ((dynamic_cast<Building *>(squares[6])->getOwner() == dynamic_cast<Building *>(squares[8])->getOwner()) &&
			(dynamic_cast<Building *>(squares[8])->getOwner() == dynamic_cast<Building *>(squares[9])->getOwner()) &&
			(dynamic_cast<Building *>(squares[6])->getOwner() != NULL)) {
			return true;
		}
	}
	else if (monology == "Eng") {
		if ((dynamic_cast<Building *>(squares[11])->getOwner() == dynamic_cast<Building *>(squares[13])->getOwner()) &&
			(dynamic_cast<Building *>(squares[13])->getOwner() == dynamic_cast<Building *>(squares[14])->getOwner()) &&
			(dynamic_cast<Building *>(squares[11])->getOwner() != NULL)) {
			return true;
		}
	}
	else if (monology == "Health") {
		if ((dynamic_cast<Building *>(squares[16])->getOwner() == dynamic_cast<Building *>(squares[18])->getOwner()) &&
			(dynamic_cast<Building *>(squares[18])->getOwner() == dynamic_cast<Building *>(squares[19])->getOwner()) &&
			(dynamic_cast<Building *>(squares[16])->getOwner() != NULL)) {
			return true;
		}
	}
	else if (monology == "Env") {
		if ((dynamic_cast<Building *>(squares[21])->getOwner() == dynamic_cast<Building *>(squares[23])->getOwner()) &&
			(dynamic_cast<Building *>(squares[23])->getOwner() == dynamic_cast<Building *>(squares[24])->getOwner()) &&
			(dynamic_cast<Building *>(squares[21])->getOwner() != NULL)) {
			return true;
		}
	}
	else if (monology == "Sci1") {
		if ((dynamic_cast<Building *>(squares[26])->getOwner() == dynamic_cast<Building *>(squares[27])->getOwner())
			&& (dynamic_cast<Building *>(squares[27])->getOwner() == dynamic_cast<Building *>(squares[29])->getOwner()) &&
			(dynamic_cast<Building *>(squares[26])->getOwner() != NULL)) {
			return true;
		}
	}
	else if (monology == "Sci2") {
		if ((dynamic_cast<Building *>(squares[31])->getOwner() == dynamic_cast<Building *>(squares[31])->getOwner()) &&
			(dynamic_cast<Building *>(squares[32])->getOwner() == dynamic_cast<Building *>(squares[34])->getOwner()) &&
			(dynamic_cast<Building *>(squares[31])->getOwner() != NULL)) {
			return true;
		}
	}
	else if (monology == "Math") {
		if (dynamic_cast<Building *>(squares[37])->getOwner() == dynamic_cast<Building *>(squares[39])->getOwner() &&
			(dynamic_cast<Building *>(squares[37])->getOwner() != NULL)) {
			return true;
		}
	}
	return false;
}

void Board::purchLand(Player *Owner) {
	cout << "You are now land at " << PlayerBuildingName() << endl;
	if (dynamic_cast<Building *>(squares[PlayerIndex()])->getOwner() != NULL) {
		cout << "Sorry, this land already have an owner" << endl;
		return;
	}
	if ((IsBuilding(PlayerIndex()) == 1) || (IsBuilding(PlayerIndex()) == 2) || (IsBuilding(PlayerIndex()) == 3)) {
        if (players[current] == dynamic_cast<Building *>(squares[PlayerIndex()])->getOwner()) {
			cout << PlayerBuildingName() << " is your property" << endl;
		}
		else {
			cout << "Do you want to buy this property?" << endl;
			cout << "1. Yes" << endl;
			cout << "2. No" << endl;
			string todo;
			cin >> todo;
			if ((todo == "1") || (todo == "Yes")) {
                if(getPlayerBalance() < dynamic_cast<Building *>(Owner->getPosition())->getCost()){
                    Bankrupt(current);
                    if(end) return;
                }else{
                    dynamic_cast<Building *>(Owner->getPosition())->setOwner(Owner);  // set the Owner
                    Owner->setMoney(Owner->getBalance() - dynamic_cast<Building *>(Owner->getPosition())->getCost());
                    cout << "Now, you have that property." << endl;
                    cout << "Your current balance is $"<<getPlayerBalance()<<endl;
                }
            }else if((todo == "2") || (todo == "No")) {
                auction(PlayerIndex());  if(end) return;
            }else{
                cout<<"Sorry, you have to choose 1 or 2 above."<<endl;
                return;
            }
		}
	}
}

/****************** checkLand **********
 when arrived in one block, pay fees
 ***************************************/
void Board::checkLand() {
	if (PlayerIndex() == 10 || PlayerIndex() == 0) {
		return;
	}
	if (PlayerIndex() == 30) {
		players[current]->changePosition(squares[10]);
		players[current]->subLineTurn();
		notifyLocation();
		cout << "You have been moved to DC Tims Line. Enjoy it!" << endl;
	} // Go to tims
	else if (PlayerIndex() == 20) { cout << "You are attacked by a flock of nesting geese!" << endl; } // Goose Nesting
	else if (PlayerIndex() == 4) { Tuition(); if(end) return; } // Tuition
    else if ((PlayerIndex() == 2) || (PlayerIndex() == 17) || (PlayerIndex() == 33)) { SLC(); if(end) return; } // SLC
	else if ((PlayerIndex() == 7) || (PlayerIndex() == 22) || (PlayerIndex() == 36)) { NeedlesHall(); if(end) return; } // Needles Hall
	else if (PlayerIndex() == 38) { // Coop Fee
		cout << "Please pay $150 to the School as coop fees." << endl;
        if(getPlayerBalance()<150){
            Bankrupt(current); if(end) return;
        }else{
            changePlayerBalance(players[current], -150);
            cout << "Your current balance is: $" << getPlayerBalance() << endl;
        }
	}
	else if ((IsBuilding(PlayerIndex()) == 2) || (IsBuilding(PlayerIndex()) == 3)) { // res or gym
		if (dynamic_cast<Building *>(squares[PlayerIndex()])->getOwner() == NULL) {
			purchLand(players[current]);
            if(end) return;
		}
		else {
            if(dynamic_cast<Building *>(squares[PlayerIndex()])->getOwner() == players[current]){
                cout << "This is your property. Nothing happens." << endl;
            } else {
                cout << "Please pay $" << dynamic_cast<Building *>(squares[PlayerIndex()])->getFees() << endl;
                if(getPlayerBalance()<dynamic_cast<Building * > (squares[PlayerIndex()])->getFees()){
                    Bankrupt(current,dynamic_cast<Building*>(squares[PlayerIndex()])->getOwner()); if(end) return;
                }else{
                    changePlayerBalance(players[current], dynamic_cast<Building *>(squares[PlayerIndex()])->getFees()*(-1));
                    changePlayerBalance(dynamic_cast<Building *>(squares[PlayerIndex()])->getOwner(),
                                        dynamic_cast<Building *>(squares[PlayerIndex()])->getFees());
                    cout << "Your current balance is: $" << getPlayerBalance() << endl;
                }
            }
        }
    }
	
    else if (IsBuilding(PlayerIndex()) == 1) {
        if (dynamic_cast<Building *>(squares[PlayerIndex()])->getOwner() == NULL) {
			purchLand(players[current]);
            if(end) return;
		}
		else {
            if(dynamic_cast<Building *>(squares[PlayerIndex()])->getOwner() == players[current]){
                cout << "This is your property. Nothing happens." << endl;
            }
            else if (checkMonopoly(dynamic_cast<AcademicBuilding *>(squares[PlayerIndex()])->getMonopoly())) {
                cout << "This is a monopoly land, please pay twice of fees to ";
                if(getPlayerBalance() < dynamic_cast<Building *>(squares[PlayerIndex()])->getFees()*2){
                    Bankrupt(current,dynamic_cast<Building*>(squares[PlayerIndex()])->getOwner()); if(end) return;
                }else{
                    cout << dynamic_cast<AcademicBuilding *>(squares[PlayerIndex()])->getOwner()->getPlayerName() << endl;
                    changePlayerBalance(players[current], dynamic_cast<Building *>(squares[PlayerIndex()])->getFees()*(-2));
                    changePlayerBalance(dynamic_cast<Building *>(squares[PlayerIndex()])->getOwner(),
                                        dynamic_cast<Building *>(squares[PlayerIndex()])->getFees() * 2);
                }
			}
			else {
				cout << "Please pay $" << dynamic_cast<Building *>(squares[PlayerIndex()])->getFees() << endl;
                if(getPlayerBalance() < dynamic_cast<Building *>(squares[PlayerIndex()])->getFees()){
                    Bankrupt(current, dynamic_cast<Building*>(squares[PlayerIndex()])->getOwner()); if(end) return;
                }else{
                    changePlayerBalance(players[current], dynamic_cast<Building *>(squares[PlayerIndex()])->getFees()*(-1));
                    changePlayerBalance(dynamic_cast<Building *>(squares[PlayerIndex()])->getOwner(),
                                        dynamic_cast<Building *>(squares[PlayerIndex()])->getFees());
                    cout << "Your current balance is: $" << getPlayerBalance() << endl;
                }
			}
		}
	}
}

void Board::DCTimsLine() {
	int cupNum = -1; // cupNum is: -1 if holding no cup; 1-4 the index of the cup the player is holding
	for (int i = 0; i < 4; i++) {
		if (players[current] == Cups[i]) {
			cupNum = i;
		}
	}
	cout << "Please enter the following commands to decide that how you would leave DC Tims Line." << endl;
	if (players[current]->getLineTurn() && rollable) {
		cout << "-r: Roll doubles. You have " << players[current]->getLineTurn() << " turns to roll." << endl;
		if (isTesting) {
			cout << "Notice Testing mode enable. Please enter two digits after '-r'" << endl;
		}
	}
	//if (players[current]->getBalance() > 50) {
	cout << "-p: Pay $50" << endl;
	cout << "Your current balance is: $" << getPlayerBalance() << endl;
	//}
	if (cupNum != -1) {
		cout << "-c: Use a Roll Up the Rim cup." << endl;
	}
	string option;
	cin >> option;
	cout << option;
	if (option == "-r"&&players[current]->getLineTurn() && rollable) {
		roll();
		rollable = false;
		if (dice1() == dice2()) {
			cout << "Congratulations! you have gotten your coffee!" << endl;
			players[current]->setLineTurn(0);
			rollable = false;
			Move(dice1() + dice2());
            if(end) return;
		}
		else {
			cout << "Oops. Try next time." << endl;
			players[current]->subLineTurn();
			if (!players[current]->getLineTurn()) {
				cout << "you have failed to roll doubles 3 turns!" << endl;
                DCTimsLine(); if(end) return;
			}
		}
	}
	else if (option == "-p"/*&&players[current]->getBalance() > 50*/) {
        if(getPlayerBalance()<50){
            Bankrupt(current); if(end) return;
        }else{
            changePlayerBalance(players[current], -50);
            cout << "Your current balance is: $" << getPlayerBalance() << endl;
        }
	}
	else if (option == "-c"&&cupNum != -1) {
		cout << "You have used one Roll Up the Rim cup" << endl;
		delete Cups[cupNum];
	}
}



void Board::Tuition() {
	cout << "please pay $300 tuition or 10% of your total worth." << endl;
	cout << "1. pay $300" << endl;
	cout << "2. pay 10% of my total worth" << endl;
	string option;
	cin >> option;
	if ((option == "1") || (option == "pay $300")) {
        if(getPlayerBalance()<300){
            Bankrupt(current); if(end) return;
        }else{
            changePlayerBalance(players[current], -300);
            cout << "Your current balance is: $" << getPlayerBalance() << endl;
        }
	}
	else if ((option == "2") || (option == "pay 10% of my total worth")) {
        if(getPlayerBalance() < players[current]->getBalance()*0.9){
            Bankrupt(current); if(end) return;
        }else{
            players[current]->setMoney(players[current]->getBalance()*0.9);
            cout << "Your current balance is: $" << getPlayerBalance() << endl;
        }
	}
}

void Board::SLC() {
	cout << "You are now at SLC" << endl;
	srand((unsigned)time(0));
	int rollUp = rand() % 100 + 1;
	if (rollUp == 1) { // get the 1% rollUp card
		cout << "Congrajulations! you got the roll Up card!" << endl;
		bool full = true; // check if the Cup is full or not
		for (int i = 0; i < 4; i++) {
			if (Cups[i] == NULL) {
				Cups[i] = players[current];
				full = false;
				break;
			}
		}
		if (full) {
			cout << "Sorry, cant offer you a roll Up cup since we have 4 cups already!" << endl;
			cout << "roll dices again for you." << endl;
            SLC(); if (end) return;
		}
	}
	else { // else gain or lose some amount of savings by probability
		int random = rand() % 18 + 1;
		if (random == 1) {
			cout << "You are moving back 3" << endl;
			if (PlayerIndex() == 2) {
                Move(37); if(end){ return;}
			}
			else {
				Move(-3); if(end){ return;}
			}
		}
		else if ((random >= 2) && (random <= 3)) {
			cout << "You are moving back 2" << endl; Move(-2); if(end){ return;}
		}
		else if ((random >= 4) && (random <= 6)) {
			cout << "You are moving back 1" << endl; Move(-1);if(end){ return;}
		}
		else if ((random >= 7) && (random <= 12)) {
			cout << "You are moving forward 1" << endl; Move(1);if(end){ return;}
		}
		else if ((random >= 13) && (random <= 15)) {
			cout << "You are moving forward 2" << endl; Move(2);if(end){ return;}
		}
		else if ((random >= 16) && (random <= 17)) {
			cout << "You are moving forward 3" << endl; Move(3);if(end){ return;}
		}
		else if (random == 18) {
			players[current]->changePosition(squares[10]);
			notifyLocation();
			players[current]->subLineTurn();
		}
	}
}

void Board::NeedlesHall() {
	cout << "You are now at NeedlesHall" << endl;
	srand((unsigned)time(0));
	int rollUp = rand() % 100 + 1;
	if (rollUp == 1) { // get the 1% rollUp card
		bool full = true; // check if the Cup is full or not
		for (int i = 0; i < 4; i++) {
			if (Cups[i] == NULL) {
				Cups[i] = players[current];
				full = false;
				break;
			}
		}
		if (full) {
			cout << "Sorry, cant offer you a roll Up cup since we have 4 cups already!" << endl;
			cout << "roll dices again for you." << endl;
			NeedlesHall(); if(end) return;
		}
	}
	else { // else gain or lose some amount of savings by probability
		int random = rand() % 18 + 1;
		if (random == 1) {
			cout << "You lost $200" << endl;
            if(getPlayerBalance() < 200){
                Bankrupt(current); if(end) return;
            }else{
                changePlayerBalance(players[current], -200);
            }
		}
		else if ((random >= 2) && (random <= 3)) {
			cout << "You lost $100" << endl;
            if(getPlayerBalance() < 100){
                Bankrupt(current); if(end) return;
            }else{
                changePlayerBalance(players[current], -100);
            }
		}
		else if ((random >= 4) && (random <= 6)) {
			cout << "You lost $50" << endl;
            if(getPlayerBalance() < 50){
                Bankrupt(current); if(end) return;
            }else{
                changePlayerBalance(players[current], -50);
            }
		}
		else if ((random >= 7) && (random <= 12)) {
			cout << "You gain $25" << endl; changePlayerBalance(players[current], 25);
		}
		else if ((random >= 13) && (random <= 15)) {
			cout << "You gain $50" << endl; changePlayerBalance(players[current], 50);
		}
		else if ((random >= 16) && (random <= 17)) {
			cout << "You gain $100" << endl; changePlayerBalance(players[current], 100);
		}
		else if (random == 18) {
			cout << "You gain $200" << endl; changePlayerBalance(players[current], 200);
		}
	}
}

int Board::IsBuilding(int index) {
	if (index != 0 && index != 2 && index != 4 && index != 5 && index != 7 && index != 10 &&
		index != 12 && index != 15 && index != 17 && index != 20 && index != 22 && index != 25 &&
		index != 28 && index != 30 && index != 33 && index != 35 && index != 36 && index != 38) {
		return 1; // if it's a Academic building
	}
	else if (index == 5 || index == 15 || index == 25 || index == 35) {
		return 2; // if it's a Residence
	}
	else if (index == 28 || index == 12) {
		return 3; // if it's a gym
	}
	else {
		return 4; // it's not a building
	}
}

string Board::PlayerBuildingName() {
	return players[current]->getPosition()->getBuildingName();
}

void Board::changePlayerBalance(Player * who, int changes) {
	if ((who->getBalance() + changes) < 0) {
		for (int i = 0; i < numPlayers; i++) {
			if (players[i] == who) {
				Bankrupt(i);
			}
		}
	}
	else {
		who->setMoney(who->getBalance() + changes);
	}
}

int Board::getPlayerBalance() {
	return players[current]->getBalance();
}

void Board::enableTest() {
	isTesting = true;
}

int Board::dice1() {
	return players[current]->getDice1();
}

int Board::dice2() {
	return players[current]->getDice2();
}

void Board::commandMortgage() {
	string property;
	cin >> property;
	int i = findIndex(property);
	Building* b = dynamic_cast<Building*>(squares[i]);
	if (b->getOwner() != players[current]) {
		cout << "Failure: You do not own this property" << endl;
		return;
	}
	if (b->checkMortgaged()) {
		cout << "Failure: Already mortagaged!" << endl;
		return;
	}
	if (IsBuilding(i) == 1) {
		if (!checkImproMono(i)) {
			cout << "Failure: There are improvement(s) on properties in this monopoly!" << endl;
			return;
		}
		else {
			changePlayerBalance(players[current], 0.5*b->getCost());
			b->setMortgage();
		}
	}
	else if (IsBuilding(i) < 3) {
		changePlayerBalance(players[current], 0.5*b->getCost());
		b->setMortgage();
	}
	cout << "successful" << endl;
}

void Board::commandUnmortgage() {
	string property;
	cin >> property;
	int i = findIndex(property);
	Building* b = dynamic_cast<Building*>(squares[i]);
	if (!b->checkMortgaged()) {
		cout << "Failure: This building is not mortagaged!" << endl;
		return;
	}
	if (b->getOwner() != players[current]) {
		cout << "Failure: You do not own this property" << endl;
		return;
	}
	if (IsBuilding(i) < 3) {
		cout << b->checkMortgaged() << endl;
		changePlayerBalance(players[current], -(0.5 + 0.05*b->checkMortgaged())*b->getCost());
		b->setMortgage();
		cout << b->checkMortgaged() << endl;
		cout << "successful!" << endl;
	}
}

bool Board::checkImproMono(int index) {
	string mono = dynamic_cast<AcademicBuilding*>(squares[index])->getMonopoly();
	for (int i = 0; i < 40; i++) {
		if (IsBuilding(i) == 1) {
			if (mono == dynamic_cast<AcademicBuilding*>(squares[i])->getMonopoly()) {
				if (dynamic_cast<AcademicBuilding*>(squares[i])->getImprov()) {
					return false;
				}
			}
		}
	}
	return true;
}

void Board::auction(int index) {
	cout << "A auction has been started on " << squares[index]->getBuildingName() << endl;
	int n = numPlayers; // stores # of players havent withdraw
	int max = 0; // stores the value of current highest bid
	bool bids[maxPlayers]; // stores the bid stutes of all players
    for(int i=0; i<maxPlayers; i++){
        bids[i]=true;
    }
    int winner = numPlayers-1; // stores the index of the players with the highest bid
	int bid; // int to read bid each time
    while(1){
		for (int i = 0; i < numPlayers; i++) {
			// for each unwithdrawed player, a decision and/or bid will be inout to process
			if (bids[i]==true) {
				cout << players[i]->getPlayerName() << ". The current highest bid is " << max << ". Input 'withdraw' to withdraw, anything else to continue :" << endl;
				string d;
				cin >> d;
				if (d == "withdraw") { // withdraw
					bids[i] = !bids[i];
					n--;
                    cout<<"Player "<< i+1<<" withdrawed."<<endl;
				}
				else {
					cout << "Place your bid:" << endl;
					cin >> bid;
					if (bid > max) {
						max = bid;
						winner = i;
						cout << "successful!" << endl;
					}
					else {
						cout << "Failure: You withdrawed with a underbid!"; // withdraw for underbid inputted
						bids[i] = !bids[i];
						n--;
					}
                }
            }
            if (n == 1&&winner != -1) { // do the tansaction
				cout << players[winner]->getPlayerName() << " wins. " << endl;
				changePlayerBalance(players[winner], -max);
				dynamic_cast<Building *>(squares[index])->setOwner(players[winner]);
                cout << players[winner]->getPlayerName() << " pays "<<max<<endl;
                if(players[winner]->getBalance() < max){
                    Bankrupt(current); if(end) return;
                }else{
                    cout<<players[winner]->getPlayerName() <<", your current balance is $"<< players[winner]->getBalance()<<endl;
                    return;
                }
			}
        }
    }
}

void Board::save(string filename) {
	ofstream file(filename.c_str());
	file << numPlayers << endl;
	for (int i = 0; i < numPlayers; i++) {
		file << players[i]->getPlayerName() << " "<< players[i]->getPlayerAbb() << " ";
		int TimsCups = 0;
		for (int j = 0; j < 4; j++) {
			if (Cups[j] == players[i]) {
				TimsCups++;
			}
		}
		file << TimsCups << " " << players[i]->getBalance() << " " << findIndex(players[i]->getPosition()->getBuildingName());
		if (players[i]->getPosition() == squares[10]) {
			if (players[i]->getLineTurn()) {
				file << " 1 " << players[i]->getLineTurn() - 1;
			}
			else {
				file << " 0";
			}
		}
		file << endl;
	}
	for (int i = 0; i < 40; i++) {
		if (IsBuilding(i) < 4) {
			file << squares[i]->getBuildingName() << " ";
			Player* theOwner = dynamic_cast<Building*>(squares[i])->getOwner();
			if (theOwner) {
				file << theOwner->getPlayerName() << " ";
			}
			else {
				file << "BANK ";
			}
			if (dynamic_cast<Building*>(squares[i])->checkMortgaged()) {
				file << -1 << endl;
			}
			else if (IsBuilding(i) ==1) {
				file << dynamic_cast<AcademicBuilding*>(squares[i])->getImprov() << endl;
			}
			else {
				file << 0 << endl;
			}
		}
	}
	file.close();
}


bool Board::load(std::string filename) {
	cout << "e0" << endl;
	ifstream file(filename.c_str());
	file >> numPlayers;
	cout << "e1" << endl;
	for (int i = 0; i < numPlayers; i++) {
		string name;
		char abb;
		int cups;
		int money;
		int position;
		file >> name >> abb >> cups >> money >> position;
		players[i] = new Player(abb, name, squares[position]);
		display->notifyLocation(i, position);
		display->notifyPlayer(i, abb);
		players[i]->setMoney(money);
		int n = 0;
		while (cups) {
			if (!Cups[n]) {
				Cups[n] = players[i];
				cups--;
			}
			n++;
			if (n > 5) {
				return false;
			}
		}
		if (position == 10) {
			int Tims;
			file >> Tims;
			if (Tims) {
				int turn;
				file >> turn;
				players[i]->setLineTurn(turn + 1);
			}
		}
	}
	cout << "e2" << endl;
	for (int i = 0; i < 40; i++) {
		if (IsBuilding(i) < 4) {
			string bname;
			string owner;
			int improv;
			file >> bname >> owner >> improv;
			cout << "e2.4 " << i << endl;
			if (owner != "BANK") {
				for (int j = 0; j < numPlayers; j++) {
					if (players[j]->getPlayerName() == owner) {
						dynamic_cast<Building*>(squares[i])->setOwner(players[j]);
					}
				}
				if (improv == -1) {
					dynamic_cast<Building*>(squares[i])->setMortgage();
				}
			}
			else if (improv == -1) {
				return false;
			}
			cout << "e2.6 " << i << endl;
			if (improv>0) {
				if (IsBuilding(i) != 1) {
					return false;
				}
				dynamic_cast<AcademicBuilding*>(squares[i])->changeImprov(improv);
			}
			cout << "e2.7 " << i << endl;
		}
	}
	cout << "e3" << endl;
	file.close();
	cout << "e4" << endl;
	return true;
}

void Board::removePlayer(int index) {
    if(index==-1){index=current;}
    for(int i=0; i<4; i++){ // destroy all Roll Up the Rim cups owned by this player
        if(Cups[i]==players[index]){
            Cups[i]=NULL;
        }
    }
    delete players[index]; // call destructor of Player
    numPlayers--;
    for(int i=index;i<numPlayers;i++){
        players[i]=players[i+1];
    }
}

void Board::Bankrupt(int loserIndex, Player * owed){
    cout<<"Now you owe more money than they currently possess."<<endl;
    cout<<"Sorry, you are now calling bankrupt."<<endl;
	Player* loser = players[loserIndex]; // note this address will be invalid soon. it should only be used to compare.
	removePlayer(loserIndex);
	if (numPlayers == 1) {
		end = true;
		cout << players[0]->getPlayerName() << " wins the game!!!" << endl;
		return;
	}
    if(owed==NULL){
        for(int i=0; i<totalSquares; i++){
            if(IsBuilding(i)<4){
				Building* b = dynamic_cast<Building *>(squares[i]);
                if(b->getOwner() == loser){
					if (b->checkMortgaged()) {
						b->setMortgage(0);
					}
                    auction(i); if(end) return;
                }
            }
        }
    }else{
        for(int i=0; i<totalSquares; i++){
            if(IsBuilding(i)<4){
				Building* b = dynamic_cast<Building *>(squares[i]);
                if (b->getOwner() == loser){
					if (b->checkMortgaged()) {
						b->setMortgage(-2);
					}
                    b->setOwner(owed);
                    changePlayerBalance(owed, getPlayerBalance());
                    removePlayer(loserIndex);
                    if(numPlayers==1){
                        end=true;
                        cout<<players[0]->getPlayerName()<<" wins the game!!!"<<endl;
                        return;
                    }
                }
            }
        }
		for (int i = 0; i < totalSquares; i++) {
			if (IsBuilding(i) < 4) {
				Building* b = dynamic_cast<Building *>(squares[i]);
				if (b->getOwner() == loser) {
					if (b->checkMortgaged()==-2) {
						cout << "Please pay " << 0.05*b->getCost() << " for receive a mortgaged building " << b->getBuildingName() << endl;
						changePlayerBalance(owed, -0.05*b->getCost());
						cout << "Do you want to unmortgage it now or later(with another extra 10% fees)? Enter 'y' for yes, enter others for no." << endl;
						string c;
						cin >> c;
						if (c == "y") {
							changePlayerBalance(owed, -0.55*b->getCost());
							b->setMortgage(0);
						}
						if (c == "n") {
							b->setMortgage(2);
						}
					}
				}
			}
		}
    }
    if(numPlayers==1){
        end=true;
        cout<<players[0]->getPlayerName()<<" wins the game!!!"<<endl;
        return;
    }
}


void Board::commandCheat() {
	string request;
	cin >> request;
	if (request == "GetMoney") {
		int amount;
		cin >> amount;
		changePlayerBalance(players[current], amount);
		cout << "successful!" << endl;
	}
	if (request == "UnmortageForFree") {
		string b;
		cin >> b;
		if (IsBuilding(findIndex(b))==1) {
			dynamic_cast<Building*>(squares[findIndex(b)])->setMortgage(0);
		}
		cout << "successful!" << endl;
	}
	if (request == "Move") {
		int index;
		cin >> index;
		players[current]->changePosition(squares[index]);
		notifyLocation();
		display->display();
		checkLand();
		cout << "successful!" << endl;
	}
	if (request == "Rollable") {
		rollable = true;
		cout << "successful!" << endl;
	}
	if (request == "NoMoreTimsLine") {
		players[current]->setLineTurn(0);
		cout << "successful!" << endl;
	}
}

void Board::enableCheating() {
	cheating = true;
}

