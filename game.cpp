#include "std_lib_facilities_4.h"
#include "classes.h"

// handles abstract game mechanics
//int pancakes = 8;

int Game::double_number(int n)
{
	cout << "Let's double a number." << endl;
	cout << "pancakes: " << pancakes << endl;
	return n * 2;
}

Game::Game(void)
{
	cout << "new game is being created" << endl;
	this->pancakes = 8;
}

