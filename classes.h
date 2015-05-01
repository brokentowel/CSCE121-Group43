// this is the header file that defines all elements in the program

#ifndef CLASSES_H	// checks to see if file has been defined yet
#define CLASSES_H	// if it hasn't, define it

#include "std_lib_facilities_4.h"
#include "classes.h"

#include "Window.h"
#include "Graph.h"
#include "GUI.h"

using namespace Graph_lib;

struct Intro : Graph_lib::Window
{
	Intro(int, int, const string&);
private:
	void quit();
	static void cb_quit(Address, Address);
	Button to_quit;
};

class Game {
public:
	Game(int);
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
	vector<int> pancake_stack;	// assume index 0 to be top of stack
	vector<int> user_steps;
	int difficulty;
	bool game_play;
	bool game_running;
	int minimum_steps;
};

class Interface {//: public Graph_lib::Window {
public:
	Interface(int w, int h, const String& s);// : public Graph_lib::Window::Window(p, w, h, s);
	void draw_pancakes(vector<int> pancake);
	void draw_pancake(int x, int y, int s);
	void draw_background(void);

private:
	int window_height;
	int window_width;
};

#endif
