#pragma once
#include <list>

// A player is someone who is playing the game

class Player {
	short int spacesLeft;

	void transferSpacesTo(Player p);

public:
	void moveByOne(); // Deducts or increments spacesLeft towards zero

	short int getSpacesLeft();

	void setSpacesLeft(short int s);

	void setCurrentPosition(std::list<Space*>::iterator it);
	std::list<Space*>::iterator getCurrentPosition(); 
};