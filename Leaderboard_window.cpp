/*
   Leaderboard_window.cpp
   Revised form of Simple_window.cpp to conform to project needs
   Kenneth Payne		5/2/2015
*/

#include "Splash_screen.h"
#include "Leaderboard_window.h"
#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include "Window.h"
#include "std_lib_facilities_4.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

Leaderboard_window::Leaderboard_window(Point xy, int w, int h, const string& title, string initials, int final_score) :
    Window(xy,w,h,title),
    back_button(Point(0, 0), 50, 20, "Back", cb_back),
	back_pushed(false)
{
	Text* text_score;
	text_score = new Text(Point(50, 50), "Final score: " + std::to_string(final_score));	// I have to create a pointer to text for some reason
	text_score->set_font_size(30);
	text_score->set_color(Color::white);
	attach(*text_score);
	
	set_leaderboard(score_entry{initials, final_score});
	
	attach(back_button);
	vector<Text*> all_scores;
	ifstream ist {"scores.txt"}; // ist reads from the file named iname
	if (!ist) error("can't open input file ");
	string entry;
	for(int i = 0; i<5;++i)
	{
		getline(ist, entry);
		all_scores.push_back(new Text(Point(130,130+(i*25)),entry));
		all_scores[i]->set_font_size(30);
		all_scores[i]->set_color(Color::white);
		attach(*all_scores[i]);
	}
	ist.close();

	wait_for_button();
}

Leaderboard_window::Leaderboard_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    back_button(Point(0, 0), 50, 20, "Back", cb_back),
	back_pushed(false)
{
	attach(back_button);
	vector<Text*> all_scores;
	ifstream ist {"scores.txt"}; // ist reads from the file named iname
	if (!ist) error("can't open input file ");
	string entry;
	for(int i = 0; i<5;++i)
	{
		getline(ist, entry);
		all_scores.push_back(new Text(Point(130,130+(i*25)),entry));
		all_scores[i]->set_font_size(30);
		all_scores[i]->set_color(Color::white);
		attach(*all_scores[i]);
	}
	ist.close();

	wait_for_button();
}

bool Leaderboard_window::is_lower(const score_entry& x, const score_entry& y) { return x.score > y.score; }

void Leaderboard_window::set_leaderboard(const score_entry& s)
{
	cout << s.initials << "!!" << endl;
	vector<score_entry> scores;
		
	//read current leaderboard from leaderboard.txt
	ifstream ist {"scores.txt"}; 
	if (!ist) error("can't open input file ");
	string init;
	int score;
	while(ist >> init >> score)
	{
		scores.push_back(score_entry{init,score});
	}
	ist.close();
	//insert player's score into the vector 
	scores.push_back(s);
	//sort the vector
	sort_scores(scores);	//sort(scores.begin(), scores.end());
	//write top 5 scores back to scores.txt	
	ofstream ost {"scores.txt"};
	for (int i = 0; i < scores.size()-1; i++)
	{
		ost << scores[i].initials << '\t' << scores[i].score << "\r\n";		
	}        
	ost.close();
}

void Leaderboard_window::sort_scores(vector<score_entry> &scores)
{
      int i, j, flag = 1;    // set flag to 1 to start first pass
      int temp;             // holding variable
	  string temp_s;
      int array_length = scores.size(); 
      for(i = 1; (i <= array_length) && flag; i++)
     {
          flag = 0;
          for (j=0; j < (array_length -1); j++)
         {
               if (scores[j+1].score > scores[j].score)      // ascending order simply changes to <
              { 
                    temp = scores[j].score;             // swap elements
					temp_s = scores[j].initials; 
                    scores[j].score = scores[j+1].score;
					scores[j].initials = scores[j+1].initials;
                    scores[j+1].score = temp;
					scores[j+1].initials = temp_s;
                    flag = 1;               // indicates that a swap occurred.
               }
          }
     }
     return;   //arrays are passed to functions by address; nothing is returned
}

void Leaderboard_window::back()
{
	back_pushed = true;
	hide();
	Splash_screen splash(Point(100,200),800,600,"FlipFlaps");
    wait_for_button();
}

bool Leaderboard_window::wait_for_button() //need to get red x to work
{
    //show();
    back_pushed = false;
#if 1
    // Simpler handler
    while (!back_pushed) Fl::wait();
    Fl::redraw();
#else
    // To handle the case where the user presses the X button in the window frame
    // to kill the application, change the condition to 0 to enable this branch.
    Fl::run();
#endif
    //return button_pushed;
}

void Leaderboard_window::cb_back(Address, Address b)
{
	reference_to<Leaderboard_window>(b).back();
}