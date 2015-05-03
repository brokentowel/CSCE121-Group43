#ifndef Splash_screenH_GUARD
#define Splash_screenH_GUARD

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"

/*
Color c_pancake(fl_rgb_color(255, 218, 148));
Color c_pancake_outline(fl_rgb_color(191, 163, 111));
Color c_cyan(fl_rgb_color(112, 186, 235));
Color c_dark_blue(fl_rgb_color(6, 83, 138));
*/

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Splash_screen : Graph_lib::Window {
    Splash_screen(Point xy, int w, int h, const string& title );

    bool wait_for_button(); // simple event loop

protected:
    //something to set the color of the window/background to c_cyan
    // <code>
    
    Button quit_button;
    bool quit_pushed;
    Button rules_button;     // the "rules" button  HINT(we can cover the buttons with shapes and they still work!)
    bool rules_pushed;     // implementation detail
    Button play_button;     //button to start game
    bool play_pushed;
    Button ldr_button;      //button to open current leaderboard window
    bool ldr_pushed;

    static void cb_rules(Address, Address); // callback for play_button
    static void cb_play(Address, Address); // callback for play_button
    static void cb_ldr(Address, Address); // callback for play_button
    
    void quit();
    void rules();            // action to be done when next_button is pressed
    bool play();
    void ldr();

};

//------------------------------------------------------------------------------

#endif // Splash_screenH_GUARD
