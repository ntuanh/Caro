#include "includes.h"

Intro intro;
 
void Intro::Screen_1() {
	int x = 30;
	int y = 10;
	drawing.teacher(x, y);
	drawing.students(x, y + 3);
}

void Intro::Screen_2(int x, int y  ) {
	//int x = 60;
	//int y = 10;
	int ch = 176;
	drawing.row(y, x, x + 30, ch);
	drawing.row(y + 4, x, x + 30, ch);
	drawing.col(x, y, y + 4, ch);
	drawing.col(x-1, y, y + 4, ch);
	drawing.col(x + 30, y, y + 4, ch);
	drawing.col(x + 30 + 1, y, y + 4, ch);
	setCursor(x + 4, y + 2);
	//cout << name;
}

void Intro::Table(int x, int y) {
	int width = 50;
	int size_menu = 5;
	for (int i = 0; i <= size_menu * 4; i += 4) 
		drawing.row(y + i, x, x + width, 196);
	drawing.col(x - 1, y, y + size_menu * 4  , 179);
	drawing.col(x + width + 1, y, y + size_menu * 4, 179);
	for (int i = 4; i < size_menu * 4; i += 4) {
		drawing.row(y + i, x - 1, x - 1, 195);
		drawing.row(y + i, x + width + 1, x + width + 1, 180);
	}
	// 4 goc 
	setCursor(x - 1, y);
	cout << char(218);
	setCursor(x + width + 1, y);
	cout << char(191);
	setCursor(x - 1, y + size_menu * 4);
	cout << char(192);
	setCursor(x + width + 1, y + size_menu * 4);
	cout << char(217);

	// print 

	for (int i = 0; i < size_menu * 4; i += 4) {
		int d = i / 4;
		setCursor(x + 5, y + i + 2);
		location[d].first = x + 5;
		location[d].second= y + i + 2;
		drawing.setColor(4, 0);
		switch (d) {
		case 0  :
			cout << " Player VS Player =.=";
			break;
		case 1  :
			cout << " Player VS Computer !";
			break;
		case 2  :
			cout << " How to play game ??? ";
			break;
		case 3 :
			cout << " Project countdown led RBG  ^.^";
			break;
		case 4 : 
			cout << " Open CV  '_'   ⁠";
			break;
		}
	}

}

void Intro::Control_table(int *ptr_mode ) {
	int m = *ptr_mode;
	setCursor(location[m].first - 10, location[m].second);
	drawing.setColor(2, 0);
	string s[2] = { "    " , "--->" };
	cout << s[1];
	int keys[] = { 13, 'S', 'W', 'E' ,'A' , 72 };
	bool check = true;
	while ( check ){
		for (int i = 0; i < 6; i++) {
			int v = GetAsyncKeyState(keys[i]);
			if (v & 1) {
				//sound_kick 
				setCursor(0, 0);
				cout << m << endl;
				switch (keys[i])
				{
				case 'W':
					setCursor(location[m].first - 10, location[m].second);
					cout << s[0];
					m--;
					if (m < 0) m = 5 + m;
					setCursor(location[m].first - 10, location[m].second);
					cout << s[1];
					break;
				case 'S':
					setCursor(location[m].first - 10, location[m].second);
					cout << s[0];
					m++;
					if (m > 4) m -= 5;
					setCursor(location[m].first - 10, location[m].second);
					cout << s[1];
					break;
				case 13 :
					check = false;
					break;
				}
			}
		}
	}
	*ptr_mode = m;
}

void Intro::Instruction() {
	drawing.clear(0, 0, 150, 50);
	setCursor(30, 30);
	//drawing.setColor(3, 0);
	cout << " Welcome to our project " << endl;
	cout << " We are Nguyen Tuan Anh 20233258 and Bui Cong Thanh 20233643" << endl;
	cout << " Our mentor is teacher Vu Song Tung ^ . ^ " << endl;
	cout << " Instruction for you : " << endl;
	cout << " Simply , you must have 5 [x] if you are player 1 or 5 [o] if you are player 2 " << endl;
	cout << " Keep alternating moves until one of the players has drawn a row of three symbols or until no one can win" << endl;
	cout << " Press  C to continue ... " << endl; 
	cout << " Good Luck !!! ";
}