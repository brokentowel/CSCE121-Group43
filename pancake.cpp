#include "Graph.h"
#include "std_lib_facilities_4a.h"
//create class pancake
class Pancake {
	int width, height; 
	public: 
	//public constructor function
	void Pancake(int);
	//public swap pancake function
	void swap_pancake();
};
//pancake constructor 
Pancake::Pancake(int w) {
	Graph_lib::Rectangle unburnt(Point(300,40),w,20);
	Graph_lib::Rectangle burnt(Point(300,20),w,20);
};
