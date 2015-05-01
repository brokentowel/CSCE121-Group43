// game screen size is 800x600

#include "std_lib_facilities_4.h"
#include "classes.h"
#include "Graph.h"
#include "Window.h"
	
int main()
try {
	cout << "main() called" << endl;

	using namespace Graph_lib;
	
	Intro win {Point{100, 100}, 800, 600, "FlipFlaps"};
	
	Rectangle r {Point{0, 0}, 800, 600};
	r.set_color(Color::white);
	win.attach(r);
	win.draw(r);
	
	cout << "Select difficulty [2-9]: ";
	int diff;
	cin >> diff;
	
	if (diff >= 2 && diff <= 9)
		Game game(diff);
	else
		cout << "wrong difficulty entered" << endl;

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