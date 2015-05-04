/*
gameplayscene.cpp Mine
*/

#include "std_lib_facilities_4.h"
#include "classes.h"
#include "gameplayscene.h"
#include "Graph.h"
#include "Window.h"
#include "find_solution.h"
#include <random>
#include <chrono>
#include "score_entry.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

gameplayscene::gameplayscene(Point xy, int w, int h, const string& title, int diff) :
	Window(xy, w, h, title),
	background_with_color(Point(0,0),800,600),
	quit_button(Point(729, 0), 70, 30, "Quit", cb_quit),
	quit_b(Point(729,0),70,30),
	undo_button(Point(0, 0), 70, 30, "Undo", cb_undo),
	undo_b(Point(0,0),70,30),
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
	attach(undo_button);
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
	
	cout << "Game constructed" << endl;
	
	game_running = true;
	
	char input;
	
	difficulty = diff;
	
	while (game_running)
	{
		game_play = true;
		
		generate_stack(difficulty);
		
		minimum_steps = get_minimum_steps();
		
		cycle();
		game_play = false;
		cout << "You beat the game!" << endl;
		cout << "It took you " << user_steps.size() << " steps!" << endl;
		cout << "Score: " << calculate_score() << endl;
		cout << "Would you like to play again? [Y/N]";
		cin >> input;
		if (input == 'N' || input == 'n') { break; }
	}
}
//------------------------------------------------------------------------------
void gameplayscene::quit()
{
	hide();
}
//------------------------------------------------------------------------------
void gameplayscene::undo()
{
	flip(user_steps[user_steps.size() - 1], 0);
	user_steps.pop_back();
	print_stack();
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

void gameplayscene::cb_undo(Address, Address q)
{
	reference_to<gameplayscene>(q).undo();
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

/*
void gameplayscene::draw_pancake(int y, int size)
{
	Ellipse e {Point(400, y), size*30+170, size*3+17};
	e.set_fill_color(Color::yellow);
	e.set_color(Color::yellow);
}
*/
/*
//create new player
void Game::new_player(String& s)
{
	score_entry player_score = new score_entry;
	player_score.initials = s;
}
*/

// handles abstract game mechanics
void Game::set_difficulty(int n)
{
	this->difficulty = n;
	cout << "Difficulty set to: " << this->difficulty << endl;
}

// generates random stack of pancakes
void gameplayscene::generate_stack(int d)
{
	// fills vectors with numbers
	for(int i = 0; i < d; ++i) { pancake_stack.push_back(i + 1); }
	
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();				// generates a time-based seed
	shuffle(pancake_stack.begin(), pancake_stack.end(), default_random_engine(seed));	// generates a random permutation of vector
}

// displays the order of pancakes
void gameplayscene::print_stack(void)
{
	for(int i = 0; i < pancake_stack.size(); ++i) { cout << pancake_stack[i] << "\t"; }
	cout << endl;
}

// swaps elements a and b in the vector
void gameplayscene::swap(int a, int b)
{
	int temp = pancake_stack[a];
	pancake_stack[a] = pancake_stack[b];
	pancake_stack[b] = temp;
}

// flips the order of pancakes from element i to the last element
void gameplayscene::flip(int i, int c)	// c is used to gradually move from the last element inwards
{	
	if(c < i)
	{
		swap(c, i);
		flip(i - 1, c + 1);
	}
	
	return;
}

// cyclical process used for the game
void gameplayscene::cycle(void)
{	
	while(game_play)
	{	
		if (pancake_stack.size() > minimum_steps + 10) { break; }	// this would result in a negative score, at which point the game ends
		wait_for_button();
		/*
		{
			user_steps.push_back(x - 1);
			flip(x - 1, 0);
			print_stack();
			check();
		}
		*/
	}
}

// TO BE USED WITH SPATULA TO ACTUALLY DO MOVE; IT FLIPS PANCAKES, X IS THE SPATULA POSITION
/*
void gameplayscene::move(void)
{
	user_steps.push_back(x - 1);
	flip(x - 1, 0);
	check();
}
*/

// checks if pancake_stack array is in proper order
void gameplayscene::check(void)
{
	for (int i = 0; i < pancake_stack.size() - 1; ++i)
	{
		if(pancake_stack[i] > pancake_stack[i+1])
			return;
	}
	
	game_play = false;
}

// returns the minimum amount of steps to complete the game
int gameplayscene::get_minimum_steps()
{
	cout << "dere" << endl;
	return find_solution(pancake_stack)->size();	// since find_solution() returns a pointer to an array, we must use -> to access the member function
}

// calculates score
int gameplayscene::calculate_score()
{
	return (100 - 10 * (user_steps.size() - minimum_steps)) * difficulty;
}

// ----------------------------------------------------------------
// methods for access

vector<int> gameplayscene::get_stack()
{
	return pancake_stack;
}