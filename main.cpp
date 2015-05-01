// main.cpp
// game screen size is 800 x 600

#include "classes.h"
#include "std_lib_facilities_4.h"

#include "GUI.h"
#include "Graph.h"
	
int main()
try {
	Intro introduction(800, 600, "FlipFlaps");
	return gui_main();								// keeps the window open
	
	/*
	Intro win {Point{100, 100}, 800, 600, "FlipFlaps"};
	
	cout << "Select difficulty [2-9]: ";
	int diff;
	cin >> diff;
	
	if (diff >= 2 && diff <= 9)
		Game game(diff);
	else
		cout << "wrong difficulty entered" << endl;
	*/
}

catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}

catch (...) {
	cerr << "Some exception\n";
	return 2;
}