#pragma once 
#include "Player.h"
#include <list>
// A space is a zone where a player can land, each type of space can still be a space

class Space{
	virtual void getNewPosition();
	virtual void getType(); 
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