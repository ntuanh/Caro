#include"includes.h"
int f[40][40];
int size_main;
void set_value() {
	for (int i = 0; i < 40; i++)
		for (int j = 0; j < 40; j++)f[i][j] = 0;
	for (int i = 0; i <= size_main + 1; i++) {
		f[0][i] = 4;
		f[size_main+1][i] = 4;
		f[i][0] = 4;
		f[i][size_main+1] = 4;
	}
}

// y hang ; x cot
bool check(int x, int y) {
	if (f[y][x] == 0)return false;
	int cnt = 1;
	// row 
	for (int i = x + 1; i < x + 5; i++)
		if (f[y][x] == f[y][i])cnt++;else break;
	for (int i = x - 1; i > x - 5; i--)
		if (f[y][x] == f[y][i])cnt++;else break;
	if (cnt > 4)return true;
	cnt = 1;
	//col 
	for (int i = y + 1; i < y + 5; i++)
		if (f[y][x] == f[i][x])cnt++;else break;
	for (int i = y - 1; i > y - 5; i--)
		if (f[y][x] == f[i][x])cnt++;else break;
	if (cnt > 4)return true;
	//  /
	cnt = 1;
	for (int i = 1; i < 5; i++)
		if (f[y][x] == f[y - i][x + i])cnt++;else break;
	for (int i = 1; i < 5; i++)
		if (f[y][x] == f[y + i][x - i])cnt++;else break;
	if (cnt > 4)return true;
	//  "\"
	cnt = 1;
	for (int i = 1; i < 5; i++)
		if (f[y][x] == f[y - i][x - i])cnt++;else break;
	for (int i = 1; i < 5; i++)
		if (f[y][x] == f[y + i][x + i])cnt++;else break;
	if (cnt > 4)return true;
	return false;
}

void print() {
	set_value();
	//f[1][1] = 2;
	for (int i = 0 ; i <= size_main + 1; i++) {
		for (int j = 0; j <= size_main + 1; j++)cout << f[i][j] << " ";
		cout << endl;
	}
}