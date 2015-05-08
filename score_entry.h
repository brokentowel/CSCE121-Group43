#ifndef SCORE_ENTRY_H
#define SCORE_ENTRY_H
#include "std_lib_facilities_4.h"

//type to describe a user and his/her score
class score_entry
{
  public:
	string initials; 
	int score;
	void set_init(string& init){initials = init;}
};

#endif
