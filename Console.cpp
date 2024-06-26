﻿#include "includes.h"

using namespace std;

//extern Drawing drawing;

void delay(int delaytime) {
	std::this_thread::sleep_for(std::chrono::milliseconds(delaytime));
}

void print_ascii() {
	for (int i = 100; i < 255; i++)cout << i << " " << char(i) << endl;
	// loading 176 
}

pair<int, int> logo_location;

void test() {
	if (_kbhit()) {
		char ch;
		ch = _getch();
		cout << int(ch);
	}
}

void restart() {
	logo_location.first = 38 * 2 - 1;
	logo_location.second = 10;
	drawing.clear(0, 0, 150, 42);
	setCursor(0, 0);
	set_value();
	drawing.logo(logo_location.first,logo_location.second);
}

struct Player {
	int score;
	int x;
	int y;
};


int main_sound() {
	sound_keyboard();
	delay(100);
	sound_kick();
	return 0;
}

int main() {
	logo_location.first = 38 * 2 - 1;
	logo_location.second = 10;

	
	//
	size_main = 36;
	int player_1_score = 0;
	int player_2_score = 0;
	int* ptr_score_1 = &player_1_score;
	int* ptr_score_2 = &player_2_score;
	int top = 4;
	int left = 1;
	int cnt = 1;
	int x = left+ size_main;
	int y = top + size_main/ 2;
	int* ptr_cnt = &cnt;
	int* ptr_x = &x;
	int* ptr_y = &y;
	int score_1 = 0;
	int score_2 = 0;
	int mode = 0;
	int* ptr_mode = &mode;

	//
	ShowConsoleCursor(false);
	bool check_mode = true;
	while (check_mode == true) {
		intro.Table(60 , 10);
		intro.Control_table(ptr_mode);
	}
	while (!_kbhit()) {
		setCursor(30, 30);
		cout << " Press C to continue <3 " << *ptr_mode ;
		char  ch = _getch();
		if (ch == 'c')break;
	}
	
	drawing.clear(0, 0, 150, 50);
	set_value();
	cout << *ptr_mode << endl;
	drawing.set_player_1(cnt, score_1);
	drawing.set_player_2(cnt, score_2);
	drawing.logo(logo_location.first, logo_location.second);

	drawing.setColor(7, 0);
	drawing.retangle(left - 1, top - 1 , size_main , size_main * 2 + 1);
	drawing.setColor(9, 0);
	//logo(38*2 - 1, 10);
	setCursor(38 * 3, 10);
	drawing.setColor(7, 0);
	drawing.col(38 * 3, 0, 42 , 177);
	drawing.row(20, 38 * 3+1, 38 * 4 - 3  , 177);
	drawing.setColor(10,0 );
	bool check_setvalue = false;
	while (true) {
		int q = 0;
		drawing.set_player_1(cnt % 2, score_1  );
		drawing.set_player_2(1 - cnt % 2, score_2);
		int X = (x - left) / 2 + 1;
		int Y = y - top + 1;
		drawing.setColor(13 - f[Y][X], 0);
		control(ptr_x, ptr_y, left, top, ptr_cnt);
		X = (*ptr_x - left) / 2 + 1;
		Y = (*ptr_y - top + 1);
		if (check(X, Y) == 1) {
			//sound();
			//clear(0, 0, 50, 50);
			setCursor(logo_location.first , logo_location.second + 10);
			cout << "  C : contunue or ESC : quit ";
			drawing.winner(f[Y][X]);
			if (check_setvalue == false) {
				//print();
				if (f[Y][X] == 1) score_1++; else score_2++;
				setCursor(100, 1);
				//cout << " value of f[X][Y] : " << X << " " << Y <<" " <<f[X][Y];
				check_setvalue = true;
			}
			while  ( ! _kbhit()) {
				char ch = _getch();
				if (ch == 'c') {
					restart();
					check_setvalue = false;
					x = left + size_main;
					y = top + size_main / 2;
					*ptr_x = x;
					*ptr_y = y;
					cnt = (score_1 + score_2) % 2 + 1;
					*ptr_cnt = cnt;
					control(ptr_x, ptr_y, left, top, ptr_cnt);
					set_value();
					drawing.setColor(7, 0);
					drawing.retangle(left - 1, top - 1, size_main, size_main * 2 + 1);
					setCursor(38 * 3, 10);
					drawing.setColor(7, 0);
					drawing.col(38 * 3, 0, 42 , 177 );
					drawing.row(20, 38 * 3 + 1, 38 * 4 - 3 , 177);
					drawing.setColor(10, 0);
					break;
				}
				else if (int(ch) == 27) {
					sound_keyboard();
					break;
				}
			}
		}

		//cout << "x : " << X << "y : " << Y;
		if (_kbhit()) {
			char ch = _getch();
			if (int(ch) == 27)break;
		}
	}
	return 0 ;
}


int main_1() {
	char spinner[] = { '|', '/', '-', '\\' };
	int spinnerIndex = 0;

	while (true) {
		// Clear the console (this works in Windows; for Unix-based systems use "clear")
		system("CLS");

		// Print the current frame of the spinner
		cout << spinner[spinnerIndex] << endl;

		// Move to the next frame
		spinnerIndex = (spinnerIndex + 1) % 4;

		// Wait for 200 milliseconds
		this_thread::sleep_for(chrono::milliseconds(200));
	}

	return 0;
}

// sudoku 
