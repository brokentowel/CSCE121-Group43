/*
   Splash_screen.cpp
   Revised form of Simple_window.cpp to conform to project needs
   Kenneth Payne		5/2/2015
*/

#include "Splash_screen.h"
#include "Leaderboard_window.h"
#include "gameplayscene.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

Splash_screen::Splash_screen(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    quit_button(Point(729,0), 70, 30, "Quit", cb_quit),
    rules_button(Point(210,540), 100, 30, "Rules", cb_rules),
    rules_pushed(false),
    play_button(Point(350,540), 100, 30, "Play", cb_play),
    play_pushed(false),
    ldr_button(Point(490,540), 100, 30, "Leaderboard", cb_ldr),
    ldr_pushed(false)
{
    attach(quit_button);
    attach(rules_button);
    attach(play_button);
    attach(ldr_button);
}
//------------------------------------------------------------------------------
void Splash_screen::quit()
{
    hide();
}
//------------------------------------------------------------------------------
void Splash_screen::rules()
{
    rules_pushed = true;
    //open_rules();
}
//------------------------------------------------------------------------------
bool Splash_screen::play()
{
	hide();
    play_pushed = true;
    gameplayscene gameplay{Point{100,100},800,600,"Gameplay"};
    gameplay.wait_for_button();
}
//------------------------------------------------------------------------------
void Splash_screen::ldr()
{
    ldr_pushed = true;
    Leaderboard_window leaders{Point{100,100},200,300,"Hi-Scores"};
    leaders.wait_for_button();
}
//------------------------------------------------------------------------------ 

bool Splash_screen::wait_for_button() //need to get red x to work
{
    show();
    quit_pushed = false;
#if 1
    // Simpler handler
    while (!rules_pushed && !play_pushed && !ldr_pushed) Fl::wait();
    Fl::redraw();
#else
    // To handle the case where the user presses the X button in the window frame
    // to kill the application, change the condition to 0 to enable this branch.
    Fl::run();
#endif
    //return button_pushed;
}

//------------------------------------------------------------------------------
void Splash_screen::cb_quit(Address, Address pw)
{  
    reference_to<Splash_screen>(pw).quit();    
}

//-------------------------------------------------------------------

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
