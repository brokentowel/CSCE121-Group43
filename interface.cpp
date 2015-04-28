/*
	This class can be used to implement all graphics into the program
	Color Scheme:
		pancake color 	RGB(214,151,43)
		toasty		RGB(115,79,17)
		blue		RGB(33,152,237)
		dark_blue	RGB(6,83,138)
*/

#include "std_lib_facilities_4.h"
#include "classes.h"

// this could draw the stack of drawn pancakes
void Interface::draw_pancakes(Simple_window& win, vector<int> ps)
{
	
	/* takes the array of pancakes and draws them all on same x-value with different y-values depending on size of pancakes
	for loop:
		// draw bottom pancake (so that it appears to be underneath other pancakes)
		// from array.end() to 0
	*/
}

// this could draw a single pancake; let's assume pancake has a height of h 
void Interface::draw_pancake(int x, int y, int s)
{
	Ellipse lower {Point{x, y-10}, s, s/8};					// 
	Ellipse upper {Point{x, y+10}, s, s/8};					// 
	Rectangle r {Point{x-s/2, y+10}, Point{x+s/2, y-10}};	// rectangle
	
	// takes position x, position y, and size to draw a pancake of specific shape and height
	// oval top and bottom with circle sides and rectangle center?
}

Interface::Interface(Simple_window& win)
{
	using namespace Graph_lib;
	win.wait_for_button();	
}

// smallest pancake has a width of 200, and increases by 30
// 200, 230, 260, 290, 320, 350, 380, 410, 440, 470
