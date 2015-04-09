// this is the header file that defines all elements in the program

#ifndef CLASSES_H	// checks to see if file has been defined yet
#define CLASSES_H	// if it hasn't, define it

class Intro {
public:
	Intro(void);
	void set_difficulty(int);

private:
	int difficulty;
};

class Game {
public:
	Game(void);
	int double_number(int);

private:
	vector<int> pancake_stack;
	int pancakes;
};

#endif