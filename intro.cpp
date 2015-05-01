#include "classes.h"
#include "std_lib_facilities_4.h"

#include "Window.h"
#include "Graph.h"
#include "GUI.h"

// can assign some global variables

Color c_pancake(fl_rgb_color(255, 218, 148));
Color c_pancake_outline(fl_rgb_color(191, 163, 111));
Color c_cyan(fl_rgb_color(112, 186, 235));
Color c_dark_blue(fl_rgb_color(6, 83, 138));
	

Intro::Intro(int w, int h, const string& s)						// constructs the child Intro; Intro is a Window
	: Window(w, h, s),											// constructs the parent Window
	background(Point(0, 0), 800, 600),							// initializes background Rectangle
	pancake(Point(400,300), 200, 50),							// initializes pancake Ellipse
	title(Point(240, 200), "FlipFlaps"),						// initializes title Text
	to_quit(Point(360, 460), 80, 40, "QUIT", cb_quit),
	quit_button(Point(360, 460), 80, 40)
{
		attach(background);
		background.set_fill_color(c_cyan);
		background.set_color(c_cyan);
		
		attach(pancake);
		pancake.set_fill_color(c_pancake);
		pancake.set_color(c_pancake_outline);
		
		attach(title);
		title.set_color(Color::white);
		title.set_font_size(80);
		
		attach(to_quit);

		attach(quit_button);
		quit_button.set_fill_color(Color::red);
		quit_button.set_color(Color::dark_red);
		
		Fl::redraw();
}

// ends game by destroying window
void Intro::quit()
{
	hide();
}

// calls quit to destroy window
void Intro::cb_quit(Address, Address pw)	// callback function that calls quit
{
	reference_to<Intro>(pw).quit();
}