#ifndef Splash_screenH_GUARD
#define Splash_screenH_GUARD

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include "Leaderboard_window.h"

/*
Color c_pancake(fl_rgb_color(255, 218, 148));
Color c_pancake_outline(fl_rgb_color(191, 163, 111));
Color c_cyan(fl_rgb_color(112, 186, 235));
Color c_dark_blue(fl_rgb_color(6, 83, 138));
*/

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Splash_screen : Graph_lib::Window {
    Splash_screen(Point xy, int w, int h, const string& title );

    bool wait_for_button(); // simple event loop

protected:
    //something to set the color of the window/background to c_cyan
    // <code>
	
	Image bg;
	
    Button quit_button;
	bool quit_pushed;
    Button rules_button;     // the "rules" button  HINT(we can cover the buttons with shapes and they still work!)
    bool rules_pushed;     // implementation detail
    Button play_button;     //button to start game
    bool play_pushed;
    Button ldr_button;      //button to open current leaderboard window
    bool ldr_pushed;
	
	Button difficulty2_button;
	Button difficulty3_button;
	Button difficulty4_button;
	Button difficulty5_button;
	Button difficulty6_button;
	Button difficulty7_button;
	Button difficulty8_button;
	Button difficulty9_button;
	bool difficulty2_pushed;
	bool difficulty3_pushed;
	bool difficulty4_pushed;
	bool difficulty5_pushed;
	bool difficulty6_pushed;
	bool difficulty7_pushed;
	bool difficulty8_pushed;
	bool difficulty9_pushed;
	
	Button rules_back_button;
	bool rules_back_button_pushed;

	static void cb_quit(Address, Address);
    static void cb_rules(Address, Address); // callback for play_button
    static void cb_play(Address, Address); // callback for play_button
    static void cb_ldr(Address, Address); // callback for play_button
	
	static void cb_difficulty2(Address, Address);
	static void cb_difficulty3(Address, Address);
	static void cb_difficulty4(Address, Address);
	static void cb_difficulty5(Address, Address);
	static void cb_difficulty6(Address, Address);
	static void cb_difficulty7(Address, Address);
	static void cb_difficulty8(Address, Address);
	static void cb_difficulty9(Address, Address);
	
	static void cb_rules_back(Address, Address);
    
    void quit();
	void rules();            // action to be done when next_button is pressed
    bool play();
    void ldr();
	
	void difficulty2();
	void difficulty3();
	void difficulty4();
	void difficulty5();
	void difficulty6();
	void difficulty7();
	void difficulty8();
	void difficulty9();
	
	void rules_back();
	
	//---------------------------------------------
	
	In_box initials_box;
	Button initials_button;
	bool initials_pushed;
	
	static void cb_initials(Address, Address);
	void play_initials();
};

//------------------------------------------------------------------------------

#endif // Splash_screenH_GUARD
