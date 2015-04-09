// this should include the splash screen, tutorial, and other intro stuff

#include "std_lib_facilities_4.h"
#include "classes.h"

void Intro::set_difficulty(int n)
{
	this->difficulty = n;
	cout << "Difficulty set to: " << this->difficulty << endl;
}

Intro::Intro(void)
{
	cout << "Select difficulty [2-9]:\t";
	int diff;
	cin >> diff;
	this->set_difficulty(diff);
}