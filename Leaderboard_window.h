#ifndef LEADERBOARDH_GUARD
#define LEADERBOARDH_GUARD

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Leaderboard_window : Graph_lib::Window {
    Leaderboard(Point xy, int w, int h, const string& title );
	
    bool wait_for_button(); // simple event loop

protected:

    Button done_button;
    bool done_pushed;
  
    static void cb_done(Address, Address);
   
    void done();

};

//------------------------------------------------------------------------------

#endif // LEADERBOARDH_GUARD

