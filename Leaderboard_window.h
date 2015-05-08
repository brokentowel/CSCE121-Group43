#ifndef LEADERBOARDH_GUARD
#define LEADERBOARDH_GUARD

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include "Window.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Leaderboard_window : Graph_lib::Window {
    Leaderboard_window(Point xy, int w, int h, const string& title );
	Leaderboard_window(Point xy, int w, int h, const string& title, string initials, int final_score );
	
    bool wait_for_button(); // simple event loop

protected:

    Button back_button;
    bool back_pushed;
	
	struct score_entry { string initials; int score; };
	bool is_lower(const score_entry&, const score_entry&);
	
	void set_leaderboard(const score_entry& s);
	void sort_scores(vector<score_entry>&);
	
	Rectangle bg;
	Rectangle back_rect;
	
    //add rectangle for bg
    //add text so we can write
	
    static void cb_back(Address, Address);
	
	void back();
	
	vector<score_entry> scores;
};

//------------------------------------------------------------------------------

#endif // LEADERBOARDH_GUARD
