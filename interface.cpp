#include "std_lib_facilities_4.h"
#include "classes.h"

#include "Graph.h"
#include "Simple_window.h"



// draw stack of single pancakes
void Interface::draw_pancakes(Simple_window& win, vector<int> ps)
{
}

// draw a single pancake
void Interface::draw_pancake(int x, int y, int s)
{
	Ellipse lower {Point{x, y-10}, s, s/8};
	Ellipse upper {Point{x, y+10}, s, s/8}; 
	Rectangle r {Point{x-s/2, y+10}, Point{x+s/2, y-10}};
}

Interface::Interface()
{
	if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ", H112);
	
	using namespace Graph_lib;
	
	Window win {Point{100, 100}, 800, 600, "FlipFlaps"};	// create game window

	// define the colors
	Color pancake_color(fl_rgb_color(214, 151, 43));
	Color toasty(fl_rgb_color(115, 79, 17));
	Color blue(fl_rgb_color(33, 152, 237));
	Color dark_blue(fl_rgb_color(6, 83, 138));
}

// smallest pancake has a width of 200, and increases by 30
// 200, 230, 260, 290, 320, 350, 380, 410, 440, 470
