/*
gameplayscene.cpp
*/

#include "gameplayscene.h"
#include "Graph.h"
#include "find_solution.h"
#include "Leaderboard_window.h"
#include "colors.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

gameplayscene::gameplayscene(Point xy, int w, int h, const string& title, int d, string initials) :
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
spatula8_b(Point(0,280),50,30),
//spatula8_pushed(false),
bg(Point(0, 0), "small_logo.jpg")
{
	Color pancake(fl_rgb_color(232, 215, 137));
	Color dark_pancakes(fl_rgb_color(207, 191, 122));
	Color background_blue(fl_rgb_color(122, 138, 207));
	Color dark_background_blue(fl_rgb_color(107, 121, 181));
	
	background_with_color.set_fill_color(game_blue);
	attach(background_with_color);
	attach(bg);
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
	
	undo_b.set_fill_color(dark_blue);
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
	
	player_initials = initials;
	
	create_stack(d);
	
}
//------------------------------------------------------------------------------
//checks if you won
void gameplayscene::win(void)
{
	hide();
	int score = calculate_score();
	Leaderboard_window leaders(Point(100,200),400,300,"Leaderboard", player_initials, score);
	wait_for_button();
}

void gameplayscene::testforwin(void)
{
	for (int i=0; i < randompancakes.size()-1; ++i)
	{
		if (randompancakes[i] < randompancakes[i+1])
		{
			return;
		}
	}
	win();
}

int gameplayscene::calculate_score()
{
	return (100 - 10 * (user_steps.size() - get_minimum_steps())) * randompancakes.size();
}

//create pancakes
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

void gameplayscene::undo()
{
	if (user_steps.size() > 0)
	{
		flip(user_steps[user_steps.size() - 1]);
		user_steps.pop_back();
	}
}


//get the randomization
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
		pancake_stack[i]->set_fill_color(pancake_color);
		pancake_stack[i]->set_color(toasty);
		attach(*pancake_stack[i]);
	}
}
void gameplayscene::quit()
{
	hide();
}
//------------------------------------------------------------------------------

void gameplayscene::flip(int x){
	int psize = pancake_stack.size()-x;
	if (psize % 2 == 0)
	{
		for (int i=1;i<=psize/2;++i)
		{
		int ho = 40*(psize-1);
		int drop = ho-80*(i-1);
		pancake_stack[pancake_stack.size()-i]->move(0,drop);
		pancake_stack[i-1+x]->move(0,-1*drop);
		std::swap(pancake_stack[i-1+x],pancake_stack[pancake_stack.size()-i]);
		swap(randompancakes[i-1+x],randompancakes[randompancakes.size()-i]);
		}
	}
	else if (psize % 2 == 1)
	{
		for (int i=1;i<=psize/2+1;++i)
		{
		int ho = 40*(psize-1);
		int drop = ho-80*(i-1);
		pancake_stack[pancake_stack.size()-i]->move(0,drop);
		pancake_stack[i-1+x]->move(0,-1*drop);
		std::swap(pancake_stack[i-1+x],pancake_stack[pancake_stack.size()-i]);
		swap(randompancakes[i-1+x],randompancakes[randompancakes.size()-i]);
		}
	}
	
	redraw();

}

int gameplayscene::get_minimum_steps()
{
	return find_solution(randomstackintegers)->size();	// since find_solution() returns a pointer to an array, we must use -> to access the member function
}

void gameplayscene::cycle()
{
	testforwin();
	// # of flips that it can be done in, current score, and a flip counter
}

//------------------------------------------------------------------------------
void gameplayscene::spatula1()
{
	user_steps.push_back(0);
	flip(0);
	cycle();
}
void gameplayscene::spatula2()
{
	user_steps.push_back(1);
	flip(1);
	cycle();
}
//------------------------------------------------------------------------------
void gameplayscene::spatula3()
{
	user_steps.push_back(2);
	flip(2);
	cycle();
}
//------------------------------------------------------------------------------ 
void gameplayscene::spatula4()
{
	user_steps.push_back(3);
	flip(3);
	cycle();
}
void gameplayscene::spatula5()
{
	user_steps.push_back(4);
	flip(4);
	cycle();
}
void gameplayscene::spatula6()
{
	user_steps.push_back(5);
	flip(5);
	cycle();
}
void gameplayscene::spatula7()
{
	user_steps.push_back(6);
	flip(6);
	cycle();
}
void gameplayscene::spatula8()
{
	user_steps.push_back(7);
	flip(7);
	cycle();
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

void gameplayscene::cb_undo(Address, Address u)
{
	reference_to<gameplayscene>(u).undo();
}