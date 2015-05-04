/*
#include "std_lib_facilities_4.h"
#include "score_entry.h"
#include "Leaderboard_window.h"

class Leaderboard{
public:
    bool is_lower(const score_entry& x, const score_entry& y) { return x.score < y.score; }
	
//-------------------------------------------------------------------------------------    
    void set_leaderboard(score_entry &s)
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
    	
    	//write the top 5 scores back to the txt file
    	ofstream ost {"scores.txt"};
    	scores[6]=s;
    	sort(scores.begin(), scores.end(), is_lower);
    	for (int i = 0; i < scores.size()-1; i++)
    	{
    		ost << scores[i].initials << "	" << scores[i].score << "\n";		
    	}        
    	ost.close();
    }
//-------------------------------------------------------------------------------------
    	//extract each score as a line of initials and score
	void get_leaderboard()
	{
		  vector<Text*> all_scores;
		  ifstream ist {"scores.txt"}; // ist reads from the file named iname
		  if (!ist) error("can't open input file ");
		  string line;
		for(int i = 0; i<5;++i)
		{
			getline(ist,line);
			string temp = to_string(1+i) + ") " + line;
			all_scores.push_back(new Text{Point{130,130+(i*25)},temp});
			all_scores[i]->set_font_size(30);
			all_scores[i]->set_color(Color::white);
			attach(*scores[i]);
		}
		ist.close();
	}
void disp_leaderboard()
     {
           //create a leaderboard window  that pops up until user closes it    200x300 window of just leaderboard
         Leaderboard_window win_ldr(Point{100,100},250,300)
         {
		Rectangle bg {Point{125,125},200,275};
		bg.set_fill_color(Color::black);
		bg.set_color(Color::invisible);	

 	    	win_ldr.attach(bg);
 	    	
 	    	get_leaderboard();

 	    	win_ldr.wait_for_button();
	    	
         }
     }
 };
*/