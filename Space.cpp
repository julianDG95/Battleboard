#include "Space.h"
#include <iostream>
#include <string>

using namespace std;

MajorSpace::MajorSpace(int dist, int dir) {
	vect.push_back(dist);
	vect.push_back(dir);
};


bool MajorSpace::startGame() {
	//MajorGame bg = new MajorGame();
	//bg.play();
	return true;
}

char MajorSpace::getType() {
	return 'b';
}

void MajorSpace::print_detail() {
	cout << "This is a MAJOR space." << endl;
}

SingleSpace::SingleSpace(int val, int dist, int dir) {
	vect.push_back(val);
	vect.push_back(dist);
	vect.push_back(dir);
};

bool SingleSpace::startGame() {
	//SingleGame sg = new SingleGame();
	//sg.play();
	return true;
};

char SingleSpace::getType() {
	return 's';
}

void SingleSpace::print_detail() {
	cout << "This is a SINGLEPLAYER space." << endl;
}

MultiSpace::MultiSpace(int val, int dist, int dir) {
	vect.push_back(val);
	vect.push_back(dist);
	vect.push_back(dir);
};

bool MultiSpace::startGame() {
	//MultiGame mg = new MultiGame();
	//mg.play();
	return true;
};

char MultiSpace::getType() {
	return 'm';
}

void MultiSpace::print_detail() {
	cout << "This is a MULTIPLAYER space." << endl;
}

vector<int> getPosition() {
	//Needs functionality