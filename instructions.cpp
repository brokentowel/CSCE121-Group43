/*
Welcome to flipjacks! A pancake sorting brain-teaser.
1. First enter your initials
2. Select a difficulty (how many pancakes you want to sort)
3. When the game begins click one of the button at the point you wish to insert a spatula and flip
4. When you have arranged the pancake so that they are stack by decreasing size, you've finished
Try to blah blah blah number of tries blah blah gme over
*/
/*
#include "instructions.h"
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
*/
