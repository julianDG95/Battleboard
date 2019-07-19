#pragma once

// A player is someone who is playing the game

class Player {
	short int spacesLeft;

	void transferSpacesTo(Player p);

	bool moveByOne(short int spaces); // Deducts or increments spacesLeft towards zero
};