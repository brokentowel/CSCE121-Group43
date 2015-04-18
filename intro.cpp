// this should include the splash screen, tutorial, and other intro stuff

#include "std_lib_facilities_4.h"
#include "classes.h"

<<<<<<< HEAD
#include "Graph.h"
#include "Simple_window.h"

Intro::Intro(Simple_window& win)	// reference to window so that this class can actually use it
{
	cout << "Intro constructed" << endl;
	
	// I would like to handle all graphics in the same place, perhaps the main() method, I just have to figure out how to do that
	using namespace Graph_lib;
	
	Color aggie_maroon(fl_rgb_color(80, 0, 0));
	Color gray(fl_rgb_color(188, 177, 171));
	
	Rectangle r {Point{0, 0}, Point{600, 400}};
	r.set_fill_color(aggie_maroon);
	r.set_color(aggie_maroon);
	
	win.attach(r);
	
	win.wait_for_button();
=======
Intro::Intro(void)
{
	cout << "intro constructed" << endl;
>>>>>>> origin/master
}