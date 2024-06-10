#include "includes.h"

using namespace std;


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
	clear(0, 0, 150, 42);
	setCursor(0, 0);
	set_value();
	logo(logo_location.first,logo_location.second);
}

struct Player {
	int score;
	int x;
	int y;
};

int main_2() {
	//test();
	while (true) {
		test();
	}
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
	int top = 1;
	int left = 1;
	int cnt = 1;
	int x = left+ size_main;
	int y = top + size_main/ 2;
	int* ptr_cnt = &cnt;
	int* ptr_x = &x;
	int* ptr_y = &y;
	int score_1 = 0;
	int score_2 = 0;

	//
	ShowConsoleCursor(false);
	set_value();
	set_player_1(cnt, score_1);
	set_player_2(cnt, score_2);
	logo(logo_location.first, logo_location.second);

	setColor(7, 0);
	retangle(left - 1, top - 1 , size_main , size_main * 2 + 1);
	setColor(9, 0);
	//logo(38*2 - 1, 10);
	setCursor(38 * 3, 10);
	setColor(7, 0);
	col(38 * 3, 0, 42);
	row(20, 38 * 3+1, 38 * 4 - 3);
	setColor(10,0 );
	bool check_setvalue = false;
	while (true) {
		int q = 0;
		set_player_1(cnt % 2, score_1  );
		set_player_2(1 - cnt % 2, score_2);
		int X = (x - left) / 2 + 1;
		int Y = y - top + 1;
		setColor(13 - f[Y][X], 0);
		control(ptr_x, ptr_y, left, top, ptr_cnt);
		X = (*ptr_x - left) / 2 + 1;
		Y = (*ptr_y - top + 1);
		if (check(X, Y) == 1) {
			//sound();
			//clear(0, 0, 50, 50);
			setCursor(logo_location.first , logo_location.second + 10);
			cout << "  C : contunue or Q : quit ";
			winner(f[Y][X]);
			if (check_setvalue == false) {
				//print();
				if (f[Y][X] == 1) score_1++; else score_2++;
				setCursor(100, 1);
				//cout << " value of f[X][Y] : " << X << " " << Y <<" " <<f[X][Y];
				check_setvalue = true;
			}
			if (_kbhit()) {
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
					setColor(7, 0);
					retangle(left - 1, top - 1, size_main, size_main * 2 + 1);
					setCursor(38 * 3, 10);
					setColor(7, 0);
					col(38 * 3, 0, 42);
					row(20, 38 * 3 + 1, 38 * 4 - 3);
					setColor(10, 0);
				}
				else if (int(ch) == 27)break;
			}
		}

		//cout << "x : " << X << "y : " << Y;
		if (_kbhit()) {
			char ch = _getch();
			if (int(ch) == 27)break;
			/*if (ch == 'c') {
				restart();
				x = left;
				y = top;
				*ptr_x = x;
				*ptr_y = y;
				cnt = 1;
				*ptr_cnt = 0;
				control(ptr_x, ptr_y, left, top, ptr_cnt);
				set_value();
				setColor(7, 0);
				retangle(left - 1, top - 1, size_main, size_main * 2 + 1);
				setCursor(38 * 3, 10);
				setColor(7, 0);
				col(38 * 3, 0, 42);
				row(20, 38 * 3 + 1, 38 * 4 - 3);
				setColor(10, 0);

				//setCursor(0, 20);
				//print();
			}*/
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
