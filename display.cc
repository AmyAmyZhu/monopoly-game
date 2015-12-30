#include "display.h"
#include <string>
#include <iostream>

using namespace std;

void BoardDisplay::display() {
	string line1 = "-----------------------------------------------------------------------------------------";
	string line2 = "|Goose  |       |NEEDLES|       |       |V1     |       |       |CIF    |       |GO TO  |";
	string line3 = "|Nesting|-------|HALL   |-------|-------|       |-------|-------|       |-------|TIMS   |";
	string line4 = "|       |EV1    |       |EV2    |EV3    |       |PHYS   |B1     |       |B2     |       |";
	string line5 = "|       |       |       |       |       |       |       |       |       |       |       |";
	string line6 = "|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|";
	string line7 = "|       |                                                                       |       |";
	string line8 = "|-------|                                                                       |-------|";
	string line9 = "|OPT    |                                                                       |EIT    |";
	string line10 = "|       |                                                                       |       |";
	string line11 = "|-------|                                                                       |-------|";
	string line12 = "|       |                                                                       |       |";
	string line13 = "|-------|                                                                       |-------|";
	string line14 = "|BMH    |                                                                       |ESC    |";
	string line15 = "|       |                                                                       |       |";
	string line16 = "|-------|                                                                       |-------|";
	string line17 = "|SLC    |                                                                       |SLC    |";
	string line18 = "|       |                                                                       |       |";
	string line19 = "|       |                                                                       |       |";
	string line20 = "|       |                                                                       |       |";
	string line21 = "|-------|                                                                       |-------|";
	string line22 = "|       |                                                                       |       |";
	string line23 = "|-------|                                                                       |-------|";
	string line24 = "|LHI    |                                                                       |C2     |";
	string line25 = "|       |               -----------------------------------------               |       |";
	string line26 = "|-------|               |                                       |               |-------|";
	string line27 = "|UWP    |               |  ###   ###    ####  ###   ###   ###   |               |REV    |";
	string line28 = "|       |               |  #  #  #  #     #  #   # #   # #   #  |               |       |";
	string line29 = "|       |               |  ####  ####    #   #   # #   # #   #  |               |       |";
	string line30 = "|       |               |  #   # #   #  #    #   # #   # #   #  |               |       |";
	string line31 = "|-------|               |  ####  ####  #      ###   ###   ###   |               |-------|";
	string line32 = "|       |               |                                       |               |NEEDLES|";
	string line33 = "|-------|               -----------------------------------------               |HALL   |";
	string line34 = "|CPH    |                                                                       |       |";
	string line35 = "|       |                                                                       |       |";
	string line36 = "|-------|                                                                       |-------|";
	string line37 = "|       |                                                                       |       |";
	string line38 = "|-------|                                                                       |-------|";
	string line39 = "|DWE    |                                                                       |MC     |";
	string line40 = "|       |                                                                       |       |";
	string line41 = "|-------|                                                                       |-------|";
	string line42 = "|PAC    |                                                                       |COOP   |";
	string line43 = "|       |                                                                       |FEE    |";
	string line44 = "|       |                                                                       |       |";
	string line45 = "|       |                                                                       |       |";
	string line46 = "|-------|                                                                       |-------|";
	string line47 = "|       |                                                                       |       |";
	string line48 = "|-------|                                                                       |-------|";
	string line49 = "|RCH    |                                                                       |DC     |";
	string line50 = "|       |                                                                       |       |";
	string line51 = "|-------|-----------------------------------------------------------------------|-------|";
	string line52 = "|DC Tims|       |       |NEEDLES|       |MKV    |TUITION|       |SLC    |       |COLLECT|";
	string line53 = "|Line   |-------|-------|HALL   |-------|       |       |-------|       |-------|OSAP   |";
	string line54 = "|       |HH     |PAS    |       |ECH    |       |       |ML     |       |AL     |       |";
	string line55 = "|       |       |       |       |       |       |       |       |       |       |       |";
	string line56 = "|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|";

	// set the improvement of academic buildings

	line52.replace(73, 5, improvement[1]);   // AL
	line52.replace(57, 5, improvement[3]);   // ML
	line52.replace(33, 5, improvement[6]);   // ECH
	line52.replace(17, 5, improvement[8]);   // PAS
	line52.replace(9, 5, improvement[9]);    // HH
	line47.replace(1, 5, improvement[11]);   // RCH
	line37.replace(1, 5, improvement[13]);   // DWE
	line32.replace(1, 5, improvement[14]);   // CPH
	line22.replace(1, 5, improvement[16]);   // LHI
	line12.replace(1, 5, improvement[18]);   // BMH
	line7.replace(1, 5, improvement[19]);    // OPT
	line2.replace(9, 5, improvement[21]);    // EV1
	line2.replace(25, 5, improvement[23]);   // EV2
	line2.replace(33, 5, improvement[24]);   // EV3
	line2.replace(49, 5, improvement[26]);   // PHYS
	line2.replace(57, 5, improvement[27]);   // B1
	line2.replace(73, 5, improvement[29]);   // B2
	line7.replace(81, 5, improvement[31]);   // EIT
	line12.replace(81, 5, improvement[32]);  // ESC
	line22.replace(81, 5, improvement[34]);  // C2
	line37.replace(81, 5, improvement[37]);  // MC
	line47.replace(81, 5, improvement[39]);  // DC

	// set the academic building owner
	line52.at(79) = Owner[1];  // AL
	line52.at(63) = Owner[3]; // ML
	line52.at(39) = Owner[6];  // ECH
	line52.at(23) = Owner[8];  // PAS
	line52.at(15) = Owner[9];  // HH
	line47.at(6) = Owner[11];  // RCH
	line37.at(6) = Owner[13];  // DWE
	line32.at(6) = Owner[14];  // CPH
	line22.at(6) = Owner[16];  // LHI
	line12.at(6) = Owner[18];  // BMH
	line7.at(6) = Owner[19];   // OPT
	line2.at(14) = Owner[21];  // EV1
	line2.at(30) = Owner[23];  // EV2
	line2.at(38) = Owner[24];  // EV3
	line2.at(54) = Owner[26];  // PHYS
	line2.at(62) = Owner[27];  // B1
	line2.at(78) = Owner[29];  // B2
	line7.at(86) = Owner[31];  // EIT
	line12.at(86) = Owner[32]; // ESC
	line22.at(86) = Owner[34]; // C2
	line37.at(86) = Owner[37]; // MC
	line47.at(86) = Owner[39]; // DC

	// set players location
	for (int i = 0; i < 6; i++) {
		if (playerLocation[i] <= 10) { // 0-10
			line55.at(81 - playerLocation[i] * 8 + i) = playerAbb[i];
		}
		else if (playerLocation[i] == 11) { // 11
			line50.at(i + playerLocation[i] - 10) = playerAbb[i];
		}
		else if (playerLocation[i] == 12) { // 12
			line45.at(i + playerLocation[i] - 11) = playerAbb[i];
		}
		else if (playerLocation[i] == 13) { // 13
			line40.at(i + playerLocation[i] - 12) = playerAbb[i];
		}
		else if (playerLocation[i] == 14) { // 14
			line35.at(i + playerLocation[i] - 13) = playerAbb[i];
		}
		else if (playerLocation[i] == 15) { // 15
			line30.at(i + playerLocation[i] - 14) = playerAbb[i];
		}
		else if (playerLocation[i] == 16) { // 16
			line25.at(i + playerLocation[i] - 15) = playerAbb[i];
		}
		else if (playerLocation[i] == 17) { // 17
			line20.at(i + playerLocation[i] - 16) = playerAbb[i];
		}
		else if (playerLocation[i] == 18) { // 18
			line15.at(i + playerLocation[i] - 17) = playerAbb[i];
		}
		else if (playerLocation[i] == 19) { // 19
			line10.at(i + playerLocation[i] - 18) = playerAbb[i];
		}

		else if ((playerLocation[i] >= 20) && (playerLocation[i] <= 30)) { // 20-30
			line5.at(1 + (playerLocation[i] - 20) * 8 + i) = playerAbb[i];
		}

		else if (playerLocation[i] == 31) { // 31
			line10.at(i + playerLocation[i] + 50) = playerAbb[i];
		}
		else if (playerLocation[i] == 32) { // 32
			line15.at(i + playerLocation[i] + 49) = playerAbb[i];
		}
		else if (playerLocation[i] == 33) { // 33
			line20.at(i + playerLocation[i] + 48) = playerAbb[i];
		}
		else if (playerLocation[i] == 34) { // 34
			line25.at(i + playerLocation[i] + 47) = playerAbb[i];
		}
		else if (playerLocation[i] == 35) { // 35
			line30.at(i + playerLocation[i] + 46) = playerAbb[i];
		}
		else if (playerLocation[i] == 36) { // 36
			line35.at(i + playerLocation[i] + 45) = playerAbb[i];
		}
		else if (playerLocation[i] == 37) { // 37
			line40.at(i + playerLocation[i] + 44) = playerAbb[i];
		}
		else if (playerLocation[i] == 38) { // 38
			line45.at(i + playerLocation[i] + 43) = playerAbb[i];
		}
		else if (playerLocation[i] == 39) { // 39
			line50.at(i + playerLocation[i] + 42) = playerAbb[i];
		}
	}
	// print out the result
	cout << line1 << endl << line2 << endl << line3 << endl << line4 << endl << line5 << endl;
	cout << line6 << endl << line7 << endl << line8 << endl << line9 << endl << line10 << endl;
	cout << line11 << endl << line12 << endl << line13 << endl << line14 << endl << line15 << endl;
	cout << line16 << endl << line17 << endl << line18 << endl << line19 << endl << line20 << endl;
	cout << line21 << endl << line22 << endl << line23 << endl << line24 << endl << line25 << endl;
	cout << line26 << endl << line27 << endl << line28 << endl << line29 << endl << line30 << endl;
	cout << line31 << endl << line32 << endl << line33 << endl << line34 << endl << line35 << endl;
	cout << line36 << endl << line37 << endl << line38 << endl << line39 << endl << line40 << endl;
	cout << line41 << endl << line42 << endl << line43 << endl << line44 << endl << line45 << endl;
	cout << line46 << endl << line47 << endl << line48 << endl << line49 << endl << line50 << endl;
	cout << line51 << endl << line52 << endl << line53 << endl << line54 << endl << line55 << endl << line56 << endl;
}

