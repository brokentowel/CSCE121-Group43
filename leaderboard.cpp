#include "std_lib_facilities_4.h"

class score_entry
{
  public:
	string initials; int score;
	void set_init(string& init){initials = init;}
	string get_init(){return initials;}
	void set_score(int& sc){score = sc;}
	int get_score(){return score;}
};
// handles the score system and the leaderboard elements

// add a new high score
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
	for (i = 0; i < scores.size()-1; i++)
	{
		ost << scores[i].initials << "	" << scores[i].score << "\n";		
	}        
	ost.close()	
};

//return a vector
void disp_leaderboard()
{
	vector<score_entry> scores[6];
    ifstream ist {"scores.txt"}; // ist reads from the file named iname
	if (!ist) error("can't open input file ");
	string initials;
	int score;
	while(ist >> initials >> score)//MAKE THIS A STRING STREAM INSTEAD AND FILL A WINDOW
	//fill a vector with leaderboard data of score and initials
	{
	    scores.push_back(score_entry{initials,score});
	}
	ist.close();	
};
/*   
//create a leaderboard window  that pops up until user closes it    200x300 window of just leaderboard
ldr_window::ldr_window(Point p, int w, int h, const string& t)
	:Window(p,w,h,t),
	to_quit(Point(60,140),80,40,"QUIT", cb_quit),
	quit_button(Point(60,140),80,40)
{
	vector<score_entry> ldr = get_leaderboard();
	//maybe the vector should be the result of a stringstream and each element can be writte on leaderboard
	Text first{Point{25,25},
}
*/
};
