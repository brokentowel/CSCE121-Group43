// game screen size is 800 x 600
/*
pancake project for Walter Daugherity on 5/3/2015
Liam Moran
Ricky Padilla
Kenneth Payne
Faraaz Sunesara
*/

#include "std_lib_facilities_4.h"
#include "Splash_screen.h"
#include "Graph.h"

int main()
try {
	if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ",
	H112);		
	
	//"starts" the game by popping up a splash screen
	Splash_screen win1(Point(100,200),800,600,"Flipjack");
	
	win1.wait_for_button();
	return 0;
}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}


