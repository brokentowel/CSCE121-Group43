#ifndef gameplaysceneH_GUARD
#define gameplaysceneH_GUARD

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include "std_lib_facilities_4.h"
#include "find_solution.h"
/*
Color c_pancake(fl_rgb_color(255, 218, 148));
Color c_pancake_outline(fl_rgb_color(191, 163, 111));
Color c_cyan(fl_rgb_color(112, 186, 235));
Color c_dark_blue(fl_rgb_color(6, 83, 138));
*/

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct gameplayscene : Graph_lib::Window {
	gameplayscene(Point xy, int w, int h, const string& title, int);

	bool wait_for_button(); // simple event loop
	
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	int g;
	int h;
	int i;
	
	Rectangle pancake1;
	Rectangle pancake2;
	Rectangle pancake3;
	Rectangle pancake4;
	Rectangle pancake5;
	Rectangle pancake6;
	Rectangle pancake7;
	Rectangle pancake8;
	Rectangle pancake9;
	/*
	vector<Rectangle> pancakeswoheight;
	vector<Rectangle> pancakeswithheight;
	vector<int> pancakeheights;
	*/
	Rectangle quit_b;
	Rectangle undo_b;
	Rectangle spatula1_b;
	Rectangle spatula2_b;
	Rectangle spatula3_b;
	Rectangle spatula4_b;
	Rectangle spatula5_b;
	Rectangle spatula6_b;
	Rectangle spatula7_b;
	Rectangle spatula8_b;
	Rectangle background_with_color;
	
protected:
	//set window background color to cyan <code>
	Button quit_button;
	bool quit_pushed;
	Button spatula1_button;     //spatula button
	bool spatula1_pushed;     
	Button spatula2_button;     
	bool spatula2_pushed;
	Button spatula3_button;      
	bool spatula3_pushed;
	Button spatula4_button;
	bool spatula4_pushed;
	Button spatula5_button;
	bool spatula5_pushed;
	Button spatula6_button;
	bool spatula6_pushed;
	Button spatula7_button;
	bool spatula7_pushed;
	Button spatula8_button;
	bool spatula8_pushed;
	Button undo_button;
	bool undo_pushed;

	static void cb_quit(Address, Address); // callback for play_button
	static void cb_spatula1(Address, Address); //callback for spatula button
	static void cb_spatula2(Address, Address); 
	static void cb_spatula3(Address, Address);
	static void cb_spatula4(Address, Address);
	static void cb_spatula5(Address, Address);
	static void cb_spatula6(Address, Address);
	static void cb_spatula7(Address, Address);
	static void cb_spatula8(Address, Address);
	static void cb_undo(Address, Address);

	void quit();
	void spatula1();            // action to be done when spatula button is pressed
	bool spatula2();
	void spatula3();
	void spatula4();
	void spatula5();
	void spatula6();
	void spatula7();
	void spatula8();
	void undo();
	
public:
	// void new_player(String& s);
	void set_difficulty(int);
	void generate_stack(int);
	void print_stack(void);
	void swap(int, int);
	void flip(int, int);
	void cycle(void);
	void check(void);
	int get_minimum_steps(void);
	int calculate_score(void);
	void move(void);
	
	vector<int> get_stack(void);

private:
	vector<int> pancake_stack;	// assume index 0 to be top of stack
	vector<int> user_steps;
	int difficulty;
	bool game_play;
	bool game_running;
	int minimum_steps;

};

//------------------------------------------------------------------------------

#endif // gameplaysceneH_GUARD
