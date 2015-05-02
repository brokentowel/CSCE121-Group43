#include "std_lib_facilities_4.h"

class player
{
  public:
	string initials; int score;
	void set_init();
	void get_init();
	void set_score();
	void get_score();
};
}
/*
// handles the score system and the leaderboard elements
class leaderboard
{
  public:
    // vector to hold scores in position
    vector<score_entry> scores[6];
    
    // return high scores 
    vector<score_entry> get_high_scores() { return scores; }
    
    // add a new high score
    void set_leaderboard(score_entry &s)
    {
    //read current leaderboard from leaderboard.txt
        ifstream ist {"scores.txt"}; // ist reads from the file named iname
        if (!ist) error("can't open input file ",iname);
        string initials;
        int score;
        while(ist >> initials >> score)
        //fill a vector with leaderboard data of score and initials
        {
            scores.push_back(score_entry{initials,score});
        }
        ist.close();
        ofstream ost {"scores.txt"};
        scores[6]=s;
        sort(scores.begin(), scores.end(), is_lower);
        
        for (i = 0; i < scores.size()-1; i++)
        {
		ost << scores[i].initials << "	" << scores[i].score << "\n";		
        }        
	ost.close()	
       
    };
   
//create a leaderboard window  that pops up until user closes it    
leaderboard_window::leaderboard_window(Point p, int w, int h, const string& t)
	:Window(p,w,h,t),
	to_quit(Point(360,460),80,40,"QUIT", cb_quit),
	quit_button(Point(360,460),80,40)
{
	
}
	}
    
    // returns initals of certain score
    string get_initials() { return score_entry.initials; }
    
    // sets initials of certain score
    void write_high_score() { return; }
    
};

*/
