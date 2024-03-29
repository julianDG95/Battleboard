// Battleboard.cpp
// Runs the game through each player

#include "stdafx.h"
#include <iostream>
#include "Space.h"
#include "Player.h"
#include "Board.h"
#include "Battleboard.h"

// Uses player dice rolls to determine turn order
// turnOrder is an out parameter
void getPlayerOrder(int* turnOrder) {
	int rolls[4][2];
	int position, max;
	std::cout << "Player one please 'roll':";
	std::cin >> rolls[0][0];
	std::cout << "Player two please 'roll':";
	std::cin >> rolls[1][0];
	std::cout << "Player three please 'roll':";
	std::cin >> rolls[2][0];
	std::cout << "Player four please 'roll':";
	std::cin >> rolls[3][0];
	// Set player numbers
	for (int i = 1; i < 5; i++) {
		rolls[i - 1][1] = i;
	}

	for (int z = 3; z >= 0; z--){
		max = rolls[0][0];
		position = 0;
		for (int i = 0; i <= z; i++) {
			if (rolls[i][0] > max) {
				position = i;
			}
		}
		// Highest roll of this round is found
		// add the roller to the turn order
		turnOrder[3 - z] = rolls[position][1];

		// Move the back of the array to the highest roll this turn if it's not already in the back
		if (position != z) {
			rolls[z][0] = rolls[position][0];
			rolls[z][1] = rolls[position][1];
		}
	}
	
}

// Commences a duel between two players
// Returns true if the first player i.e. p1 wins the duel
bool duel(Player p1, Player p2) {
	///...
	return true;
}


// turn: Takes the player and the player number
// Goes through a players turn
void turn(Player p, int i, Board gameBoard) {
	int roll;
	std::cout << "Player " << i << " roll!\n";
	std::cin >> roll; 
	p.setSpacesLeft(roll);

	// As long as you are not trying to move backwards at the begining and 
	while (!(p.getCurrentPosition() == *gameBoard.getBegining() && p.getSpacesLeft < 0) || p.getSpacesLeft != 0) {
		p.moveByOne();
		
		if (!( p.getCurrentPosition() -> isSpaceVacant()) ) {
			if(!duel(p, p.getCurrentPosition() -> getPlayersOnSpace())){
				p.transferSpacesTo(p.getCurrentPosition());
			} 
		}
	}
}


// Runs the actual game, right now only works for human controlled players
int main() {

	Board gameBoard = Board();

	gameBoard.populateSpaces(); // This may go in the constructor depending on what we do
	
	// Create "Players"
	Player p1 = Player();
	Player p2 = Player();
	Player p3 = Player();
	Player p4 = Player();
	

	// Set each players position to starting node
	p1.setCurrentPosition(gameBoard.getBegining());
	p2.setCurrentPosition(gameBoard.getBegining());
	p3.setCurrentPosition(gameBoard.getBegining());
	p4.setCurrentPosition(gameBoard.getBegining());

	int fakeRoll; // Eventually this will be a real roll

	//Game loop
	while (true) {

		std::cout << "Welcome to the BATTLEBOARD!\n";
		int turnOrder[4];
		getPlayerOrder(turnOrder);

		while (true) {
			for (int i = 0; i < 4; i++) {
				switch (turnOrder[i]) {
				case 1:
					turn(p1, 1, gameBoard);
					break;
				case 2:
					turn(p2, 2, gameBoard);
					break;
				case 3:
					turn(p3, 3, gameBoard);
					break;
				case 4:
					turn(p4, 4, gameBoard);
					break;
				}
			}
		}

	}


	return 0;
}