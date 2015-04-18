// this is the abstract game mechanics

#include "std_lib_facilities_4.h"
#include "classes.h"
<<<<<<< HEAD
#include <random>
#include <chrono>
=======
>>>>>>> origin/master

// handles abstract game mechanics
void Game::set_difficulty(int n)
{
	this->difficulty = n;
	cout << "Difficulty set to: " << this->difficulty << endl;
}

<<<<<<< HEAD
// generates random stack of pancakes
void Game::generate_stack(int d)
{
	// fills vectors with numbers
	for(int i = 0; i < d; ++i) { pancake_stack.push_back(i + 1); }
	
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();				// generates a time-based seed
	shuffle(pancake_stack.begin(), pancake_stack.end(), default_random_engine(seed));	// generates a random permutation of vector
}

// displays the order of pancakes
void Game::print_stack(void)
{
	for(int i = 0; i < pancake_stack.size(); ++i) { cout << pancake_stack[i] << "\t"; }
	cout << endl;
}

// swaps elements a and b in the vector
void Game::swap(int a, int b)
{
	int temp = pancake_stack[a];
	pancake_stack[a] = pancake_stack[b];
	pancake_stack[b] = temp;
}

// flips the order of pancakes from element i to the last element
void Game::flip(int i, int c)	// c is used to gradually move from the last element inwards
{	
	if(i < pancake_stack.size() - 1 - c)
	{
		swap(i, pancake_stack.size() - 1 - c);
		flip(i + 1, c + 1);
	}
	return;
}

// cyclical process used for the game
void Game::cycle(void)
{
	while(game_play)
	{
		int x;
		cout << "Where would you like to place the spatula? ";
		cin >> x;
		if(x == 0)
			undo();
		else
		{
			user_steps.push_back(x - 1);
			flip(x - 1, 0);
			print_stack();
			check();
		}
	}
}

// checks if pancake_stack array is in proper order
void Game::check(void)
{
	for (int i = 0; i < pancake_stack.size() - 1; ++i)
	{
		if(pancake_stack[i] < pancake_stack[i+1])
			return;
	}
	
	game_play = false;
}

// goes back a step
void Game::undo()		// a is the vector of steps, s is the pancake_stack
{
	flip(user_steps[user_steps.size() - 1], 0);
	user_steps.pop_back();
	print_stack();
}

// constructors

Game::Game(int d)
{		
	this->difficulty = d;
	game_play = true;
	
	generate_stack(this->difficulty);
	print_stack();
	cycle();
	cout << "You beat the game!" << endl;
	cout << "It took you " << user_steps.size() << " steps!" << endl;
}
=======
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

>>>>>>> origin/master
