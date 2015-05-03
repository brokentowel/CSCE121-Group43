/*
gameplayscene.cpp
*/

#include "gameplayscene.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

gameplayscene::gameplayscene(Point xy, int w, int h, const string& title) :
Window(xy, w, h, title),
quit_button(Point(729, 0), 70, 30, "Quit", cb_quit),
[](Address, Address pw){reference_to<gameplayscene>(pw).quit();},
spatula1(Point(0, 560), 50, 30, "1", cb_spatula1),
spatula1_pushed(false),
spatula2(Point(0, 520), 50, 30, "2", cb_spatula2),
spatula2_pushed(false),
spatula3(Point(0, 480), 50, 30, "3", cb_spatula3),
spatula3_pushed(false),
spatula4(Point(0, 440), 50, 30, "4", cb_spatula4),
spatula4_pushed(false),
spatula5(Point(0, 400), 50, 30, "5", cb_spatula5),
spatula5_pushed(false),
spatula6(Point(0, 360), 50, 30, "6", cb_spatula6),
spatula6_pushed(false),
spatula7(Point(0, 320), 50, 30, "7", cb_spatula7),
spatula7_pushed(false),
spatula8(Point(0, 280), 50, 30, "8", cb_spatula8),
spatula8_pushed(false)
{
	attach(quit_button);
	attach(spatula1);
	attach(spatula2);
	attach(spatula3);
	attach(spatula4);
	attach(spatula5);
	attach(spatula6);
	attach(spatula7);
	attach(spatula8);
}
//------------------------------------------------------------------------------
void gameplayscene::quit()
{
	hide();
}
//------------------------------------------------------------------------------
void gameplayscene::spatula1()
{
	spatula1_pushed = true;
	//open_rules();
}
//------------------------------------------------------------------------------
bool gameplayscene::spatula2()
{
	hide();
	spatula2_pushed = true;
	//start_game();
}
//------------------------------------------------------------------------------
void gameplayscene::spatula3()
{
	spatula3_pushed = true;
}
//------------------------------------------------------------------------------ 
void gameplayscene::spatula4()
{
	spatula4_pushed = true;
}
void gameplayscene::spatula5()
{
	spatula5_pushed = true;
}
void gameplayscene::spatula6()
{
	spatula6_pushed = true;
}
void gameplayscene::spatula7()
{
	spatula7_pushed = true;
}
void gameplayscene::spatula8()
{
	spatula8_pushed = true;
}
bool gameplayscene::wait_for_button() //need to get red x to work
{
	show();
	quit_pushed = false;
#if 1
	// Simpler handler
	while (!spatula1_pushed && !spatula2_pushed && !spatula3_pushed && !spatula4_pushed && !spatula4_pushed && !spatula5_pushed && !spatula6_pushed && !spatula7_pushed && !spatula8_pushed) Fl::wait();
	Fl::redraw();
#else
	// To handle the case where the user presses the X button in the window frame
	// to kill the application, change the condition to 0 to enable this branch.
	Fl::run();
#endif
	//return button_pushed;
}

//------------------------------------------------------------------------------

void gameplayscene::cb_spatula1(Address, Address a)
// call Simple_window::rules() for the window located at a
{
	reference_to<gameplayscene>(a).spatula1();
}

//------------------------------------------------------------------------------

void gameplayscene::cb_spatula2(Address, Address b)
// call Simple_window::play() for the window located at b
{
	reference_to<gameplayscene>(b).spatula2();
}

//------------------------------------------------------------------------------

void gameplayscene::cb_spatula3(Address, Address c)
// call Simple_window::ldr() for the window located at c
{
	reference_to<gameplayscene>(c).spatula3();
}

//------------------------------------------------------------------------------

void gameplayscene::cb_spatula4(Address, Address d)
// call Simple_window::ldr() for the window located at c
{
	reference_to<gameplayscene>(d).spatula4();
}

//------------------------------------------------------------------------------

void gameplayscene::cb_spatula5(Address, Address e)
// call Simple_window::ldr() for the window located at c
{
	reference_to<gameplayscene>(e).spatula5();
}

//------------------------------------------------------------------------------

void gameplayscene::cb_spatula6(Address, Address f)
// call Simple_window::ldr() for the window located at c
{
	reference_to<gameplayscene>(f).spatula6();
}

//------------------------------------------------------------------------------

void gameplayscene::cb_spatula7(Address, Address g)
// call Simple_window::ldr() for the window located at c
{
	reference_to<gameplayscene>(g).spatula7();
}

//------------------------------------------------------------------------------

void gameplayscene::cb_spatula8(Address, Address h)
// call Simple_window::ldr() for the window located at c
{
	reference_to<gameplayscene>(h).spatula8();
}

//------------------------------------------------------------------------------
