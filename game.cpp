// this is the abstract game mechanics

#include "std_lib_facilities_4.h"
#include "classes.h"

// handles abstract game mechanics
void Game::set_difficulty(int n)
{
	this->difficulty = n;
	cout << "Difficulty set to: " << this->difficulty << endl;
}

Game::Game(int d)
{
	cout << "new game is being created" << endl;
		
	this->difficulty = d;
	cout << "new game is being created with difficult of: " << this->difficulty << endl;
}

Game::Game(void)	// this is a class constructor
{
	this->difficulty = 8;
}

