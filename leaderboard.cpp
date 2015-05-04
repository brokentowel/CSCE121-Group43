

#include "std_lib_facilities_4.h"
#include "score_entry.h"
#include "leaderboard_window.h"
#include "Graph.h"

class Leaderboard{
public:
    vector<score_entry> get_leaderboard()
    {
        vector<score_entry> scores[6];
    //read current leaderboard from leaderboard.txt
    	ifstream ist {"scores.txt"}; // ist reads from the file named iname
    	if (!ist) error("can't open input file ");
    	string initials;
    	int score;
    	while(ist >> initials >> score)
    	//fill a vector with leaderboard data of score and initials
    	{
    	    scores.push_back(score_entry{initials,score});
    	}
    	ist.close();
    	return scores;
    }
//-------------------------------------------------------------------------------------    
    void set_leaderboard(score_entry &s)
    {

    	vector<score_entry> scores =  get_leaderboard();
    	//write the top 5 scores back to the txt file
    	ofstream ost {"scores.txt"};
    	scores[6]=s;
    	sort(scores.begin(), scores.end(), is_lower);
    	for (i = 0; i < scores.size()-1; i++)
    	{
    		ost << scores[i].initials << "	" << scores[i].score << "\n";		
    	}        
    	ost.close();
    }
//-------------------------------------------------------------------------------------
    //return a vector
    void disp_leaderboard()
    {
          //create a leaderboard window  that pops up until user closes it    200x300 window of just leaderboard
        leaderboard_window win_ldr(Point{100,100},250,300);
        {
        	vector<score_entry> ldr = get_leaderboard();
        	string one = ldr[0].initials;
        	
        	Rectangle bg {Point{125,125},200,275};
        	    bg.set_fill_color(Color::black);
		    	bg.set_color(Color::invisible);	
	    	Text first{Point{130,130}, one};
	    	    first.set_font(FL_COURIER_BOLD);
	    	    first.set_font_size(22);
	    	    first.set_color(Color::white);
	    	win_ldr.attach(bg);
	    	win_ldr.attach(first);
	    	
	    	win_ldr.wait_for_button();
	    	return 0;
        }
    }
};




