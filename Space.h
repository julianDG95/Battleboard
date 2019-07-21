#pragma once 
#include "Player.h"
#include <list>
#include <vector>
// A space is a zone where a player can land, each type of space can still be a space.

class Space{
public:
	// Pure virtual functions are similar to abstract functions
	virtual std::vector<int> getPosition() = 0;
	virtual char getType() = 0;
	virtual void print_detail() = 0;
	virtual bool startGame() = 0;
	virtual vector<int> getPosition() = 0;

	bool vacant; // List of pointers to players on the space
	Player playerOnSpace; 
	virtual Player getPlayerOnSpace() { return playerOnSpace; };
	virtual bool isSpaceVacant() { return vacant; }
	virtual void playerLeftSpace() { vacant = true; }
	virtual void playerMovedToSpace(Player p) { playerOnSpace = p; vacant = false; }
};

class MajorSpace : public Space {
	MajorSpace(int dist, int dir);
	int dist;
	float dir;
	vector<int> vect;
	bool startGame();
	char getType();
	void print_detail();
};

class SingleSpace : public Space {
	SingleSpace(int val, int dist, int dir);
	int val;
	int dist;
	float dir;
	vector<int> vect;
	bool startGame();
	char getType();
	void print_detail();
};

class MultiSpace : public Space {
	MultiSpace(int val, int dist, int dir);
	int val;
	int dist;
	float dir;
	vector<int> vect;
	bool startGame();
	char getType();
	void print_detail();
};