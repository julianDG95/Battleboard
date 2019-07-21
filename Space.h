#pragma once 
#include "Player.h"
#include <list>
#include <vector>
// A space is a zone where a player can land, each type of space can still be a space

class Space{
	// Pure virtual functions are similar to abstract functions
	virtual std::vector<int> getPosition() = 0;
	virtual char getType() = 0;

	bool vacant; // List of pointers to players on the space
	Player playerOnSpace; 
	Player getPlayersOnSpace() { return playerOnSpace; };
	bool isSpaceVacant() { return vacant; }
	void playerLeftSpace() { vacant = true; }
	void playerMovedToSpace(Player p) { playerOnSpace = p; vacant = false; }
};

class MajorSpace : public Space {

};

class SingleSpace : public Space {
	
};

class MultiSpace : public Space {
};