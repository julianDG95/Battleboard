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

		void moveByOne(short int spaces) // Deducts or increments spacesLeft towards zero
		{
			if (spaces > 0)
			{
				spaces--;
			}
			else if (spaces < 0)
			{
				spaces++;
			}
			else 
			{
				cout << "Out of movable spaces, can't  move." << endl;
			}

		}
};