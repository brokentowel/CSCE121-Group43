// this is the header file that defines all elements in the program

#ifndef CLASSES_H	// checks to see if file has been defined yet
#define CLASSES_H	// if it hasn't, define it

#include "std_lib_facilities_4.h"
#include "classes.h"
#include "Graph.h"
#include "Simple_window.h"

class Intro {
public:
	Intro(Simple_window&);
};

class Game {
public:
	Game(Simple_window&, int);
	void set_difficulty(int);
	void generate_stack(int);
	void print_stack(void);
	void swap(int, int);
	void flip(int, int);
	void cycle(void);
	void check(void);
	void undo(void);
	int get_minimum_steps();
	int calculate_score();

private:
	vector<int> pancake_stack;	// assume index 0 to be bottom of stack
	vector<int> user_steps;
	int difficulty;
	bool game_play;
	int minimum_steps;
};

#endif