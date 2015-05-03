/*
   Splash_screen.cpp
   Revised form of Simple_window.cpp to conform to project needs
   Kenneth Payne		5/2/2015
*/

#include "Splash_screen.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

Splash_screen::Splash_screen(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    rules_button(Point(255,560), 70, 20, "Rules", cb_rules),
    rules_pushed(false),
    play_button(Point(365,560), 70, 20, "Play", cb_play),
    play_pushed(false),
    ldr_button(Point(475,560), 70, 20, "Leaderboard", cb_ldr),
    ldr_pushed(false)
{
    attach(rules_button);
    attach(play_button);
    attach(ldr_button);
}

//------------------------------------------------------------------------------
void Splash_screen::rules()
{
    rules_pushed = true;
    //forward = true;
    //return forward;
}
//------------------------------------------------------------------------------
bool Splash_screen::play()
{
    play_pushed = true;
    //forward = true;
    //return forward;
}
//------------------------------------------------------------------------------
void Splash_screen::ldr()
{
    ldr_pushed = true;
    //forward = true;
    //return forward;
}
//------------------------------------------------------------------------------ 

bool Splash_screen::wait_for_button()
{
    show();
    //button_pushed = false;
#if 1
    // Simpler handler
    while (!rules_pushed && !play_pushed && !ldr_pushed) Fl::wait();
    Fl::redraw();
#else if 0
    // To handle the case where the user presses the X button in the window frame
    // to kill the application, change the condition to 0 to enable this branch.
    Fl::run();
#endif
    //return button_pushed;
}

//------------------------------------------------------------------------------

void Splash_screen::cb_rules(Address, Address a)
// call Simple_window::rules() for the window located at a
{  
    reference_to<Splash_screen>(a).rules();    
}

//------------------------------------------------------------------------------

void Splash_screen::cb_play(Address, Address b)
// call Simple_window::play() for the window located at b
{  
    reference_to<Splash_screen>(b).play();    
}

//------------------------------------------------------------------------------

void Splash_screen::cb_ldr(Address, Address c)
// call Simple_window::ldr() for the window located at c
{  
    reference_to<Splash_screen>(c).ldr();    
}

//------------------------------------------------------------------------------
