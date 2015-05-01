#include "classes.h"
#include "std_lib_facilities_4.h"

#include "Window.h"
#include "Graph.h"
#include "GUI.h"

// can assign some global variables

Intro::Intro(int w, int h, const string& s)
	: Window(w, h, s),
	to_quit(Point(x_max() - 120, 0), 70, 20, "QUIT", cb_quit)
{
		attach(to_quit);
		to_quit.hide();
}

void Intro::quit()
{
	//hide();
}

// calls quit to destroy the window
void Intro::cb_quit(Address, Address pw)
{
	reference_to<Intro>(pw).quit();
}