#ifndef gameplaysceneH_GUARD
#define gameplaysceneH_GUARD

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include "std_lib_facilities_4.h"
#include "pancake.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------
//this class is a window that houses the gmae
class gameplayscene :public Graph_lib::Window{
public:
	
	gameplayscene(Point xy, int w, int h, const string& title, int d, string initials);

	bool wait_for_button(); // simple event loop
	
	void create_stack(int diff);
	void draw_pancakes();
	void flip(int x);
	void testforwin();
	void win();
	int calculate_score();
	
	Image bg;
	
	string player_initials;

	Rectangle quit_b;
	Rectangle undo_b;
	Rectangle spatula1_b;
	Rectangle spatula2_b;
	Rectangle spatula3_b;
	Rectangle spatula4_b;
	Rectangle spatula5_b;
	Rectangle spatula6_b;
	Rectangle spatula7_b;
	Rectangle spatula8_b;
	Rectangle background_with_color;
	
	vector<int> randomize_pancakes(int diff);
	
protected:
	//set window background color to cyan <code>
	Button quit_button;
	bool quit_pushed;
	Button undo_button;
	bool undo_pushed;
	
     //These are the buttons that tell the spatula where to flip
	Button spatula1_button;    
	//bool spatula1_pushed;     
	Button spatula2_button;     
	bool spatula2_pushed;
	Button spatula3_button;      
	bool spatula3_pushed;
	Button spatula4_button;
	bool spatula4_pushed;
	Button spatula5_button;
	bool spatula5_pushed;
	Button spatula6_button;
	bool spatula6_pushed;
	Button spatula7_button;
	bool spatula7_pushed;
	Button spatula8_button;
	bool spatula8_pushed;

	static void cb_quit(Address, Address); // callback for play_button
	static void cb_undo(Address, Address);
	static void cb_spatula1(Address, Address); //callback for spatula button
	static void cb_spatula2(Address, Address); 
	static void cb_spatula3(Address, Address);
	static void cb_spatula4(Address, Address);
	static void cb_spatula5(Address, Address);
	static void cb_spatula6(Address, Address);
	static void cb_spatula7(Address, Address);
	static void cb_spatula8(Address, Address);

	void quit();
	void undo();
	void spatula1();            // action to be done when spatula button is pressed
	void spatula2();
	void spatula3();
	void spatula4();
	void spatula5();
	void spatula6();
	void spatula7();
	void spatula8();
	
	void cycle();

private:
	vector <pancake*> pancake_stack;	
	vector <int> randomstackintegers;
	vector <int> randompancakes;
	vector <int> user_steps;
	
	int get_minimum_steps();
};


#endif // gameplaysceneH_GUARD
