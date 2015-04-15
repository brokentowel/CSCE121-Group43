#include "std_lib_facilities_4.h"
#include "classes.h"
#include "Graph.h"
#include "Simple_window.h"
	
int main()
try {
	cout << "main() called" << endl;
	
	if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ", H112);
	
	using namespace Graph_lib;
	
	Simple_window win {Point{100, 100}, 600, 400, "FlipFlaps"};	// create game window
	
	Intro intro;
	
	cout << "Select difficulty [2-9]: ";
	int diff;
	cin >> diff;
	if (diff >= 2 && diff <= 9)
		Game game(diff);
	else
		cout << "wrong difficult entered" << endl;
	
	win.wait_for_button();

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