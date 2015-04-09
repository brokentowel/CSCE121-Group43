#include "std_lib_facilities_4.h"
#include "classes.h"
	
int main()
try {
	cout << "Pancake game yay!" << endl;
	Intro intro;
	
	cout << "Select difficulty [2-9]: ";
	int diff;
	cin >> diff;
	if (diff >= 2 && diff <= 9)
		Game game(diff);
	else
		cout << "wrong difficult entered" << endl;

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