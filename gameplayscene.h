#ifndef gameplaysceneH_GUARD
#define gameplaysceneH_GUARD

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"

/*
Color c_pancake(fl_rgb_color(255, 218, 148));
Color c_pancake_outline(fl_rgb_color(191, 163, 111));
Color c_cyan(fl_rgb_color(112, 186, 235));
Color c_dark_blue(fl_rgb_color(6, 83, 138));
*/

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct gameplayscene : Graph_lib::Window {
	gameplayscene(Point xy, int w, int h, const string& title);

	bool wait_for_button(); // simple event loop

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

	static void cb_quit(Address, Address); // callback for play_button
	static void cb_spatula1(Address, Address); //callback for spatula button
	static void cb_spatula2(Address, Address); 
	static void cb_spatula3(Address, Address);
	static void cb_spatula4(Address, Address);
	static void cb_spatula5(Address, Address);
	static void cb_spatula6(Address, Address);
	static void cb_spatula7(Address, Address);
	static void cb_spatula8(Address, Address);

	void quit();
	void spatula1();            // action to be done when spatula button is pressed
	bool spatula2();
	void spatula3();
	void spatula4();
	void spatula5();
	void spatula6();
	void spatula7();
	void spatula8();

};

//------------------------------------------------------------------------------

#endif // gameplaysceneH_GUARD
