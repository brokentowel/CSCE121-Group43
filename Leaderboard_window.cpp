/*
   Leaderboard_window.cpp
   Revised form of Simple_window.cpp to conform to project needs
   Kenneth Payne		5/2/2015
*/

#include "Splash_screen.h"
#include "Leaderboard_window.h"
#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include "Window.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

Leaderboard_window::Leaderboard_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    back_button(Point(0, 0), 50, 20, "Back", cb_back),
	back_pushed(false)
{
	attach(back_button);
}

void Leaderboard_window::back()
{
	back_pushed = true;
	hide();
	Splash_screen splash(Point(100,200),800,600,"FlipFlaps");
    wait_for_button();
}

bool Leaderboard_window::wait_for_button() //need to get red x to work
{
    //show();
    back_pushed = false;
#if 1
    // Simpler handler
    while (!back_pushed) Fl::wait();
    Fl::redraw();
#else
    // To handle the case where the user presses the X button in the window frame
    // to kill the application, change the condition to 0 to enable this branch.
    Fl::run();
#endif
    //return button_pushed;
}

void Leaderboard_window::cb_back(Address, Address b)
{
	reference_to<Leaderboard_window>(b).back();
}