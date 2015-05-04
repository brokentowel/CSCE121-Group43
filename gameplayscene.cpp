/*
gameplayscene.cpp
*/

#include "gameplayscene.h"
#include "Graph.h"

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
spatula8_pushed(false),
pancake1(Point(375, 560), 50, 40),
pancake2(Point(350, 520), 100, 40),
pancake3(Point(325, 480), 150, 40),
pancake4(Point(300, 440), 200, 40),
pancake5(Point(275, 400), 250, 40),
pancake6(Point(250, 360), 300, 40),
pancake7(Point(225, 320), 350, 40),
pancake8(Point(200, 280), 400, 40),
pancake9(Point(175, 240), 450, 40)

{
	a = 0;
	b = 0;
	c = 0;
	srand( unsigned ( time(0)));
	vector<int>pancakeheights = {560,520,480,440,400,360,320,280,240};
	random_shuffle (pancakeheights.begin(),pancakeheights.end());
    a = pancakeheights.at(0);
	cout << a;
	b = pancakeheights.at(1);
	cout << b;
	c = pancakeheights.at(2);
	cout << c;
	d = pancakeheights.at(3);
	cout << d;
	e = pancakeheights.at(4);
	f = pancakeheights.at(5);
	g = pancakeheights.at(6);
	h = pancakeheights.at(7);
	i = pancakeheights.at(8);
	
	int hp1 = a-560;
	int hp2 = b-520;
	int hp3 = c-480;
	int hp4 = d-440;
	int hp5 = e-400;
	int hp6 = f-360;
	int hp7 = g-320;
	int hp8 = h-280;
	int hp9 = i-240;
	
	pancake1.move(0,hp1);
	pancake2.move(0,hp2);
	pancake3.move(0,hp3);
	pancake4.move(0,hp4);
	pancake5.move(0,hp5);
	pancake6.move(0,hp6);
	pancake7.move(0,hp7);
	pancake8.move(0,hp8);
	pancake9.move(0,hp9);
	
	
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
	
	attach(pancake1);
	pancake1.set_fill_color(Color::yellow);
	attach(pancake2);
	pancake2.set_fill_color(Color::yellow);
	attach(pancake3);
	pancake3.set_fill_color(Color::yellow);
	attach(pancake4);
	pancake4.set_fill_color(Color::yellow);
	attach(pancake5);
	pancake5.set_fill_color(Color::yellow);
	attach(pancake6);
	pancake6.set_fill_color(Color::yellow);
	attach(pancake7);
	pancake7.set_fill_color(Color::yellow);
	attach(pancake8);
	pancake8.set_fill_color(Color::yellow);
	attach(pancake9);
	pancake9.set_fill_color(Color::yellow);
	
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
