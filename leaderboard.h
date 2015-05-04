#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include "std_lib_facilities_4.h"
#include "score_entry.h"
#include "Leaderboard_window.h"

class Leaderboard{
public:
	bool is_lower(const score_entry&, const score_entry&);
	
    vector<score_entry> get_leaderboard(void);
    void set_leaderboard(score_entry &s);
    void disp_leaderboard();
};



#endif
