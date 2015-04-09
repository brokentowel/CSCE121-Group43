#include "std_lib_facilities_4.h"
#include "classes.h"
	
int main()
try {
	Intro intro;
	cout << "Select difficulty [2-9]:\t";
	int diff;
	cin >> diff;
	intro.set_difficulty(diff);
	
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