#include "Player.h"
#include "stdafx.h"
#include <string>
#include <iostream>
#include <iterator>
#include <list>
#include "Space.h"
using namespace std;

class Player
{
private:
	short int spacesLeft;

	list<Space*>::iterator currentPosition;  // Pointer at current Space node


public:

	short int getSpacesLeft()
	{
		return spacesLeft;
	}

	void setSpacesLeft(short int s)
	{
		this->spacesLeft = s;
	}


	void transferSpacesTo(Player p) //Gives remainder of spaces from current player to target player
	{
		p.setSpacesLeft(this->getSpacesLeft());
	}

	void moveByOne() // Deducts or increments spacesLeft towards zero
	{
		if (spacesLeft > 0)
		{
			spacesLeft--;
			currentPosition--; 
		}
		else if (spacesLeft < 0)
		{
			spacesLeft++;
			currentPosition++;
		}
		else
		{
			cout << "Out of movable spaces, can't  move." << endl;
		}

	}

	void setCurrentPosition(list<Space*>::iterator it) {
		currentPosition = it; 
	}

	list<Space*>::iterator getCurrentPosition(){
		return currentPosition;
	}
};