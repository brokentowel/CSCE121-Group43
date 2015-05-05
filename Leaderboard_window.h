#ifndef LEADERBOARDH_GUARD
#define LEADERBOARDH_GUARD

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include "Window.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Leaderboard_window : Graph_lib::Window {
    Leaderboard_window(Point xy, int w, int h, const string& title );
	
    bool wait_for_button(); // simple event loop

protected:

    Button back_button;
    bool back_pushed;
    Rectangle bg;
    Text text;
	
    static void cb_back(Address, Address);
	
	void back();
};

//------------------------------------------------------------------------------

#endif // LEADERBOARDH_GUARD
