#include <list>
#include <iostream>
#include "Space.h "


class Board {

	// Displays spaces on command line
	void displayList() {
		std::cout << "Cannot display list yet";
	}

	std::list<Space*> spaceList; // List of all spaces on board



	void populateSpaces() {

	}


	private:
		void addSpace(char type, unsigned int val, unsigned int dist, float dir) {
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

		void addSpace(char type, unsigned int dist, float dir) {
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

};