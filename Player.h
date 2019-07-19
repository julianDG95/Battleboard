#pragma once

// A player is someone who is playing the game

class Player {
	short int spacesLeft;

	void transferSpacesTo(Player p);

	void moveByOne(short int spaces); // Deducts or increments spacesLeft towards zero

public:
	short int getSpacesLeft();

	void setSpacesLeft(short int s);

	void setCurrentPosition(list<Space*>::iterator it);
};