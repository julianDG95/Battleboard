#pragma once

// A player is someone who is playing the game

class Player {
	short int spacesLeft;

	transferSpacesTo(Player p);

	moveByOne(); // Deducts or increments spacesLeft towards zero
};