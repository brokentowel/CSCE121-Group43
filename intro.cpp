// this should include the splash screen, tutorial, and other intro stuff

#include "std_lib_facilities_4.h"
#include "classes.h"
#include "Graph.h"
#include "Window.h"

Intro::Intro(int w, int h, const String& s) : Graph_lib::Window::Window(w, h, s)
{
	cout << "Intro() called" << endl;
	
	using namespace Graph_lib;
	
	cout << "here" << endl;
	
	Rectangle r {Point{0, 0}, w, h};
	
	cout << "it is" << endl;
	
	this->attach(r);
	this->draw();
}