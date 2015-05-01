#include "std_lib_facilities_4.h"
#include "classes.h"
#include "find_solution.h"
#include <random>
#include <chrono>

// handles abstract game mechanics
void Game::set_difficulty(int n)
{
	this->difficulty = n;
	cout << "Difficulty set to: " << this->difficulty << endl;
}

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
	if(c < i)
	{
		swap(c, i);
		flip(i - 1, c + 1);
	}
	
	return;
}

// cyclical process used for the game
void Game::cycle(void)
{	
	while(game_play)
	{	
		if (pancake_stack.size() > minimum_steps + 10) { break; }	// this would result in a negative score, at which point the game ends
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
		if(pancake_stack[i] > pancake_stack[i+1])
			return;
	}
	
	game_play = false;
}

// goes back a step
void Game::undo()
{
	flip(user_steps[user_steps.size() - 1], 0);
	user_steps.pop_back();
	print_stack();
}

// returns the minimum amount of steps to complete the game
int Game::get_minimum_steps()
{
	return find_solution(pancake_stack)->size();	// since find_solution() returns a pointer to an array, we must use -> to access the member function
}

// calculates score
int Game::calculate_score()
{
	return (100 - 10 * (user_steps.size() - minimum_steps)) * difficulty;
}

// constructors

Game::Game(int d)
{
	cout << "Game constructed" << endl;
	game_running = true;
	
	char input;
	
	difficulty = d;
	
	while (game_running)
	{
		game_play = true;
		
		generate_stack(difficulty);
		
		minimum_steps = get_minimum_steps();
		
		print_stack();
		cycle();
		game_play = false;
		cout << "You beat the game!" << endl;
		cout << "It took you " << user_steps.size() << " steps!" << endl;
		cout << "Score: " << calculate_score() << endl;
		cout << "Would you like to play again? [Y/N]";
		cin >> input;
		if (input == 'N' || input == 'n') { break; }
	}
}
