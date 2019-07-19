#include "Board.h"


// displayList(): no parameters
// Displays spaces on command line
void Board::displayList() {		
	int i = 0;
	for (std::list<Space*>::iterator it = spaceList.begin(); !it == spaceList.end(); it++) {
		std::cout << "Position " << i << " is a "; 
		(**it).print_detail(); // Space needs a "print_detail" method
		std::cout << "\n";
	}
}

// populateSpaces: no parameters
// Fills the list of spaces with spaces
void Board::populateSpaces() {
	// Right now this function will only test the necessary spaces
	addSpace('s', 4, 4, 270.2);
	addSpace('m', 4, 4, 360.0);
	addSpace('b', 4, 360.0);
	addSpace('b', 0, 4, 360.0);
}

// Creates and adds a Space object with given perameters to the list of spaces
// Type is as follows:
//  b: boss
//  s: singleplayer 
//  m: multiplayer
void Board::addSpace(char type, unsigned int val, unsigned int dist, float dir) {
		Space *s;
			if (type == 's') { // Single player space
				SingleSpace newSpace(val, dist, dir);
				s = &newSpace;
			}
			else if (type == 'm') { // Multiplayer space
				MultiSpace newSpace(val, dist, dir);
				s = &newSpace; 
			}
			else if (type == 'b') { // Boss space
				MajorSpace newSpace(dist, dir);
				s = &newSpace;
			}
			else {
				std::cerr << "Invalid char type sent to addSpace";
				return;
				std::cout << "Something has gone wrong, addSpace didn't end on time.";
			}
			spaceList.push_back(s);
		}

// Creates and adds a Space object with given perameters to the list of spaces
// Only a boss type space 'b' will be allowed to possess no value
void Board::addSpace(char type, unsigned int dist, float dir) {
	if (type == 'b') {
		MajorSpace newSpace(dist, dir);
		Space *s = &newSpace; 
				
		spaceList.push_back(s);
	}
	else {
		std::cerr << "Invalid char type sent to addSpace";
		return;
		std::cout << "Something has gone wrong, addSpace didn't end on time.";
	}
}