void BoardDisplay::notifyImprov(int index, int numImprov, char owner) {
	if (numImprov != -1) {
		string temp = "";
        // increasingly add I to show the level of improvements
		for (int i = 0; i < numImprov; i++) {
			temp += "I";
		}
		for (int i = numImprov; i < 5; i++) {
			temp += " ";
		}
		improvement[index] = temp;
	}
	Owner[index] = owner;
}

void BoardDisplay::notifyLocation(int index, int where) {
	playerLocation[index] = where;
}

char BoardDisplay::getPlayerAbb(int index) {
	return playerAbb[index];
}

BoardDisplay::BoardDisplay() {
	for (int i = 0; i < 6; i++) {
		playerAbb[i] = ' ';
	}
	for (int i = 0; i < 6; i++) {
		playerLocation[i] = ' ';
	}
	for (int i = 0; i < 40; i++) {
		Owner[i] = ' ';
	}
    // initial all improvements to be empty
	improvement[1] = "     ";
	improvement[3] = "     ";
	improvement[6] = "     ";
	improvement[8] = "     ";
	improvement[9] = "     ";
	improvement[11] = "     ";
	improvement[13] = "     ";
	improvement[14] = "     ";
	improvement[16] = "     ";
	improvement[18] = "     ";
	improvement[19] = "     ";
	improvement[21] = "     ";
	improvement[23] = "     ";
	improvement[24] = "     ";
	improvement[26] = "     ";
	improvement[27] = "     ";
	improvement[29] = "     ";
	improvement[31] = "     ";
	improvement[32] = "     ";
	improvement[34] = "     ";
	improvement[37] = "     ";
	improvement[39] = "     ";
}

void BoardDisplay::notifyPlayer(int index, char abb) {
	playerAbb[index] = abb;
}



