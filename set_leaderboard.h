#ifndef SETLEADERBOARDH_GUARD
#define SETLEADERBOARDH_GUARD

#include "std_lib_facilities_4.h"

bool is_lower(const score_entry& x, const score_entry& y) { return x.score > y.score; }

void set_leaderboard(score_entry& s)
{
		vector<score_entry> scores;
		
	//read current leaderboard from leaderboard.txt
		ifstream ist {"scores.txt"}; 
		if (!ist) error("can't open input file ");
		string initials;
		int score;
		while(ist >> initials >> score)
		{
			scores.push_back(score_entry{initials,score});
		}
		ist.close();
	//insert player's score into the vector 
		scores.push_back(s);
	//sort the vector
		sort(scores.begin(), scores.end(), is_lower);
	//write top 5 scores back to scores.txt	
		ofstream ost {"scores.txt"};
		for (int i = 0; i < scores.size()-1; i++)
		{
			ost << scores[i].initials << '\t' << scores[i].score << "\r\n";		
		}        
		ost.close();
}

#endif
