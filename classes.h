// this is the header file that defines all elements in the program

#ifndef CLASSES_H	// checks to see if file has been defined yet
#define CLASSES_H	// if it hasn't, define it

class Intro {
public:
	Intro(void);
};

class Game {
public:
	Game(int);
	Game(void);
	void set_difficulty(int);
	int double_number(int);

private:
	vector<int> pancake_stack;
	int difficulty;
};

#endif