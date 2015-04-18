// this is the header file that defines all elements in the program

#ifndef CLASSES_H	// checks to see if file has been defined yet
#define CLASSES_H	// if it hasn't, define it

<<<<<<< HEAD
#include "std_lib_facilities_4.h"
#include "classes.h"
#include "Graph.h"
#include "Simple_window.h"

class Intro {
public:
	Intro(Simple_window&);
=======
class Intro {
public:
	Intro(void);
>>>>>>> origin/master
};

class Game {
public:
	Game(int);
	Game(void);
	void set_difficulty(int);
<<<<<<< HEAD
	void generate_stack(int);
	void print_stack(void);
	void swap(int, int);
	void flip(int, int);
	void cycle(void);
	void check(void);
	void undo(void);
	int double_number(int);

private:
	vector<int> pancake_stack;	// assume index 0 to be bottom of stack
	vector<int> user_steps;
	int difficulty;
	bool game_play;
=======
	int double_number(int);

private:
	vector<int> pancake_stack;
	int difficulty;
>>>>>>> origin/master
};

#endif