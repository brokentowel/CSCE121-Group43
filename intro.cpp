#include "std_lib_facilities_4.h"
#include "classes.h"
#include "Graph.h"
#include "Window.h"

Intro::Intro(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title)
{
	cout << "Intro'd" << endl;
	
}