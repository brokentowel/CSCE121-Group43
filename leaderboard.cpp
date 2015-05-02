#include "std_lib_facilities_4.h"

/*
// handles the score system and the leaderboard elements
class leaderboard
{
    // data structure for scores with initials, consider using an enumeration of structs to hold position
    struct score_entry { string initials; int score; };
    
    // function to create a score_entry
    void create_user(string& init, int p) 
    {
    	
    }
    
    // function for comparing two score_entry
    // bool is_lower(const score_entry& x, const score_entry& x) { return x.score < y.score; }
    
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
       
    }
   
//create a leaderboard window  that pops up until user closes it    
  

    
    // returns initals of certain score
    string get_initials() { return score_entry.initials; }
    
    // sets initials of certain score
    void write_high_score() { return; }
    
};

*/
