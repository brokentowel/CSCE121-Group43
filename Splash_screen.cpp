/*
   Splash_screen.cpp
   Revised form of Simple_window.cpp to conform to project needs
   Kenneth Payne		5/2/2015
*/

#include "Splash_screen.h"
#include "Leaderboard_window.h"
#include "gameplayscene.h"
#include "Leaderboard.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

Splash_screen::Splash_screen(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
	difficulty2_button(Point(350, 50), 100, 30, "2 - Easiest", cb_difficulty2),
	difficulty2_pushed(false),
	difficulty3_button(Point(350, 100), 100, 30, "3", cb_difficulty3),
	difficulty3_pushed(false),
	difficulty4_button(Point(350, 150), 100, 30, "4", cb_difficulty4),
	difficulty4_pushed(false),
	difficulty5_button(Point(350, 200), 100, 30, "5", cb_difficulty5),
	difficulty5_pushed(false),
	difficulty6_button(Point(350, 250), 100, 30, "6", cb_difficulty6),
	difficulty6_pushed(false),
	difficulty7_button(Point(350, 300), 100, 30, "7", cb_difficulty7),
	difficulty7_pushed(false),
	difficulty8_button(Point(350, 350), 100, 30, "8", cb_difficulty8),
	difficulty8_pushed(false),
	difficulty9_button(Point(350, 400), 100, 30, "9 - Hardest", cb_difficulty9),
	difficulty9_pushed(false),
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
//-------------------------------------------------------
void Splash_screen::difficulty2()
{
	hide();
	difficulty2_pushed = true;
	gameplayscene gameplay{Point{100,100},800,600,"Gameplay", 2};
	gui_main(); //wait_for_button();
}

void Splash_screen::difficulty3()
{
	hide();
	difficulty3_pushed = true;
	gameplayscene gameplay{Point{100,100},800,600,"Gameplay", 3};
	wait_for_button();
}

void Splash_screen::difficulty4()
{
	hide();
	difficulty4_pushed = true;
	gameplayscene gameplay{Point{100,100},800,600,"Gameplay", 4};
	wait_for_button();
}

void Splash_screen::difficulty5()
{
	hide();
	difficulty5_pushed = true;
	gameplayscene gameplay{Point{100,100},800,600,"Gameplay", 5};
	wait_for_button();
}

void Splash_screen::difficulty6()
{
	hide();
	difficulty6_pushed = true;
	gameplayscene gameplay{Point{100,100},800,600,"Gameplay", 6};
	wait_for_button();
}

void Splash_screen::difficulty7()
{
	hide();
	difficulty7_pushed = true;
	gameplayscene gameplay{Point{100,100},800,600,"Gameplay", 7};
	wait_for_button();
}

void Splash_screen::difficulty8()
{
	hide();
	difficulty8_pushed = true;
	gameplayscene gameplay{Point{100,100},800,600,"Gameplay", 8};
	wait_for_button();
}

void Splash_screen::difficulty9()
{
	hide();
	difficulty9_pushed = true;
	gameplayscene gameplay{Point{100,100},800,600,"Gameplay", 9};
	wait_for_button();
}
//------------------------------------------------------------------------------
void Splash_screen::quit()
{
	detach(play_button);
	detach(ldr_button);
	detach(rules_button);
	detach(quit_button);
    hide();
}
//------------------------------------------------------------------------------
void Splash_screen::rules()
{
	detach(play_button);
	detach(ldr_button);
	detach(rules_button);
	detach(quit_button);
    rules_pushed = true;
    //open_rules();
}
//------------------------------------------------------------------------------
bool Splash_screen::play()
{
	detach(play_button);
	detach(ldr_button);
	detach(rules_button);
	detach(quit_button);
	
    play_pushed = true;
	
	attach(difficulty2_button);
	difficulty2_button.show();
	attach(difficulty3_button);
	difficulty3_button.show();
	attach(difficulty4_button);
	difficulty4_button.show();
	attach(difficulty5_button);
	difficulty5_button.show();
	attach(difficulty6_button);
	difficulty6_button.show();
	attach(difficulty7_button);
	difficulty7_button.show();
	attach(difficulty8_button);
	difficulty8_button.show();
	attach(difficulty9_button);
	difficulty9_button.show();
	
    wait_for_button();
}
//------------------------------------------------------------------------------
void Splash_screen::ldr()
{
    ldr_pushed = true;
    disp_leaderboard();
    wait_for_button();
}
//------------------------------------------------------------------------------ 

bool Splash_screen::wait_for_button() //need to get red x to work
{
    show();
    quit_pushed = false;
#if 1
    // Simpler handler
    while ((!rules_pushed && !play_pushed && !ldr_pushed) || (!difficulty2_pushed && !difficulty3_pushed && !difficulty4_pushed && !difficulty5_pushed && !difficulty6_pushed && !difficulty7_pushed && !difficulty8_pushed && !difficulty9_pushed)) Fl::wait();
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

void Splash_screen::cb_difficulty2(Address, Address d2)
{
	reference_to<Splash_screen>(d2).difficulty2();
}
void Splash_screen::cb_difficulty3(Address, Address d3)
{
	reference_to<Splash_screen>(d3).difficulty3();
}
void Splash_screen::cb_difficulty4(Address, Address d4)
{
	reference_to<Splash_screen>(d4).difficulty4();
}
void Splash_screen::cb_difficulty5(Address, Address d5)
{
	reference_to<Splash_screen>(d5).difficulty5();
}
void Splash_screen::cb_difficulty6(Address, Address d6)
{
	reference_to<Splash_screen>(d6).difficulty6();
}
void Splash_screen::cb_difficulty7(Address, Address d7)
{
	reference_to<Splash_screen>(d7).difficulty7();
}
void Splash_screen::cb_difficulty8(Address, Address d8)
{
	reference_to<Splash_screen>(d8).difficulty8();
}
void Splash_screen::cb_difficulty9(Address, Address d9)
{
	reference_to<Splash_screen>(d9).difficulty9();
}
