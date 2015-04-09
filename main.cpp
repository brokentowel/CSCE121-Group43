#include "std_lib_facilities_4.h"
#include "classes.h"
	
int main()
try {
	cout << "Pancake game yay!" << endl;
	Intro intro;
	
	Game game;
	cout << game.double_number(4) << endl;

    return 0;
}

catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}

catch (...) {
	cerr << "Some exception\n";
	return 2;
}