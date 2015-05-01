/*
#include "std_lib_facilities_4.h"
#include "classes.h"

#include "Graph.h"
#include "Window.h"

void Interface::draw_background(void)
{
	Rectangle r {Point{0, 0}, window_width, window_height};
	
	win.attach(r);
}

// draw stack of single pancakes
void Interface::draw_pancakes(Window& win, vector<int> ps)
{
}

// draw a single pancake
void Interface::draw_pancake(int x, int y, int s)
{
	using namespace Graph_lib;
	
	Ellipse lower {Point{x, y-10}, s, s/8};
	Ellipse upper {Point{x, y+10}, s, s/8}; 
	Rectangle r {Point{x-s/2, y+10}, Point{x+s/2, y-10}};
}

Interface::Interface(int w, int h, const String& s)// : Graph_lib::Window::Window(w, h, s)
{
	if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ", H112);
	
	using namespace Graph_lib;
	
	window_width = w;
	window_height = h;
	
	Graph_lib::Window win {w, h, s};	// create game window

	// define the colors
	Color pancake_color(fl_rgb_color(214, 151, 43));
	Color toasty(fl_rgb_color(115, 79, 17));
	Color blue(fl_rgb_color(33, 152, 237));
	Color dark_blue(fl_rgb_color(6, 83, 138));
}

// smallest pancake has a width of 200, and increases by 30
// 200, 230, 260, 290, 320, 350, 380, 410, 440, 470


Color pancake_color(fl_rgb_color(214, 151, 43));
	Color toasty(fl_rgb_color(115, 79, 17));
	Color blue(fl_rgb_color(33, 152, 237));
	Color dark_blue(fl_rgb_color(6, 83, 138));
	
	Rectangle r {Point{0, 0}, 800, 600};
	r.set_color(blue);
*/