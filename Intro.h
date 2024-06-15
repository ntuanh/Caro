#pragma once
#include "includes.h"

class Intro {
private:
	std::pair<int,int > location[4];
public :
	void Screen_1(); // print name teacher and students ;
	void Screen_2(int x, int y); // menu table = { two player , 1 player , how to play , project countdownt led , opencv }
	void Table(int x, int y);
	void Control_table( int* ptr_mode);

	void Instruction(); // instruction for newbie ;
};

extern Intro intro ;