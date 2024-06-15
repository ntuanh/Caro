#pragma once
#include "includes.h"

class Drawing {
public:
	void setColor(int textColor, int backgroundColor);
	//void TextColor(int color_code); 
	void retangle(int left, int top, int size_col, int size_row);
	void logo(int x, int y);
	void set_player_1(bool boolen, int score_1);
	void set_player_2(bool boolen, int score_2);
	void col(int x, int begin, int end , int ascii );
	void row(int y, int begin, int end , int ascii );
	void winner(int n);
	void clear(int x1, int y1, int x2, int y2);
	void brear(int x, int y);
	void teacher(int x, int y);
	void students(int x, int y);
};

extern Drawing drawing; 
