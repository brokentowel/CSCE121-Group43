#ifndef SCORE_ENTRY_H
#define SCORE_ENTRY_H
#include "std_lib_facilities_4.h"

class score_entry
{
  public:
	string initials; 
	int score;
	void set_init(string& init){initials = init;}
	string get_init(){return initials;}
	void set_score(int& sc){score = sc;}
	int get_score(){return score;}
};

#endif
