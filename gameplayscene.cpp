/*
gameplayscene.cpp
*/

#include "gameplayscene.h"
#include "Graph.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

gameplayscene::gameplayscene(Point xy, int w, int h, const string& title, int d, string inititals) :
Window(xy, w, h, title),
background_with_color(Point(0,0),800,600),
quit_button(Point(729, 0), 70, 30, "Quit", cb_quit),
quit_b(Point(729,0),70,30),
undo_button(Point(0, 0), 70, 30, "Undo", cb_undo),
undo_b(Point(0, 0), 70, 30),
spatula1_button(Point(0, 560), 50, 30, "1", cb_spatula1),
spatula1_b(Point(0,560),50,30),
//spatula1_pushed(false),
spatula2_button(Point(0, 520), 50, 30, "2", cb_spatula2),
spatula2_b(Point(0,520),50,30),
//spatula2_pushed(false),
spatula3_button(Point(0, 480), 50, 30, "3", cb_spatula3),
spatula3_b(Point(0,480),50,30),
//spatula3_pushed(false),
spatula4_button(Point(0, 440), 50, 30, "4", cb_spatula4),
spatula4_b(Point(0,440),50,30),
//spatula4_pushed(false),
spatula5_button(Point(0, 400), 50, 30, "5", cb_spatula5),
//spatula5_pushed(false),
spatula5_b(Point(0,400),50,30),
spatula6_button(Point(0, 360), 50, 30, "6", cb_spatula6),
spatula6_b(Point(0,360),50,30),
//spatula6_pushed(false),
spatula7_button(Point(0, 320), 50, 30, "7", cb_spatula7),
spatula7_b(Point(0,320),50,30),
//spatula7_pushed(false),
spatula8_button(Point(0, 280), 50, 30, "8", cb_spatula8),
spatula8_b(Point(0,280),50,30)
//spatula8_pushed(false),

{

	background_with_color.set_fill_color(Color::cyan);
	attach(background_with_color);
	attach(quit_button);
	attach(undo_button);
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
	undo_b.set_fill_color(Color::green);
	attach(undo_b);
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
	
	create_stack(d);
	
}
//------------------------------------------------------------------------------
void gameplayscene::testforwin()
{
	if (randompancakes[8]==9 && randompancakes[7]==8 && randompancakes[6]==7 && randompancakes[5]==6 && randompancakes[4]==5 && randompancakes[3]==4 && randompancakes[2]==3 && randompancakes[1]==2 && randompancakes[0]==1)
	{
		cout << "you win!" << "\n";
	}
}

void gameplayscene::create_stack(int diff)
{
	int h = 560;
	randompancakes = randomize_pancakes(diff);
	for (int i = 0; i < diff; ++i)
	{
		pancake_stack.push_back(new pancake(Point(400-(25*randompancakes[i]),h-(40*i)),50*randompancakes[i],40));
		h=560;
	}
	draw_pancakes();
}

vector <int> gameplayscene::randomize_pancakes(int diff){
	for (int i = 1; i <=diff; ++i){
		randomstackintegers.push_back(i);
	}
	srand( unsigned ( time(0)));
	random_shuffle (randomstackintegers.begin(),randomstackintegers.end());
	return randomstackintegers;
}

void gameplayscene::draw_pancakes(){
	for (int i = 0; i < pancake_stack.size(); ++i){
		pancake_stack[i]->set_fill_color(Color::yellow);
		attach(*pancake_stack[i]);
	}
}
void gameplayscene::quit()
{
	hide();
}

void gameplayscene::undo()
{
	if (user_steps.size() > 0)
	{
		flip(user_steps[user_steps.size() - 1]);
		user_steps.pop_back();
	}
}
//------------------------------------------------------------------------------

void gameplayscene::flip(int x){
	int psize = pancake_stack.size()-x;
	if (psize % 2 == 0)
	{
		for (int i=1;i<=psize/2;++i)
		{
		int j = 0;
		pancake_stack[psize-i]->move(0,40*(psize-(j)));
		pancake_stack[0+(psize-1)]->move(0,-40*(psize+(j)));
		swap(pancake_stack[0+(i-1)],pancake_stack[psize-i]);
		swap(randompancakes[0+(i-1)],randompancakes[psize-i]);
		++j;
		}
	}
	else 
	{
		for (int i=1;i<psize/2-1;++i)
		{
		pancake_stack[psize-i]->move(0,40*(psize-i));
		pancake_stack[0+(i-1)]->move(0,-40*(psize-i));
		swap(pancake_stack[0+(i-1)],pancake_stack[psize-i]);
		swap(randompancakes[0+(i-1)],randompancakes[psize-i]);
		}
	}
	redraw();
}

//------------------------------------------------------------------------------
void gameplayscene::spatula1()
{
	user_steps.push_back(0);
	flip(0);
}
void gameplayscene::spatula2()
{
	user_steps.push_back(1);
	flip(1);
}
//------------------------------------------------------------------------------
void gameplayscene::spatula3()
{
	user_steps.push_back(2);
	flip(2);
}
//------------------------------------------------------------------------------ 
void gameplayscene::spatula4()
{
	user_steps.push_back(3);
	flip(3);
}
void gameplayscene::spatula5()
{
	user_steps.push_back(4);
	flip(4);
}
void gameplayscene::spatula6()
{
	user_steps.push_back(5);
	flip(5);
}
void gameplayscene::spatula7()
{
	user_steps.push_back(6);
	flip(6);
}
void gameplayscene::spatula8()
{
	user_steps.push_back(7);
	flip(7);
}
bool gameplayscene::wait_for_button() //need to get red x to work
{
	show();
	quit_pushed = false;
#if 1
	// Simpler handler
	while (/*/*!spatula1_pushed && !spatula2_pushed && !spatula3_pushed && !spatula4_pushed && !spatula4_pushed && !spatula5_pushed && !spatula6_pushed && !spatula7_pushed && !spatula8_pushed */true) Fl::wait();
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

void gameplayscene::cb_undo(Address, Address u)
{
	reference_to<gameplayscene>(u).undo();
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
