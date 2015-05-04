/*
   Leaderboard_window.cpp
   Revised form of Simple_window.cpp to conform to project needs
   Kenneth Payne		5/2/2015
*/


#include "Leaderboard_window.h"
#include "Splash_screen.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

Leaderboard_window::Leaderboard_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    done_button(Point(65,100), 70, 30, "Done", cb_done)
{
	attach(done_button);
}

//------------------------------------------------------------------------------
void Leaderboard_window::cb_done(Address, Address pw)
{  
    reference_to<Leaderboard_window>(pw).done();    
}

//------------------------------------------------------------------------------
void Leaderboard_window::done()
{
    done_pushed = true;
	hide();
	hide();
	Splash_screen splash(Point(100,200),800,600,"Flipjack");
    splash.wait_for_button();
}
//------------------------------------------------------------------------------

bool Leaderboard_window::wait_for_button() //need to get red x to work
{
    show();
    done_pushed = false;
#if 1
    // Simpler handler
    while (!done_pushed) Fl::wait();
    Fl::redraw();
#else
    // To handle the case where the user presses the X button in the window frame
    // to kill the application, change the condition to 0 to enable this branch.
    Fl::run();
#endif
    return done_pushed;
}
