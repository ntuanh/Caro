#pragma once
#include "includes.h"

//void delay(int delaytime);
void ShowConsoleCursor(bool showFlag);
void setCursor(int x , int y);
//void Kbhit();
void control(int* ptr_x, int* ptr_y, int left, int top, int* ptr_cnt);
