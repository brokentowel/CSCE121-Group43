/*
gameplayscene.cpp
*/

#include "gameplayscene.h"
#include "Graph.h"
#include "Window.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

gameplayscene::gameplayscene(Point xy, int w, int h, const string& title) :
	Window(xy, w, h, title),
	background_with_color(Point(0,0),800,600),
	quit_button(Point(729, 0), 70, 30, "Quit", cb_quit),
	quit_b(Point(729,0),70,30),
	spatula1_button(Point(0, 560), 50, 30, "1", cb_spatula1),
	spatula1_b(Point(0,560),50,30),
	spatula1_pushed(false),
	spatula2_button(Point(0, 520), 50, 30, "2", cb_spatula2),
	spatula2_b(Point(0,520),50,30),
	spatula2_pushed(false),
	spatula3_button(Point(0, 480), 50, 30, "3", cb_spatula3),
	spatula3_b(Point(0,480),50,30),
	spatula3_pushed(false),
	spatula4_button(Point(0, 440), 50, 30, "4", cb_spatula4),
	spatula4_b(Point(0,440),50,30),
	spatula4_pushed(false),
	spatula5_button(Point(0, 400), 50, 30, "5", cb_spatula5),
	spatula5_pushed(false),
	spatula5_b(Point(0,400),50,30),
	spatula6_button(Point(0, 360), 50, 30, "6", cb_spatula6),
	spatula6_b(Point(0,360),50,30),
	spatula6_pushed(false),
	spatula7_button(Point(0, 320), 50, 30, "7", cb_spatula7),
	spatula7_b(Point(0,320),50,30),
	spatula7_pushed(false),
	spatula8_button(Point(0, 280), 50, 30, "8", cb_spatula8),
	spatula8_b(Point(0,280),50,30),
	spatula8_pushed(false)
{
	background_with_color.set_fill_color(Color::cyan);
	attach(background_with_color);
	attach(quit_button);
	attach(spatula1_button);
	attach(spatula2_button);
	attach(spatula3_button);
	attach(spatula4_button);
	attach(spatula5_button);
	attach(spatula6_button);
	attach(spatula7_button);
	attach(spatula8_button);
	quit_b.set_fill_color(Color::red);
	attach(quit_b);
	spatula1_b.set_fill_color(Color::white);
	attach(spatula1_b);
	spatula2_b.set_fill_color(Color::white);
	attach(spatula2_b);
	spatula3_b.set_fill_color(Color::white);
	attach(spatula3_b);
	spatula4_b.set_fill_color(Color::white);
	attach(spatula4_b);
	spatula5_b.set_fill_color(Color::white);
	attach(spatula5_b);
	spatula6_b.set_fill_color(Color::white);
	attach(spatula6_b);
	spatula7_b.set_fill_color(Color::white);
	attach(spatula7_b);
	spatula8_b.set_fill_color(Color::white);
	attach(spatula8_b);
	
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
}
//------------------------------------------------------------------------------
bool gameplayscene::spatula2()
{
	spatula2_pushed = true;
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
void gameplayscene::cb_quit(Address, Address pw)
{
	reference_to<gameplayscene>(pw).quit();
}

void gameplayscene::cb_spatula1(Address, Address a)
{
	reference_to<gameplayscene>(a).spatula1();
}

//------------------------------------------------------------------------------

void gameplayscene::cb_spatula2(Address, Address b)
{
	reference_to<gameplayscene>(b).spatula2();
}

//------------------------------------------------------------------------------

void gameplayscene::cb_spatula3(Address, Address c)
{
	reference_to<gameplayscene>(c).spatula3();
}

//------------------------------------------------------------------------------

void gameplayscene::cb_spatula4(Address, Address d)
{
	reference_to<gameplayscene>(d).spatula4();
}

//------------------------------------------------------------------------------

void gameplayscene::cb_spatula5(Address, Address e)
{
	reference_to<gameplayscene>(e).spatula5();
}

//------------------------------------------------------------------------------

void gameplayscene::cb_spatula6(Address, Address f)
{
	reference_to<gameplayscene>(f).spatula6();
}

//------------------------------------------------------------------------------

void gameplayscene::cb_spatula7(Address, Address g)
{
	reference_to<gameplayscene>(g).spatula7();
}

//------------------------------------------------------------------------------

void gameplayscene::cb_spatula8(Address, Address h)
{
	reference_to<gameplayscene>(h).spatula8();
}

//------------------------------------------------------------------------------

void gameplayscene::draw_pancake(int y, int size)
{
	Ellipse e {Point(400, y), size*30+170, size*3+17};
	e.set_fill_color(Color::yellow);
	e.set_color(Color::yellow);
}