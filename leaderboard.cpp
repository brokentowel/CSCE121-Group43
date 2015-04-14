// handles the score system and the leaderboard elements
class leaderboard
{
    // data structure for scores with initials, consider using an enumeration of structs to hold position
    struct score_entry { string initials; int score; };
    
    // function for comparing two score_entry
    bool is_lower(const score_entry& x, const score_entry& x) { return x.score < y.score; }
    
    // vector to hold scores in position
    vector<score_entry> scores[6];
    
    // return high scores 
    vector<score_entry> get_high_scores() { return scores; }
    
    // add a new high score
    void set_leaderboard(score_entry &s)
    {
        ofstream ost {"scores.txt"};
        ifstream ist {"scores.txt"}; // ist reads from the file named iname
        if (!ist) error("can't open input file ",iname);
        string initials;
        int score;
        while(ist >> initials >> score)
        {
            scores.push_back(score_entry{name,score});
        }
        ost.close();
        scores[6]=s;
        sort(scores.begin(), scores.end(), is_lower);
        
        for (i=0;i<scores.size(),i++)
        {
                //write this shit to a file
        }
        
       
        
        
        
    }
    
    
  

    
    // returns initals of certain score
    string get_initials() { return score_entry.initials; }
    
    // sets initials of certain score
    void write_high_score() { return; }
    
    //write top 5 scores to file and save it
    ifstream ist {"scores.txt"};
};






