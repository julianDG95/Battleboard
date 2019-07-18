#pragma once 
//Pragma once is a preprocessor directive, tells the compiler Space.h should only be used once

// A space is a zone where a player can land, each type of space can still be a space

class Space{
	virtual void getNewPosition();
	virtual void getType(); 
};

class MajorSpace {
	
};

class SingleSpace {
	
};

class MultiSpace {
};