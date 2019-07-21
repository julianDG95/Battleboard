#pragma once
#include <iostream>
#include <list>
#include <iterator>
#include "Space.h"

class Board
{
private:
	

	void addSpace(char type, unsigned int val, unsigned int dist, float dir);
	void addSpace(char type, unsigned int dist, float dir);
public:
	std::list<Space*> spaceList; // List of pointers to all spaces on board
	// Displays spaces on command line
	void displayList();
	void populateSpaces();
	std::list<Space*>::iterator getBegining() { return spaceList.begin(); }
};